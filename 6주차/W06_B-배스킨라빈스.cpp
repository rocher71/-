#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int tc;

int main() {

    cin >> tc;
    while(tc--){
        int N;
        cin >> N;

        // dp 배열 생성, N까지 구하기 위해서 크기는 N+1
        vector<long long> dp(N + 1, 0);

        // 초기 조건 설정
        dp[0] = 1; // 0을 만드는 방법은 아무것도 선택하지 않는 경우 1가지
        if (N >= 1) dp[1] = 1; // 1을 만드는 방법
        if (N >= 2) dp[2] = 2; // 1+1, 2
        if (N >= 3) dp[3] = 4; // 1+1+1, 1+2, 2+1, 3

        // 점화식을 이용해 dp 채우기
        for (int i = 4; i <= N; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
        }

        // 결과 출력
        cout << dp[N] << "\n";
    }


    return 0;
}
