// 내 코드
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int tc, leftSemester, leftClassCnt, conditionsCnt, questionCnt;
int semesterRequired[1001], deg[1001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> tc;
    while(tc--){
        cin >> leftSemester >> leftClassCnt >> conditionsCnt;
        fill_n(semesterRequired, leftClassCnt + 1, -1);
        fill_n(deg, leftClassCnt + 1, 0);

        vector<vector<int>> conditions(leftClassCnt + 1);

        for(int i = 0; i < conditionsCnt ; i++){
            int a, b;
            cin >> a >> b;
            conditions[a].push_back(b);
            deg[b]++;
        }

        queue<pair<int, int>> q;
        for(int i = 1; i <= leftClassCnt; i++){
            if(deg[i] == 0) q.push({i, 1});
        }

        while(!q.empty()){
            int curr = q.front().first;
            int currTime = q.front().second;
            q.pop();

            semesterRequired[curr] = currTime;

            for(int i = 0; i< conditions[curr].size(); i++){
                int next = conditions[curr][i];

                if(--deg[next] == 0) q.push({next, currTime + 1});
            }

        }

        cin >> questionCnt;
        while(questionCnt--){
            int classNum;
            cin >> classNum;
            if(semesterRequired[classNum] == -1 || semesterRequired[classNum] > leftSemester){
                cout << "False\n";
                continue;
            }
            cout << "True\n";
        }

    }
}
