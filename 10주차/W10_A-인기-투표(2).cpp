#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> votes(n);
        for (int i = 0; i < n; ++i) {
            cin >> votes[i];
        }

        int S0 = votes[0]; // 인하의 초기 득표 수

        vector<int> others(votes.begin() + 1, votes.end());
        long long sumOthers = 0;
        for (int v : others) {
            sumOthers += v;
        }

        long long left = S0;
        long long right = S0 + sumOthers + 1;

        while (left < right) {
            long long mid = (left + right) / 2;
            long long totalMoved = mid - S0;
            long long sumNeeded = 0;
            for (int v : others) {
                sumNeeded += max(0LL, v - (mid - 1));
            }
            if (totalMoved >= sumNeeded) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        long long cnt = left - S0;
        cout << cnt << "\n";
    }
    return 0;
}
