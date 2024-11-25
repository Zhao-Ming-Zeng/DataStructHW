#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void powerset(char S[], int n) {
    int totalSubsets = 1<<n;

    cout << "{ ";

    for (int i = 0; i < totalSubsets; i++) 
    {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) 
            {
                cout << S[j] << " ";
            }
        }
        cout << "} ";
    }

    cout << "}" << endl;
}

int main() {
    char S[MAX_SIZE] = { 'a', 'b', 'c' };
    int n = 3;

    powerset(S, n);

    return 0;
}
