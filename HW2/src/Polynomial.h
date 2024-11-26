#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Term {
public:
    float coef;  // �Y��
    int exp;     // �����
};

class Polynomial {
public:
    Polynomial();  // �w�]�غc�l
    Polynomial Add(const Polynomial& poly);  // �h�����ۥ[
    Polynomial Mult(const Polynomial& poly);  // �h�����ۭ�
    float Eval(float f);  // �N�J�S�w�ȭp��h���������G

    // �B��l����
    friend ostream& operator<<(ostream& out, const Polynomial& poly);
    friend istream& operator>>(istream& in, Polynomial& poly);

private:
    Term* termArray;  // �x�s���ذ}�C
    int capacity;     // �}�C�e�q
    int terms;        // �h�������D�s�����ƶq

    void Resize();  // �վ�e�q�j�p
};

#endif // POLYNOMIAL_H
