#include <iostream>
#include <vector>
using namespace std;

int MOD = 1000000007, tc;

int main(){
    cin >> tc;
    while(tc--){
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i<= m; i++){
            vector<int> prefix(n + 1, 0);
            prefix[0] = dp[i-1][0];

            for(int j = 1 ; j<= n; j++){
                prefix[j] = (prefix[j-1] + dp[i-1][j]) % MOD;
            }

            for(int j = 0; j <= n; j++){
                int low = j - k - 1;
                if(low >= 0) dp[i][j] = (prefix[j] - prefix[low] + MOD) % MOD;
                else dp[i][j] = prefix[j];
            }
        }

        long long total = 0;
        for(int j = 0; j<= n; j++) total = (total + dp[m][j]) % MOD;

        int maxX = min(k, n/m);
        int uniform = maxX + 1;

        long long ans = (total - uniform) % MOD;
        if(ans <0 ) ans += MOD;

        cout << ans << "\n";
    }
    return 0;
}
