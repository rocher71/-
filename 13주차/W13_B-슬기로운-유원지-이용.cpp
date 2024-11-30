#include <iostream>
#include <vector>
using namespace std;

int tc;
int N, M; // 어트랙션 개수와 최대 시간

int main() {
    cin >> tc;

    while (tc--) {
        cin >> N >> M;
        vector<int> t(N), h(N); // 이용 시간과 만족도
        for (int i = 0; i < N; i++) cin >> t[i];
        for (int i = 0; i < N; i++) cin >> h[i];

        vector<int> dp(M + 1, 0); // dp 배열 초기화 (0으로 채움)

        for (int i = 0; i < N; i++) { // 어트랙션을 하나씩 고려
            for (int j = M; j >= t[i]; j--) { // 시간을 역순으로 갱신
                dp[j] = max(dp[j], dp[j - t[i]] + h[i]); // 최대 만족도 갱신
            }
        }

        cout << dp[M] << "\n"; // 최대 만족도 출력
    }

    return 0;
}
