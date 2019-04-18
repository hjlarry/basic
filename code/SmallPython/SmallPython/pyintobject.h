#ifndef PYINTOBJECT_H_H
#define PYINTOBJECT_H_H

#include "pytypeobject.h"

PyObject* PyInt_Create(int value);

//����pyintobject����
typedef struct tagPyIntObject
{
	PyObject_HEAD;
	int value;
}PyIntObject;

static void int_print(PyObject* object)
{
	PyIntObject* intObject = (PyIntObject*)object;
	printf("%d\n", intObject->value);
}

static PyObject* int_add(PyObject* left, PyObject* right)
{
	PyIntObject* leftInt = (PyIntObject*)left;
	PyIntObject* rightInt = (PyIntObject*)right;
	PyIntObject* result = (PyIntObject*)PyInt_Create(0);
	if(result == NULL)
	{
		printf("We have no enough memory!!");
		exit(1);
	}
	else
	{
		result->value = leftInt->value + rightInt->value;
	}
	return (PyObject*)result;
}

static long int_hash(PyObject* object)
{
	return (long)((PyIntObject*)object)->value;
}


PyTypeObject PyInt_Type = 
{
	PyObject_HEAD_INIT(NULL),
	"int",
	//��ʼ������ָ�룬�Ӷ�ʵ�ֶ�̬
	int_print,
	int_add,
	int_hash
};

//��ʼ��pyintobject����
PyObject* PyInt_Create(int value)
{
	PyIntObject* object = new PyIntObject;
	object->refCount = 1;
	object->type = &PyInt_Type;
	object->value = value;

	return (PyObject*)object;
}

#endif