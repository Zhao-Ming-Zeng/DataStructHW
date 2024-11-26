#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial() {
    capacity = 10;
    terms = 0;
    termArray = new Term[capacity];
}

void Polynomial::Resize() {
    capacity *= 2;
    Term* newArray = new Term[capacity];
    for (int i = 0; i < terms; i++) {
        newArray[i] = termArray[i];
    }
    delete[] termArray;
    termArray = newArray;
}

// 多項式相加
Polynomial Polynomial::Add(const Polynomial& poly) {
    Polynomial result;
    int i = 0, j = 0;

    while (i < terms && j < poly.terms) {
        if (termArray[i].exp == poly.termArray[j].exp) {
            float sumCoef = termArray[i].coef + poly.termArray[j].coef;
            if (sumCoef != 0) {
                if (result.terms == result.capacity) {
                    result.Resize();
                }
                result.termArray[result.terms].coef = sumCoef;
                result.termArray[result.terms].exp = termArray[i].exp;
                result.terms++;
            }
            i++;
            j++;
        }
        else if (termArray[i].exp > poly.termArray[j].exp) {
            if (result.terms == result.capacity) {
                result.Resize();
            }
            result.termArray[result.terms] = termArray[i];
            result.terms++;
            i++;
        }
        else {
            if (result.terms == result.capacity) {
                result.Resize();
            }
            result.termArray[result.terms] = poly.termArray[j];
            result.terms++;
            j++;
        }
    }

    while (i < terms) {
        if (result.terms == result.capacity) {
            result.Resize();
        }
        result.termArray[result.terms] = termArray[i];
        result.terms++;
        i++;
    }

    while (j < poly.terms) {
        if (result.terms == result.capacity) {
            result.Resize();
        }
        result.termArray[result.terms] = poly.termArray[j];
        result.terms++;
        j++;
    }

    return result;
}

// 多項式相乘
Polynomial Polynomial::Mult(const Polynomial& poly) {
    Polynomial result;

    for (int i = 0; i < terms; i++) {
        for (int j = 0; j < poly.terms; j++) {
            float newCoef = termArray[i].coef * poly.termArray[j].coef;
            int newExp = termArray[i].exp + poly.termArray[j].exp;

            bool added = false;
            for (int k = 0; k < result.terms; k++) {
                if (result.termArray[k].exp == newExp) {
                    result.termArray[k].coef += newCoef;
                    added = true;
                    break;
                }
            }

            if (!added && newCoef != 0) {
                if (result.terms == result.capacity) {
                    result.Resize();
                }
                result.termArray[result.terms].coef = newCoef;
                result.termArray[result.terms].exp = newExp;
                result.terms++;
            }
        }
    }

    return result;
}

// 計算多項式在特定 x 值下的結果
float Polynomial::Eval(float f) {
    float result = 0;
    for (int i = 0; i < terms; i++) {
        result += termArray[i].coef * pow(f, termArray[i].exp);
    }
    return result;
}
