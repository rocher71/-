#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

int tc, n, k;
vector<int> v[100001], findRock;
int rockNum[100001], answers[100001];
bool visit[100001];
map<int, int> findMap;

void bfs() {
	fill_n(visit, 100001, false);
	queue<pair<int, int>> q;
	q.push({0, 0});
	visit[0] = true;
	int ansCnt = 0;

	while (!q.empty()) {
		int curr = q.front().first;
		int currHeight = q.front().second;
		q.pop();
	
		//if (rockNum[curr] == finding) {
		//	cout << currHeight << " ";
		//	return;
		//}

		if (findMap.find(rockNum[curr]) != findMap.end()) {
			answers[findMap[rockNum[curr]]] = currHeight; 
			ansCnt++;
			if (ansCnt == k) return;
		}

		for (long unsigned int i = 0; i < v[curr].size(); i++) {
			int nxt = v[curr][i];
			if (visit[nxt]) continue;
			q.push({ nxt, currHeight + 1 });
			visit[nxt] = true;
		}
	}
}

int main(){
	cin >> tc;
	while (tc--) {
		cin >> n >> k; // 광산 내부 공간 수, 찾는 광석 수

		// 공간번호 i에 있는 광석 번호
		for (int i = 1; i <= n; i++) cin >> rockNum[i]; 

		// 찾으려는 광석 번호
		for (int i = 0; i < k; i++) {
			int tmp;
			cin >> tmp;
			findRock.push_back(tmp);
			findMap.insert({ tmp, i });
		}

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		bfs();
		for (int i = 0; i < k; i++) cout << answers[i] << " ";

		for (int i = 0; i <= n; i++) v[i].clear();
		findRock.clear();
		fill_n(rockNum, 100001, 0);
		fill_n(answers, 100001, 0);
		findMap.clear();

		cout << "\n";
	}
}