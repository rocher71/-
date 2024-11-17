#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;

        // 농작물의 수확 가능 시점과 품질 저하율을 저장
        vector<pair<int, int>> crops(N);
        for(int i=0;i<N;i++) cin >> crops[i].first; // t_k
        for(int i=0;i<N;i++) cin >> crops[i].second; // p_k

        // 수확 가능 시점(t_k) 기준으로 오름차순 정렬
        sort(crops.begin(), crops.end(), [&](const pair<int,int> &a, const pair<int,int> &b) -> bool{
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second; // t_k 같을 때 p_k 높은 순
        });

        // 우선순위 큐: p_k가 높은 순으로 정렬 (max heap)
        priority_queue<pair<int, int>> pq; // {p_k, t_k}

        long long total_loss = 0;
        int current_time = K;
        int i = 0;

        while(i < N || !pq.empty()){
            // 현재 시간에서 수확 가능한 모든 농작물을 큐에 추가
            while(i < N && crops[i].first <= current_time){
                pq.emplace(crops[i].second, crops[i].first);
                i++;
            }

            if(!pq.empty()){
                // 가장 높은 p_k를 가진 농작물 선택
                pair<int, int> crop = pq.top(); pq.pop();
                int p = crop.first;
                int t = crop.second;
                // 손실량 계산: (current_time - t_k) * p_k
                total_loss += (long long)(current_time - t) * p;
                // 수확 후 시간 증가
                current_time++;
            }
            else{
                // 수확 가능한 농작물이 없으면 다음 농작물의 t_k로 시간 이동
                if(i < N){
                    current_time = crops[i].first;
                }
            }
        }

        cout << total_loss << "\n";
    }
}
