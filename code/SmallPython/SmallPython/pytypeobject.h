#ifndef PYTYPEOBJECT_H
#define PYTYPEOBJECT_H

#include "pyobject.h"

//����ָ�����
typedef void (*PrintFun)(PyObject* object);
typedef PyObject* (*AddFun)(PyObject* left, PyObject* right);
typedef long (*HashFun)(PyObject* object);

//���Ͷ�������֣�����
typedef struct tagPyTypeObject
{
	PyObject_HEAD;//�о��ǴӶ���PyObject�м̳�����
	char* name;
	//����ָ��ʵ�ֶ�̬
	PrintFun print;
	AddFun add;
	HashFun hash;
}PyTypeObject;

#endif