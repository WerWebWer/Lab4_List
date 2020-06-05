//#pragma once
#ifndef _T_POLINOM_H_
#define _T_POLINOM_H_
#include "../List/TLink.h"
#include "../List/THeadList.h"
#include <iostream>
using namespace std;

struct TMonom  {
	double coeff;
	int power;
};

//операторы сравнения мономов
inline bool operator<(const TMonom& m1, const TMonom& m2) { return m1.power < m2.power; };
inline bool operator>(const TMonom& m1, const TMonom& m2) { return m1.power > m2.power; };

class TPolinom : public THeadList <TMonom> {
public:

	TPolinom::TPolinom() {
		TMonom m;
		m.coeff = 0;
		m.power = -1;
		pHead->val = m;
	}

	TPolinom::TPolinom(int mas[][2], int size) {
		if (size <= 0) throw - 1;
		pHead->val.coeff = 0;
		pHead->val.power = -1;
		for (int i = 0; i < size; i++)
			for (int j = i; j < size; j++) {
				if (mas[i][1] < mas[j][1]) {
					int tmp = mas[i][1];
					mas[i][1] = mas[j][1];
					mas[j][1] = tmp;

					int tmp1 = mas[i][0];
					mas[i][0] = mas[j][0];
					mas[j][0] = tmp1;
				}
			}
		for (int i = 0; i < size; i++) {
			TMonom m;
			m.coeff = mas[i][0];
			m.power = mas[i][1];
			if (m.power < 0)
				throw - 1;
			InsLast(m);
		}
	}

	TPolinom::TPolinom(TPolinom& Q) {
		pHead->val.coeff = 0;
		pHead->val.power = -1;
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext()) InsLast(Q.pCurr->val);
	}

	void TPolinom::InsMonom(TMonom m) {
		Reset();
		while (pCurr->val.power > m.power) GoNext();
		if (pCurr->val.power < m.power) InsCurr(m);
		else {
			pCurr->val.coeff += m.coeff;
			if (pCurr->val.coeff == 0) DelCurr();
		}
	}

	TPolinom& TPolinom::operator+=(TPolinom& Q) {
		Reset();
		Q.Reset();
		while (Q.pCurr->val.power != -1) {
			//InsMonom(Q.pCurr->val);
			//Q.GoNext();
			if (pCurr->val.power > Q.pCurr->val.power) GoNext();
			else if (pCurr->val.power < Q.pCurr->val.power) {
				InsCurr(Q.pCurr->val);
				Q.GoNext();
			} else {
				pCurr->val.coeff += Q.pCurr->val.coeff;
				if (pCurr->val.coeff == 0) DelCurr();
				else GoNext();
				Q.GoNext();
			}
		}
		return *this;
	}

	TPolinom& TPolinom::operator*=(const double p) {
		if (p == 0) {
			Reset();
			while (pFirst != pStop)
				DelFirst();
		} else for (Reset(); !IsEnd(); GoNext()) pCurr->val.coeff *= p;
		return *this;
	}

	TPolinom& TPolinom::operator-=(TPolinom& Q) {
		Q *= -1;
		return (*this) += Q;
	}

	bool TPolinom::operator==(TPolinom& Q) {
		(*this) -= Q;
		if (!len)
			return true;
		return false;
	}

	void TPolinom::Print() {
		if (!len) cout << "0 ";
		else for (Reset(); !IsEnd(); GoNext()) {
				if ((pCurr->val.coeff > 0) && (pCurr != pFirst))
					cout << "+ ";
				if (pCurr->val.coeff < 0)
					cout << "- ";
				if ((abs(pCurr->val.coeff) != 1) || (!pCurr->val.power))
					cout << abs(pCurr->val.coeff) << " ";
				if (pCurr->val.power / 100 > 0)
					cout << "x^" << pCurr->val.power / 100 << " ";
				if (pCurr->val.power % 100 / 10 > 0)
					cout << "y^" << pCurr->val.power % 100 / 10 << " ";
				if (pCurr->val.power % 10 > 0)
					cout << "z^" << pCurr->val.power % 10 << " ";

			}
		cout << endl;
	}
	TMonom& TPolinom::GetMonom() {
		return pCurr->val;
	}
};

#endif
