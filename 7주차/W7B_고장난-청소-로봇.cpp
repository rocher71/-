#include<iostream>
using namespace std;

// (row, col)���� �������� ���� ���� ���鼭
// ����, �Ʒ�ĭ�� �ִ� ������ ������ ��

int tc;
int arr[501][501], cnt[501][501];
int row, col, trashCnt = 0;
int main() {
	cin >> tc;
	while (tc--) {
		// tc �� �迭 �ʱ�ȭ
		fill(&arr[0][0], &arr[500][501], 0);
		fill(&cnt[0][0], &cnt[500][501], 0);

		trashCnt = 0;

		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) ++trashCnt;
			}
		}

		// ������ �� �Ʒ����� ����
		for (int i = row - 1; i >= 0; i--) {
			for (int j = col - 1; j >= 0; j--) {
				int rightCnt = j + 1 >= col ? 0 : cnt[i][j + 1];
				int bottomCnt = i + 1 >= row ? 0 : cnt[i + 1][j];
				cnt[i][j] = max(rightCnt, bottomCnt);
				if (arr[i][j]) cnt[i][j]++;
			}
		}

		// ��ü ������ �������� û�ұⰡ ó���� �� �ִ� ������ ���� �� �� ���
		cout << trashCnt - cnt[0][0] << "\n";
	}
}