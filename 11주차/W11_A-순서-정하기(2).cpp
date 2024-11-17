#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<int> circle;
        for(int i=1; i<=N; i++) circle.push_back(i);
        vector<int> ans;

        if(K == 0){
            // K가 0인 경우, 원판을 회전하지 않고 순서대로 출력
            for(auto num : circle){
                ans.push_back(num);
            }
        }
        else{
            int current_index = 0;
            while(!circle.empty()){
                // 시계방향으로 K칸 이동
                current_index = (current_index + K) % circle.size();
                ans.push_back(circle[current_index]);
                circle.erase(circle.begin() + current_index);
                // 다음 현재 위치는 현재 인덱스를 기준으로 설정 (이미 제거된 후의 인덱스)
                if(current_index == circle.size()){
                    current_index = 0;
                }
            }
        }

        // 결과 출력
        for(int i=0; i<ans.size(); i++){
            cout << ans[i];
            if(i != ans.size()-1) cout << " ";
            else cout << "\n";
        }
    }
    return 0;
}
