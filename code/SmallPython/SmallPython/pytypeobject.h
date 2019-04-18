#ifndef PYTYPEOBJECT_H
#define PYTYPEOBJECT_H

#include "pyobject.h"

//函数指针别名
typedef void (*PrintFun)(PyObject* object);
typedef PyObject* (*AddFun)(PyObject* left, PyObject* right);
typedef long (*HashFun)(PyObject* object);

//类型对象的名字，方法
typedef struct tagPyTypeObject
{
	PyObject_HEAD;//感觉是从对象PyObject中继承下来
	char* name;
	//函数指针实现多态
	PrintFun print;
	AddFun add;
	HashFun hash;
}PyTypeObject;

#endif