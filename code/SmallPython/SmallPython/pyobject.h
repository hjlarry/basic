#ifndef PYTHON_H_H
#define PYTHON_H_H

#include <stdio.h>
#include <stdlib.h>
//python中只有对象，包括所有的变量也是一个对象
#define PyObject_HEAD \
	int refCount;\
	struct tagPyTypeObject *type

//宏替换 define后面的第一个字符串代替后面所有的字符串
#define PyObject_HEAD_INIT(typePtr)\
	0, typePtr

//对象，包含计数器，数据类型
typedef struct tagPyObject
{
	PyObject_HEAD;
}PyObject;



#endif