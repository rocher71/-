// 더 빠름
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tc, n, k;
vector<int> v[100001];
int rockNum[100001], depth[100001], rockToSpace[100001];
int desiredRocks[100001];

void bfs() {
    queue<int> q;
    bool visit[100001] = {false};
    q.push(0);
    depth[0] = 0;
    visit[0] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int nxt : v[curr]) {
            if (!visit[nxt]) {
                visit[nxt] = true;
                depth[nxt] = depth[curr] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        // 배열 초기화
        for (int i = 0; i <= n; i++) {
            v[i].clear();
            depth[i] = 0;
        }
        // 광석 번호 읽기 및 매핑
        for (int i = 1; i <= n; i++) {
            cin >> rockNum[i];
            rockToSpace[rockNum[i]] = i;
        }
        // 원하는 광석 번호 읽기
        for (int i = 0; i < k; i++) {
            cin >> desiredRocks[i];
        }
        // 인접 리스트 구성
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        // BFS 수행하여 깊이 계산
        bfs();
        // 원하는 광석의 깊이 출력
        for (int i = 0; i < k; i++) {
            int rock = desiredRocks[i];
            int space = rockToSpace[rock];
            cout << depth[space] << " ";
        }
        cout << "\n";
    }
    return 0;
}
