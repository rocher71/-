#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <math.h>
using namespace std;

int tc, row, col, startY, startX, endY, endX;
int dy[4] = {0, 0, -1, 1};
int dx[4] = { -1, 1, 0, 0};
bool arr[1001][1001], visit[1001][1001];
int dist[1001][1001];

void bfs(){
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visit[startY][endY] = true;
    dist[startY][startX] = 0;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        if(currY == endY && currX == endX) break;

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(visit[nextY][nextX] || !arr[nextY][nextX]) continue;

            visit[nextY][nextX] = true;
            dist[nextY][nextX] = dist[currY][currX] + 1;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    cin >> tc;
    while(tc--){
        cin >> col >> row >> startX >> startY >> endX >> endY;

        fill(&arr[0][0], &arr[row][col], false);
        fill(&visit[0][0], &visit[row][col], false);
        fill(&dist[0][0], &dist[row][col], INT_MAX);

        startY = abs(startY - (row - 1));
        endY = abs(endY - (row - 1));

        for(int i = 0; i< row; i++){
            for(int j = 0; j < col ; j++){
                char c;
                cin >> c;
                if(c == 'O') arr[i][j] = true;
            }
        }

        bfs();

        if(!visit[endY][endX]){
            cout << "-1\n";
            continue;
        }
        cout << dist[endY][endX] << "\n";
    }
}
