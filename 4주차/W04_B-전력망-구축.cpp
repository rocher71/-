#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int prim(int N, const vector<int>& plantCost, const vector<vector<int>>& grid) {
    // 우선순위 큐 (비용이 작은 순으로 처리하기 위한 min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(N, false);  // 각 시설이 연결되었는지 여부
    vector<int> minCost(N, INT_MAX); // 각 시설로 가는 최소 비용

    // 각 시설에 발전소를 세우는 비용을 큐에 추가
    for (int i = 0; i < N; ++i) {
        pq.push({plantCost[i], i});  // (비용, 시설 번호)
        minCost[i] = plantCost[i];   // 초기 비용은 발전소 건설 비용
    }

    int totalCost = 0;  // 전체 비용
    int edgesUsed = 0;  // 연결된 시설 수

    while (!pq.empty() && edgesUsed < N) {
        auto [cost, current] = pq.top();  // 가장 작은 비용의 시설 선택
        pq.pop();

        // 이미 방문한 시설은 무시
        if (visited[current]) continue;

        visited[current] = true;  // 현재 시설을 연결
        totalCost += cost;        // 비용 누적
        edgesUsed++;              // 연결된 시설 수 증가

        // 다른 시설들과 연결할 수 있는 송전선 비용을 확인
        for (int next = 0; next < N; ++next) {
            if (!visited[next] && grid[current][next] < minCost[next]) {
                minCost[next] = grid[current][next];  // 최소 비용 갱신
                pq.push({grid[current][next], next}); // 우선순위 큐에 추가
            }
        }
    }

    return totalCost;
}

int main() {
    int T;  // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int N;  // 시설의 수
        cin >> N;

        vector<int> plantCost(N);  // 각 시설 옆에 발전소 건설 비용
        for (int i = 0; i < N; ++i) {
            cin >> plantCost[i];
        }

        vector<vector<int>> grid(N, vector<int>(N));  // 송전선 비용 정보
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }

        // 최소 비용 계산 후 출력
        cout << prim(N, plantCost, grid) << "\n";
    }

    return 0;
}
