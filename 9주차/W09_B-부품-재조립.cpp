#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int editDistance(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 초기화
    for (int i = 0; i <= m; i++) dp[i][0] = i; // 삭제 비용
    for (int j = 0; j <= n; j++) dp[0][j] = j; // 삽입 비용

    // DP 점화식 적용
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << editDistance(s1, s2) << "\n";
    }

    return 0;
}
