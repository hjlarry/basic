#ifndef PYTHON_H_H
#define PYTHON_H_H

#include <stdio.h>
#include <stdlib.h>
//python��ֻ�ж��󣬰������еı���Ҳ��һ������
#define PyObject_HEAD \
	int refCount;\
	struct tagPyTypeObject *type

//���滻 define����ĵ�һ���ַ�������������е��ַ���
#define PyObject_HEAD_INIT(typePtr)\
	0, typePtr

//���󣬰�������������������
typedef struct tagPyObject
{
	PyObject_HEAD;
}PyObject;



#endif