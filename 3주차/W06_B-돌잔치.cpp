#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9

int tc, n, m, k;
int dist[1001], visitors[1001];

int dijkstra(int from, int to, vector<pair<int, int>> graph[1001]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, from});

    fill(dist, dist+1001, INF);
    dist[from] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;

        if(curr == to) break;
        pq.pop();

        for(int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;
            if(dist[next] <= cost + nextCost) continue;

            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
        }
    }
    return dist[to];
}

int main(){
    cin >> tc;
    while(tc--){
        vector<pair<int, int>> graph[1001]; //graph[a] = {b, x} : a->b 루트의 비용 x

        cin >> n >> m;
        for(int i = 0; i<m; i++) {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            graph[a].push_back({b, x});
            graph[b].push_back({a, y});
        }
        cin >> k;
        for(int i  = 0;i <k ; i++) cin >> visitors[i];

        int ans = 0;
        for(int i = 0; i< k; i++){
            int currCost = dijkstra(visitors[i], 1, graph) + dijkstra(1, visitors[i], graph);
            ans = max(ans, currCost);
        }

        cout << ans <<"\n";
    }
}
