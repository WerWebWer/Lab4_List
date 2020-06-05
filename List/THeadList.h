//#pragma once
#ifndef _T_HEADLIST_H_
#define _T_HEADLIST_H_
#include "TLink.h"
#include "TList.h"
#include <iostream>
using namespace std;

template <class T>
class THeadList  {
protected:
	TLink <T> *pHead, *pFirst, *pLast, *pCurr, *pPred, *pStop;
	int pos, len;

public:
	THeadList() {
		pHead = new TLink <T>;
		pStop = pHead;
		pHead->pNext = pStop;
		pFirst = pLast = pCurr = pPred = NULL;
		pos = -1;
		len = 0;
	}
	virtual ~THeadList() {
		if (len) {
			pCurr = pFirst;
			while (pCurr != pStop) {
				pPred = pCurr;
				pCurr = pCurr->pNext;
				delete pPred;
			}
		}
		delete pHead;
	}

	void InsFirst(const T elem) {  //добавить первый элемент в список
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		if (!len) {
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		} else {
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		pHead->pNext = tmp;
		len++;
		pos++;
	}

	void DelFirst() {  //удалить первый элемент из списка
		if (len) {
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			pos--;
			len--;
		}
	}

	void InsCurr(const T elem) {  //добавить элемент в список перед текущим
		if (pCurr == pFirst) InsFirst(elem);
		else {
			TLink <T> *tmp = new TLink <T>;
			tmp->val = elem;
			tmp->pNext = pCurr;
			pPred->pNext = tmp;
			pCurr = tmp;
			len++;
		}
	}

	void DelCurr() {  //удалить текущий элемент из списка
		if (len) {
			if (pCurr == pFirst) {
				DelFirst();
				pCurr = pFirst;
				pos++;
			} else {
				pPred->pNext = pCurr->pNext;
				delete pCurr;
				pCurr = pPred->pNext;
				len--;
			}
		}
	}

	void InsLast(const T elem) {  //добавить последний элемент в список
		if (!len) InsFirst(elem);
		else {
			TLink <T> *tmp = new TLink <T>;
			tmp->val = elem;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			len++;
		}
	}

	void DelLast() {  //удалить последний элемент из списка
		if (len) {
			if (pLast == pFirst) DelFirst();
			else {
				Reset();
				while (pCurr->pNext != pLast)
					GoNext();
				pCurr->pNext = pStop;
				delete pLast;
				pLast = pCurr;
			}
		}
	}

	void Reset() { pCurr = pFirst; }  //указать текущим первый элемент в списке

	void GoNext() {  //перейти к следующему элементу
		pPred = pCurr;
		pCurr = pCurr->pNext;
	}

	bool IsEnd() { return pCurr == pStop; }  //проверка на конец списка
};

#endif