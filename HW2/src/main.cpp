#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    Polynomial p1, p2, result;
    cout << "�Ш̧ǿ�J�h�������Y�ƻP����ơ]������J�H����^�G";
    cin >> p1;
    cout << "�Ĥ@�Ӧh�������G" << p1 << endl;

    cout << "�Ш̧ǿ�J�ĤG�Ӧh�������Y�ƻP����ơ]������J�H����^�G";
    cin >> p2;
    cout << "�ĤG�Ӧh�������G" << p2 << endl;

    result = p1.Add(p2);
    cout << "��h�����ۥ[���G���G" << result << endl;

    result = p1.Mult(p2);
    cout << "��h�����ۭ����G���G" << result << endl;

    float x;
    cout << "�п�J�@��x�ȥN�J�Ĥ@�Ӧh�����i��p��G";
    cin >> x;
    cout << "�p�⵲�G���G" << p1.Eval(x) << endl;

    return 0;
}
