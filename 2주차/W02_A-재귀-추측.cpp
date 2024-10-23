#include<iostream>
#include<math.h>
using namespace std;

int cnt = 0;
string str;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	unsigned long long ans = pow(2, str.length() + 1) - 1;

	cout << ans  << "\n";
}

/*
1 : 3 (2^2 - 1)
2 : 7 (2^3 - 1)
3 : 15 (2^4 - 1)
4 : 31 (2^5 - 1)
5 : 63 (2^6 - 1)
6 : 127 (2^7 - 1)
7 : 255 (2^8 - 1)
...
10 : 2047 (2^11 - 1)
29 : (2^30 - 1) asdfasdfasdfasdfasdfasdfasdfa
4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048
*/
