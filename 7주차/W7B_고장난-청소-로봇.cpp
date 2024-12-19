#include<iostream>
using namespace std;

// (row, col)부터 왼쪽으로 한줄 한줄 돌면서
// 우측, 아래칸의 최대 쓰레기 개수를 셈

int tc;
int arr[501][501], cnt[501][501];
int row, col, trashCnt = 0;
int main() {
	cin >> tc;
	while (tc--) {
		// tc 당 배열 초기화
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

		// 오른쪽 맨 아래부터 시작
		for (int i = row - 1; i >= 0; i--) {
			for (int j = col - 1; j >= 0; j--) {
				int rightCnt = j + 1 >= col ? 0 : cnt[i][j + 1];
				int bottomCnt = i + 1 >= row ? 0 : cnt[i + 1][j];
				cnt[i][j] = max(rightCnt, bottomCnt);
				if (arr[i][j]) cnt[i][j]++;
			}
		}

		// 전체 쓰레기 개수에서 청소기가 처리할 수 있는 쓰레기 수를 뺀 값 출력
		cout << trashCnt - cnt[0][0] << "\n";
	}
}