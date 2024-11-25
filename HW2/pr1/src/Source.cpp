#include <iostream>
using namespace std;

class Term;

class Polynomial {
public:
    Polynomial(); // �w�]�غc�l
    Polynomial Add(const Polynomial& poly); // �h�����ۥ[
    Polynomial Mult(const Polynomial& poly); // �h�����ۭ�
    float Eval(float f); // �N�J�S�w�ȭp��h���������G
    void Print(); // �L�X�h����
    ~Polynomial(); // �Ѻc�l

private:
    Term* termArray; // �x�s���ذ}�C
    int capacity; // �}�C�e�q
    int terms; // �h�������D�s�����ƶq

    void Resize(); // �վ�e�q�j�p
};

class Term {
    friend class Polynomial; // �� Polynomial ���O�i�H�����s�� Term ���p������
private:
    float coef; // �����Y��
    int exp; // ��������
};

// Polynomial ���غc�l
Polynomial::Polynomial() {
    capacity = 10;
    terms = 0;
    termArray = new Term[capacity];
}

// �վ�}�C�e�q
void Polynomial::Resize() {
    capacity *= 2;
    Term* newArray = new Term[capacity];
    for (int i = 0; i < terms; i++) {
        newArray[i] = termArray[i];
    }
    delete[] termArray;
    termArray = newArray;
}

// �h�����ۥ[
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

// �h�����ۭ�
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
