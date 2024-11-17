#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int tc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    while(tc--){
        int n, m, k;
        cin >> n >> m >> k;

        vector<pair<int, int>> kickBoards(k);
        for(int i = 0; i<k; i++){
            int r, c;
            cin >> r>> c;
            // col, row 순서로 저장
            kickBoards[i] = make_pair(c, r);
        }

        // col 오름차순, row 오름차순 정렬
        sort(kickBoards.begin(), kickBoards.end());

        // 아르바이트생들의 마지막 행 번호 저장
        multiset<int> workers;
        
        for(auto& kb: kickBoards){
            int currCol = kb.first;
            int currRow = kb.second;

            // 현재 행 번호보다 작거나 같은 가장 큰 행 번호를 가진 아르바이트생 차기
            auto it = workers.upper_bound(currRow);
            if(it == workers.begin()){
                // 할당 가능한 아르바이트생이 없으므로 새로운 아르바이트생 추가
                workers.insert(currRow);
                continue;
            }

            // 이전 아르바이트생에게 할당
            --it;
            workers.erase(it);
            workers.insert(currRow);
        }
        cout << workers.size() << "\n";
    }
    return 0;
}
