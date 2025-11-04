#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int LOG = 32 - __builtin_clz(n); // max power of 2 ≤ n
    vector<vector<int>> st(n, vector<int>(LOG));

    // Base case: interval length = 1
    for (int i = 0; i < n; ++i)
        st[i][0] = arr[i];

    // Build sparse table
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) <= n; ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    // Precompute logs for O(1) query
    vector<int> log2val(n + 1);
    log2val[1] = 0;
    for (int i = 2; i <= n; ++i)
        log2val[i] = log2val[i / 2] + 1;

    // Answer queries
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r; // 0-indexed
        int len = r - l + 1;
        int j = log2val[len];
        cout << min(st[l][j], st[r - (1 << j) + 1][j]) << '\n';
    }

    return 0;
}
