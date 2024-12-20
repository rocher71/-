#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int tc, n, k;
int rockToSpace[MAX], rockNum[MAX], depth[MAX];
bool visit[MAX];
vector<int> desiredRocks;
vector<int> v[MAX];

void bfs(){
    queue<int> q;
    q.push(0);
    visit[0] = true;
    depth[0] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : v[curr]){
            if(visit[next]) continue;
            visit[next] = true;
            depth[next] = depth[curr] + 1;
            q.push(next);
        }
    }

}

int main(){
    cin >> tc;
    while(tc--){
        cin >> n >> k;

        fill_n(rockToSpace, n + 1, 0);
        fill_n(rockNum, n + 1, 0);
        fill_n(depth, n + 1, 0);
        fill_n(visit, n + 1, false);
        desiredRocks.clear();
        for(int i = 0; i<=n; i++) v[i].clear();

        for(int i = 1; i<= n; i++){
            cin >>rockNum[i];
            rockToSpace[rockNum[i]] = i;
        }

        for(int i = 0;i <k; i++){
            int a;
            cin >> a;
            desiredRocks.push_back(a);
        }

        for(int i = 0; i< n; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        bfs();

        for(int rock : desiredRocks){
            int space = rockToSpace[rock];
            cout << depth[space] << " ";
        }
        cout << "\n";

    }
    return 0;
}
