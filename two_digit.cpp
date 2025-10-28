#include <iostream>
#include <cmath>
using namespace std;

long long countWithZero(int n) {
    if (n < 2) return 0;
    return 9 * ((long long)pow(2, n) - (long long)pow(2, n - 1) - 1);
}

int main() {
    int n;
    cin >> n;
    cout << countWithZero(n) << endl;
    return 0;
}

