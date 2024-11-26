#include "Polynomial.h"
#include <iostream>
using namespace std;

// 輸出運算子 <<
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = 0; i < poly.terms; i++) {
        out << poly.termArray[i].coef << "x^" << poly.termArray[i].exp;
        if (i < poly.terms - 1) {
            out << " + ";
        }
    }
    return out;
}

// 輸入運算子 >>
istream& operator>>(istream& in, Polynomial& poly) {

    poly.terms = 0;
    while (true) {
        float coef;
        int exp;

        // 讀取係數
        in >> coef;
        if (in.fail()) {
            break;  // 如果無法讀取係數，跳出循環
        }

        // 讀取次方數
        in >> exp;
        if (in.fail()) {
            break;  // 如果無法讀取次方數，跳出循環
        }

        // 儲存多項式項目
        if (poly.terms == poly.capacity) {
            poly.Resize();
        }

        poly.termArray[poly.terms].coef = coef;
        poly.termArray[poly.terms].exp = exp;
        poly.terms++;

        // 嘗試讀取換行符號並處理結束輸入
        char ch = in.get();
        if (ch == '\n') {
            break;  // 若讀到換行符號，結束循環
        }
        else {
            in.putback(ch);  // 如果讀到其他字符，將其放回緩衝區，繼續讀取
        }
    }

    return in;
}

