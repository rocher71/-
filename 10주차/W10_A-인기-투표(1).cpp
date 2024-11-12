#include <iostream>
#include <queue>
using namespace std;

int tc;

int main(){
    cin >> tc;
    while(tc--){
        int n, inha;
        priority_queue<int> pq;

        // 총 학생 수, 인하의 득표수
        cin >> n >> inha;
        // 나머지 학생들의 득표수를 pq에 저장
        for(int i = 1; i< n; i++){
            int cnt;
            cin >> cnt;
            pq.push(cnt);
        }

        int moves = 0;

        // 인하의 스티커 개수가 득표수가 가장 높은 후보자보다 커질 때까지 반복
        while(!pq.empty() && inha <= pq.top()){
            int maxStickers = pq.top();
            pq.pop();

            // 스티커 하나를 인하에게 옮기기
            inha++;
            maxStickers--;
            moves++;
            
            // 옮긴 뒤 pq에 다시 삽입
            pq.push(maxStickers);
        }

        cout << moves << "\n";

    }

    return 0;
}
