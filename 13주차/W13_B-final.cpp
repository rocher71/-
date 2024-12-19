#include <iostream>
#include <vector>
using namespace std;

int tc;

int main(){
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;

        vector<int> time (n), happiness(n);

        for(int i = 0; i< n; i++) cin >> time[i];
        for(int i = 0; i< n; i++) cin >> happiness[i];

        vector<int> dp(m+1, 0);

        for(int i = 0; i< n; i++){
            for(int j = m; j >= time[i]; j--){
                dp[j] = max(dp[j], dp[j-time[i]] + happiness[i]);
            }
        }

        cout << dp[m] << "\n";
    }
    return 0;
}
