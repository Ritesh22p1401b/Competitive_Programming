#include <iostream>
using namespace std;

// Function to calculate 2^n safely
long long powerOfTwo(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) res *= 2;
    return res;
}

// Count n-digit numbers with exactly 2 distinct digits including zero
long long countWithZero(int n) {
    if (n < 2) return 0;

    // Pick 1 non-zero digit (1-9) to pair with zero
    // Total arrangements = 2^n
    // Exclude arrangements starting with zero (2^(n-1))
    // Exclude arrangement where all digits are the non-zero digit (1)
    long long count = 9 * (powerOfTwo(n) - powerOfTwo(n - 1) - 1);

    return count;
}

int main() {
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    long long result = countWithZero(n);
    cout << "Total " << n << "-digit numbers with exactly 2 distinct digits including zero: " 
         << result << endl;

    return 0;
}
