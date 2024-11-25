#include <iostream>
using namespace std;

class Term;

class Polynomial {
public:
    Polynomial(); // 預設建構子
    Polynomial Add(const Polynomial& poly); // 多項式相加
    Polynomial Mult(const Polynomial& poly); // 多項式相乘
    float Eval(float f); // 代入特定值計算多項式的結果
    void Print(); // 印出多項式
    ~Polynomial(); // 解構子

private:
    Term* termArray; // 儲存項目陣列
    int capacity; // 陣列容量
    int terms; // 多項式中非零項的數量

    void Resize(); // 調整容量大小
};

class Term {
    friend class Polynomial; // 讓 Polynomial 類別可以直接存取 Term 的私有成員
private:
    float coef; // 項的係數
    int exp; // 項的指數
};

// Polynomial 的建構子
Polynomial::Polynomial() {
    capacity = 10;
    terms = 0;
    termArray = new Term[capacity];
}

// 調整陣列容量
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
            result.termArray[result.terms].coef = termArray[i].coef;
            result.termArray[result.terms].exp = termArray[i].exp;
            result.terms++;
        }
        else {
            if (result.terms == result.capacity) {
                result.Resize();
            }
            result.termArray[result.terms].coef = termArray[i].coef;
            result.termArray[result.terms].exp = termArray[i].exp;
            result.terms++;
        }
    }

    while (i < terms) {
        if (result.terms == result.capacity) {
            result.Resize();
        }
        result.termArray[result.terms++] = termArray[i++];
    }

    while (j < poly.terms) {
        if (result.terms == result.capacity) {
            result.Resize();
        }
        result.termArray[result.terms++] = poly.termArray[j++];
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

float Polynomial::Eval(float f) {
    float result = 0;
    for (int i = 0; i < terms; i++) {
        result += termArray[i].coef * pow(f, termArray[i].exp);
    }
    return result;
}
void Polynomial::Print() {
    for (int i = 0; i < terms; i++) {
        cout << termArray[i].coef << "x^" << termArray[i].exp;
        if (i < terms - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}
Polynomial::~Polynomial() {
    delete[] termArray;
}

int main() {
    Polynomial p1, p2;
    return 0;
}
