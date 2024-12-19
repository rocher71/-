#include <vector>
#include <iostream>
using namespace std;

int tc;

int main(){
    cin >> tc;
    while(tc--){
        int n, k;
        vector<int> circle, ans;

        cin >> n >> k;

        for(int i = 1; i<= n; i++) circle.push_back(i);

        if(k == 0){
            for(int num : circle) ans.push_back(num);
        } else {
            int currIdx = 0;
            while(!circle.empty()){
                currIdx = (currIdx + k) % circle.size();
                ans.push_back(circle[currIdx]);
                circle.erase(circle.begin() + currIdx);

                if(currIdx == circle.size()) currIdx = 0;
            }
        }

        for(int i = 0; i< ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
