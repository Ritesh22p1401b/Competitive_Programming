#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, string> longestCommonSubsequence(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return {dp[m][n], lcs};
}

int main() {
    string s1 = "stone";
    string s2 = "longest";

    auto result = longestCommonSubsequence(s1, s2);

    cout << "Length of Longest Common Subsequence is: " << result.first << endl;
    cout << "Longest Common Subsequence is: " << result.second << endl;

    return 0;
}
