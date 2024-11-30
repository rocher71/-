#include<iostream>
#include<vector>
using namespace std;

int tc, n, m;
int numbers[1000001];

bool binarySearch(int find) {
	int start = 0, end = n * m - 1, mid = (start + end) / 2;

	while (start <= end) {
		if (numbers[mid] == find) return true;
		if (numbers[mid] < find) {
			start = mid + 1;
			mid = (start + end) / 2;
			continue;
		}

		end = mid - 1;
		mid = (start + end) / 2;
	}
	return false;
}


int main() {
	cin >> tc;
	while (tc -- ) {
		int q;
		cin >> n >> m;
		for (int i = 0; i < n * m; i++) {
			cin >> numbers[i];
		}
		cin >> q;
		for (int i = 0; i < q; i++) {
			int num;
			cin >> num;
			if (binarySearch(num)) cout << "1 ";
			else cout << "0 ";
		}

		cout << "\n";
		fill_n(numbers, 1000001, false);

	}
}
