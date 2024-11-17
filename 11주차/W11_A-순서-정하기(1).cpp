#include<iostream>
#include<string>
#include<vector>
using namespace std;

int tc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		int arr[1001];
		vector<int> ans;
		bool isUsed[1001] = { false };
		int n, k, cntUsed = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) arr[i] = i + 1;

		vector<int> numVec(n);
		for (int i = 0; i < n; i++) numVec[i] = i + 1;

		if (k == 0) {
			for (int i = 0; i < n; i++) cout << arr[i] << " ";
			cout << "\n";
			continue;
		}

		int idx = 0;
		//vector<int>::iterator it = numVec.begin();
		int rotate = 0;
		while (cntUsed < n - 1) {
			if (rotate == k) {
				ans.push_back(numVec[idx]);
				numVec.erase(numVec.begin() + idx);
				cntUsed++;
				rotate = (rotate == k) ? 0 : rotate + 1;
				idx = (idx >= n - cntUsed) ? 0 : idx;
				continue;
			}
			
			idx = (idx >= n - cntUsed - 1) ? 0 : idx + 1;

			rotate = (rotate == k) ? 0 : rotate + 1;
		}

		ans.push_back(numVec[0]);
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
}
