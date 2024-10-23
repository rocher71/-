#include <iostream>
using namespace std;

int T;
string answer = "";

// 주어진 string이 한번에 압축될 수 있는지 확인해주는 함수
bool check(string str) {
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != str[i - 1])	return false;
    }
    return true;
}

// 문자열을 압축해주는 함수
void compress(string str) {
    // cout << "compress string : " << str << "\n";
    // 한번에 압축 가능한 문자열일 시 정답 string에 압축문자를 추가하고 return
    if (check(str)) {
        answer += str[0];
        return;
    }

    // 바로 압축할 수 없는 문자열일 시 반을 나눠서 재귀
    answer += 'B';
    compress(str.substr(0, str.length() / 2));
    compress(str.substr(str.length() / 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        string input;
        cin >> input;

        compress(input);
        cout << answer << "\n";
        answer = "";
    }
}

/* sample input
3
1111000000000000
0100110110100100
0101010101010101

output
BB100
BBBB010B1B01BBB10B10BB010
BBBB01B01BB01B01BBB01B01BB01B01
*/
