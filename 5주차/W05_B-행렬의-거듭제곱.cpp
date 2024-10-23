#include<iostream>
#include<vector>
using namespace std;

const unsigned long long MOD = 1000000007;

// 행렬 거듭제곱을 계산하는 함수
vector<unsigned long long> solve(unsigned long long one,
                                 unsigned long long two,
                                 unsigned long long three,
                                 unsigned long long four,
                                 unsigned long long power) {
    // power가 1인 경우, 주어진 행렬을 그대로 반환
    if (power == 1) {
        return {one % MOD, two % MOD, three % MOD, four % MOD};
    }
    // power가 짝수인 경우, 행렬의 절반 거듭제곱을 먼저 계산
    if (power % 2 == 0) {
        vector<unsigned long long> half = solve(one, two, three, four, power / 2);
        unsigned long long a = (half[0] * half[0] + half[1] * half[2]) % MOD;
        unsigned long long b = (half[0] * half[1] + half[1] * half[3]) % MOD;
        unsigned long long c = (half[2] * half[0] + half[3] * half[2]) % MOD;
        unsigned long long d = (half[2] * half[1] + half[3] * half[3]) % MOD;
        return {a, b, c, d};  // 반으로 나눈 결과를 제곱하여 반환
    } else {
        // power가 홀수인 경우, 행렬의 (power-1) 거듭제곱을 계산 후, 한 번 더 행렬을 곱함
        vector<unsigned long long> minusOne = solve(one, two, three, four, power - 1);
        unsigned long long a = (one * minusOne[0] + two * minusOne[2]) % MOD;
        unsigned long long b = (one * minusOne[1] + two * minusOne[3]) % MOD;
        unsigned long long c = (three * minusOne[0] + four * minusOne[2]) % MOD;
        unsigned long long d = (three * minusOne[1] + four * minusOne[3]) % MOD;
        return {a, b, c, d};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;  // 테스트 케이스 수 입력
    while (tc--) {
        unsigned long long one, two, three, four, power;
        cin >> one >> two >> three >> four >> power;  // 행렬 원소와 거듭제곱 횟수 입력
        vector<unsigned long long> answer = solve(one, two, three, four, power);
        cout << answer[0] << " " << answer[1] << "\n";
        cout << answer[2] << " " << answer[3] << "\n";
    }
    return 0;
}
