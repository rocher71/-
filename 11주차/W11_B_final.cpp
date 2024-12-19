#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int tc;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n >>k;

        vector<pair<int, int>> crops(n);

        for(int i=0;i<n;i++) cin >> crops[i].first; // t_k
        for(int i=0;i<n;i++) cin >> crops[i].second; // p_k

        sort(crops.begin(), crops.end(), compare);

        priority_queue<pair<int, int>> pq;
        long long totalLoss = 0;
        int currTime = k;
        int i = 0;

        while(i < n || !pq.empty()){
            while(i < n && crops[i].first <= currTime){
                pq.push({crops[i].second, crops[i].first});
                i++;
            }

            if(!pq.empty()){
                int p = pq.top().first;
                int t = pq.top().second;
                pq.pop();

                totalLoss += (long long)(currTime - t) * p;
                currTime++;
                continue;
            }
            if(i >= n) continue;

            currTime = crops[i].first;
        }
        cout << totalLoss << "\n";
    }
}
