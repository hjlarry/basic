#ifndef EXCUTE_H
#define EXCUTE_H

#include "pytypeobject.h"
#include "pydictobject.h"
#include "pyintobject.h"
#include "pystrobject.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;

void ExcutePrint(string symbol);
void ExcuteAdd(string& target, string& source);
PyObject* GetObjectBySymbol(string& symbol);
static PyObject* m_LocalEnvironment = PyDict_Create();

//ָ�����
void ExcuteCommand(string& command)
{
	string::size_type pos = 0;
	if((pos = command.find("print")) != string::npos)
	{
		//Ԥ����
		while(command[pos+5] == ' ')
		{
			command.erase(pos+5,1);
			pos = command.find("print");
		}

		ExcutePrint(command.substr(pos+5));
	}
	else if((pos = command.find("=")) != string::npos)
	{
		//Ԥ����
		while(command[pos-1] == ' ')
		{
			command.erase(pos-1,1);
			pos = command.find("=");
		}
		while(command[pos+1] == ' ')
		{
			command.erase(pos+1,1);
			pos = command.find("=");
		}
		//a = b + c; a = b;
		string target = command.substr(0,pos);//target = "a";
		string source = command.substr(pos+1);//source = "b + c" or "b"
		ExcuteAdd(target, source);
	}
	else
	{
		cout << "[Error] : order:'" << command << "' is illegal!!" << endl;
	}
}

bool IsSourceAllDigit(string& source)
{
	//����source��û�������ַ�����0123456789���е��ַ�
	string::size_type pos = source.find_first_not_of("0123456789");
	return pos == string::npos;
}

void ExcuteAdd(string& target, string& source)
{
	string::size_type pos;
	PyObject* strValue = NULL;
	PyObject* resultValue = NULL;

	//sourceȫΪ����
	if(IsSourceAllDigit(source))
	{
		PyObject* intValue = PyInt_Create(atoi(source.c_str()));
		PyObject* key = PyStr_Create(target.c_str());
		PyDict_SetItem(m_LocalEnvironment, key, intValue);
	}
	//sourceΪ�ַ���
	else if(source.find("\"") != string::npos)
	{
		strValue = PyStr_Create(source.substr(1,source.size()-2).c_str());
		PyObject* key = PyStr_Create(target.c_str());
		PyDict_SetItem(m_LocalEnvironment, key, strValue);
	}
	//���ʽ
	else if((pos = source.find("+")) != string::npos)
	{
		//Ԥ����
		while(source[pos-1] == ' ')
		{
			source.erase(pos-1,1);
			pos = source.find("+");
		}
		while(source[pos+1] == ' ')
		{
			source.erase(pos+1,1);
			pos = source.find("+");
		}

		PyObject* leftObject = GetObjectBySymbol(source.substr(0,pos));
		PyObject* rightObject = GetObjectBySymbol(source.substr(pos+1));
		if(leftObject != NULL && rightObject != NULL  
			&& leftObject->type == rightObject->type)
		{
			resultValue = (leftObject->type)->add(leftObject, rightObject);
			PyObject* key = PyStr_Create(target.c_str());
			PyDict_SetItem(m_LocalEnvironment, key, resultValue);
		}
		(m_LocalEnvironment->type)->print(m_LocalEnvironment);
	}
}

//���ݱ�������ȡ�����ֵ
PyObject* GetObjectBySymbol(string& symbol)
{
	PyObject* key = PyStr_Create(symbol.c_str());
	PyObject* value = PyDict_GetItem(m_LocalEnvironment, key);
	if(value == NULL)
	{
		cout << "[Error] : " << symbol << " is not define!!" << endl;
		return NULL;
	}
	return value;
}

//��ӡ����������̨
void ExcutePrint(string symbol)
{
	PyObject* object = GetObjectBySymbol(symbol);
	if(object != NULL)
	{
		PyTypeObject* type = object->type;
		type->print(object);
	}
}


const char* info = "*************** Python Research *****************\n";
const char* prompt = ">>>";
//ִ������
void Excute()
{
	cout << info;
	cout << prompt;
	std::string m_Command;
	while(getline(cin, m_Command))
	{
		if(m_Command.size() == 0)
		{
			cout << prompt;
			continue;
		}
		else if(m_Command.find("exit") != -1)
		{
			return;
		}
		else
		{
			ExcuteCommand(m_Command);
		}
		cout << prompt;
	}
}

#endif