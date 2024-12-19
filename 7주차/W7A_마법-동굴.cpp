#include<iostream>
#include<math.h>
#include<queue>
#define MAX 1e9
using namespace std;

// bfs!

int tc;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int arr[1001][1001], dist[1001][1001];
bool visit[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		int row, col, startY, startX, endY, endX;
		queue<pair<int, int>> q;
		cin >> col >> row >> startX >> startY >> endX >> endY;
		startY = abs(startY - (row - 1)); // Y��ǥ ����
		endY = abs(endY - (row - 1)); // Y��ǥ ����

		// tc �� �迭 �ʱ�ȭ
		fill(&arr[0][0], &arr[1000][1001], 0);
		fill(&dist[0][0], &dist[1000][1001], MAX);
		fill(&visit[0][0], &visit[1000][1001], false);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				char c;
				cin >> c;
				if (c == 'O') arr[i][j] = 1;
			}
		}

		q.push({ startY, startX });
		visit[startY][startX] = true;
		dist[startY][startX] = 0;
		while (!q.empty()) {
			int currY = q.front().first;
			int currX = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nxtY = currY + dy[i];
				int nxtX = currX + dx[i];

				// ���� ��ǥ�� ���� �Ѿ �� continue
				if (nxtY < 0 || nxtX < 0 || nxtY >= row || nxtX >= col) continue;
				// �̹� �湮�� ��ǥ�̰ų�, �Ÿ��� ���� ��ǥ�� �Ÿ����� Ŭ �� continue
				if (visit[nxtY][nxtX] || arr[nxtY][nxtX] == 0 || dist[nxtY][nxtX] < dist[currY][currX]) continue;
				q.push({ nxtY, nxtX });
				visit[nxtY][nxtX] = true;
				dist[nxtY][nxtX] = dist[currY][currX] + 1;
			}

			if (currY == endY && currX == endX) break;
		}

		// ���� �� �� ������ -1 ���
		if (dist[endY][endX] == MAX) {
			cout << -1 << "\n";
			continue;
		}
		cout << dist[endY][endX] << "\n";

	}
	return 0;
}