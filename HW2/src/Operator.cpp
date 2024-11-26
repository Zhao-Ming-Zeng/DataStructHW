#include "Polynomial.h"
#include <iostream>
using namespace std;

// ��X�B��l <<
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = 0; i < poly.terms; i++) {
        out << poly.termArray[i].coef << "x^" << poly.termArray[i].exp;
        if (i < poly.terms - 1) {
            out << " + ";
        }
    }
    return out;
}

// ��J�B��l >>
istream& operator>>(istream& in, Polynomial& poly) {

    poly.terms = 0;
    while (true) {
        float coef;
        int exp;

        // Ū���Y��
        in >> coef;
        if (in.fail()) {
            break;  // �p�G�L�kŪ���Y�ơA���X�`��
        }

        // Ū�������
        in >> exp;
        if (in.fail()) {
            break;  // �p�G�L�kŪ������ơA���X�`��
        }

        // �x�s�h��������
        if (poly.terms == poly.capacity) {
            poly.Resize();
        }

        poly.termArray[poly.terms].coef = coef;
        poly.termArray[poly.terms].exp = exp;
        poly.terms++;

        // ����Ū������Ÿ��óB�z������J
        char ch = in.get();
        if (ch == '\n') {
            break;  // �YŪ�촫��Ÿ��A�����`��
        }
        else {
            in.putback(ch);  // �p�GŪ���L�r�šA�N���^�w�İϡA�~��Ū��
        }
    }

    return in;
}

