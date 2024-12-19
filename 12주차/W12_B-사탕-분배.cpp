#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int N, M, K;
        cin >> N >> M >> K;

        // dp[i][j]: i명의 친구에게 정확히 j개의 사탕을 나누는 경우의 수
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        dp[0][0] = 1; // 아무에게도 사탕을 주지 않고 사탕 사용 0개인 경우 1가지

        for (int i = 1; i <= M; i++) {
            // prefix sum 계산을 위해
            vector<int> prefix(N+1, 0);
            prefix[0] = dp[i-1][0];
            for (int j = 1; j <= N; j++){
                prefix[j] = (prefix[j-1] + dp[i-1][j]) % MOD;
            }

            for (int j = 0; j <= N; j++){
                // dp[i][j] = sum of dp[i-1][j-x] for x=0 to K (and j-x >= 0)
                int low = j - K - 1;
                if (low >= 0)
                    dp[i][j] = (prefix[j] - prefix[low] + MOD) % MOD;
                else
                    dp[i][j] = prefix[j]; // K보다 작거나 같은 범위 모두 포함
            }
        }

        // 총 합이 N 이하인 경우의 수
        // dp[M][j] = 정확히 j개 사용
        // 따라서 total = sum(dp[M][j]) for j=0 to N
        long long total = 0;
        for (int j = 0; j <= N; j++){
            total = (total + dp[M][j]) % MOD;
        }

        // uniform (모두 같은) 경우 계산
        // x = 0 ~ min(K, floor(N/M))
        int maxX = min(K, N/M);
        int uniform = maxX + 1; // x=0부터 maxX까지

        // 최종 답
        long long ans = (total - uniform) % MOD;
        if (ans < 0) ans += MOD;

        cout << ans << "\n";
    }

    return 0;
}
