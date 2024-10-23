
#include<iostream>
#include<vector>
using namespace std;

int tc;

int main() {
	//cout << '3' - '0'; return 0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		int x, y;
		string str;
		vector<int> continuosCnt;
		int specialCnt[10] = { 0, 0, 0,0,0,0,0,0,0,0 };
		cin >> x >> y >> str;

		bool isPrevSpecial = str[0] == '3' || str[0] == '6' || str[0] == '9' ? true : false;
		if (isPrevSpecial) specialCnt[str[0] - '0']++;
		

		int cnt = isPrevSpecial ? 0 : 1;
		for (int i = 1; i < str.length(); i++) {
			bool isCurrSpecial = str[i] == '3' || str[i] == '6' || str[i] == '9' ? true : false;
			if (isCurrSpecial) specialCnt[str[i] - '0']++;

			if (i == str.length() - 1 && !isCurrSpecial) {
				continuosCnt.push_back(++cnt);
				break;
			}

			if (isPrevSpecial && isCurrSpecial) continue;

			// ���� ���ڴ� not 369 ���� ���ڴ� 369
			if (!isPrevSpecial && isCurrSpecial) {
				continuosCnt.push_back(cnt);
				cnt = 0;
				isPrevSpecial = true;
				continue;
			}

			// ���� ���ڴ� 369 ���� ���ڴ� not 369
			if (isPrevSpecial && !isCurrSpecial) {
				cnt = 1;
				isPrevSpecial = false;
				continue;
			}

			// ����, ���� ���� ��� not 369
			cnt++;
		}

		int ans = 0;
		for (int num : continuosCnt) ans += min(x + y, num * x);

		cout << ans << " " << min(specialCnt[3], min(specialCnt[6], specialCnt[9])) << "\n";
	}
}
