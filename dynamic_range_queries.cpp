#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void build(const vector<long long> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node + 1, start, mid, idx, val);
            else
                update(2 * node + 2, mid + 1, end, idx, val);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || l > end)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r);
    }

    void build(const vector<long long> &arr) { build(arr, 0, 0, n - 1); }
    void update(int idx, long long val) { update(0, 0, n - 1, idx, val); }
    long long query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    SegmentTree st(n);
    st.build(arr);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            long long x;
            cin >> k >> x;
            --k; // 0-indexed
            st.update(k, x);
        } else {
            int a, b;
            cin >> a >> b;
            --a; --b; // 0-indexed
            cout << st.query(a, b) << "\n";
        }
    }
}
