//#pragma once
#ifndef _T_LINK_H_
#define _T_LINK_H_

template <class T>
class TLink
{
public:
	T val;  //значение элемента
	TLink *pNext;  //указатель на следующий элемент
};

#endif