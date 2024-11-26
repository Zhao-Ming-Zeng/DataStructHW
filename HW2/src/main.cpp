#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    Polynomial p1, p2, result;
    cout << "請依序輸入多項式的係數與次方數（結束輸入以換行）：";
    cin >> p1;
    cout << "第一個多項式為：" << p1 << endl;

    cout << "請依序輸入第二個多項式的係數與次方數（結束輸入以換行）：";
    cin >> p2;
    cout << "第二個多項式為：" << p2 << endl;

    result = p1.Add(p2);
    cout << "兩多項式相加結果為：" << result << endl;

    result = p1.Mult(p2);
    cout << "兩多項式相乘結果為：" << result << endl;

    float x;
    cout << "請輸入一個x值代入第一個多項式進行計算：";
    cin >> x;
    cout << "計算結果為：" << p1.Eval(x) << endl;

    return 0;
}
