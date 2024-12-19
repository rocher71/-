// 지피티 코드
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int N, K, M; // 남은 학기 수, 미수강 과목 수, 선수 조건 수
        cin >> N >> K >> M;

        vector<vector<int>> adj(K+1);  // 그래프 인접 리스트
        vector<int> indegree(K+1, 0); // 진입차수 배열
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indegree[b]++;
        }

        // 위상 정렬을 위한 큐
        queue<int> q;
        // 각 과목을 이수하는 데 필요한 최소 학기 수
        vector<int> semester_needed(K+1, 0);

        // 진입차수가 0인 노드를 큐에 삽입 (선수과목 없이 바로 들을 수 있는 과목)
        for (int i = 1; i <= K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                semester_needed[i] = 1; // 바로 들을 수 있으므로 1학기 필요
            }
        }

        // 위상 정렬 수행
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto next : adj[curr]) {
                // curr을 들었으니 next의 선수 과목 중 하나를 만족
                // 이때 next를 이수하는 데 필요한 학기 갱신
                semester_needed[next] = max(semester_needed[next], semester_needed[curr] + 1);

                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 원하는 과목에 대해 남은 학기 N으로 수강 가능한지 체크
        int Q;
        cin >> Q;
        while (Q--) {
            int q_subj;
            cin >> q_subj;
            // semester_needed[q_subj]가 0이면 해당 과목은 위상 정렬 시 진입차수가 감소하지 않아
            // 도달 불가능한 과목일 가능성이 있음(즉, 선수과목 조건 충족 불가)
            if (semester_needed[q_subj] != 0 && semester_needed[q_subj] <= N) {
                cout << "True\n";
            } else {
                cout << "False\n";
            }
        }
    }

    return 0;
}
