#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Term {
public:
    float coef;  // 係數
    int exp;     // 次方數
};

class Polynomial {
public:
    Polynomial();  // 預設建構子
    Polynomial Add(const Polynomial& poly);  // 多項式相加
    Polynomial Mult(const Polynomial& poly);  // 多項式相乘
    float Eval(float f);  // 代入特定值計算多項式的結果

    // 運算子重載
    friend ostream& operator<<(ostream& out, const Polynomial& poly);
    friend istream& operator>>(istream& in, Polynomial& poly);

private:
    Term* termArray;  // 儲存項目陣列
    int capacity;     // 陣列容量
    int terms;        // 多項式中非零項的數量

    void Resize();  // 調整容量大小
};

#endif // POLYNOMIAL_H
