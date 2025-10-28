#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];
int dp[MAXN][2];

// dp[u][0] = minimum cameras in subtree of u, u doesn't have a camera
// dp[u][1] = minimum cameras in subtree of u, u has a camera

void dfs(int u, int parent) {
    visited[u] = true;
    dp[u][0] = 0;  // u doesn't have camera
    dp[u][1] = 1;  // u has camera

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);

        dp[u][0] += dp[v][1]; // If u doesn't have a camera, all children must have one
        dp[u][1] += min(dp[v][0], dp[v][1]); // If u has a camera, child may or may not
    }
}

int main() {
    int n;
    cin >> n; // number of vertices
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; // edge between u and v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1); // assuming node 1 as root

    cout << "Minimum cameras needed: " << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
