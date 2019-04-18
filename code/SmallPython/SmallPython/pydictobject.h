#ifndef PYDICTOBJECT_H
#define PYDICTOBJECT_H

#include "pytypeobject.h"
#include <map>

using std::map;

//声明PyDictObject对象
typedef struct tagPyDictObject
{
	PyObject_HEAD;
	map<long, PyObject*> dict;
}PyDictObject;

//根据键在键值表中获取值，target是键值表，key是键
PyObject* PyDict_GetItem(PyObject* target, PyObject* key)
{
	long keyHashValue = (key->type)->hash(key);
	map<long, PyObject*>& dict = ((PyDictObject*)target)->dict;
	map<long, PyObject*>::iterator it = dict.find(keyHashValue);
	map<long, PyObject*>::iterator end = dict.end();
	if(it == end)
	{
		return NULL;
	}
	return it->second;
}

int PyDict_SetItem(PyObject* target, PyObject* key, PyObject* value)
{
	long keyHashValue = (key->type)->hash(key);
	PyDictObject* dictObject = (PyDictObject*)target;
	(dictObject->dict)[keyHashValue] = value;
	return 0;
}

//function for PyDict_Type
static void dict_print(PyObject* object)
{
	PyDictObject* dictObject = (PyDictObject*)object;
	printf("{");
	map<long, PyObject*>::iterator it = (dictObject->dict).begin();
	map<long, PyObject*>::iterator end = (dictObject->dict).end();
	for(; it != end; ++it)
	{
		//print key
		printf("%ld : ", it->first);
		//print value
		PyObject* value = it->second;
		(value->type)->print(value);
		printf(",");
	}
	printf("}\n");
}


PyTypeObject PyDict_Type = 
{
	PyObject_HEAD_INIT(NULL),
	//初始化函数指针，从而实现多态
	"dict",
	dict_print,
	0,
	0
};

//初始化PyDictObject对象
PyObject* PyDict_Create()
{
	PyDictObject* object = new PyDictObject;
	object->refCount = 1;
	object->type = &PyDict_Type;

	return (PyObject*)object;
}

#endif