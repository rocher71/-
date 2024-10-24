#include <iostream>
#include <map>
using namespace std;

int tc, cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> tc;
    while(tc--){
        cin >> cnt;
        int inScore = 0, biScore = 0, newIn, newBi;
        string player;
        map<string, int> inPlayerScores, biPlayerScores;
        for(int i = 0; i< cnt; i++){
            cin >> newIn >> newBi >> player;

            // 인덕팀 득점
            if(newIn != inScore){
                if(inPlayerScores.find(player) != inPlayerScores.end()) inPlayerScores.insert({player, newIn - inScore});
                else inPlayerScores[player] += newIn - inScore;
                inScore = newIn;
                continue;
            }

            //비룡팀 득점
            if(biPlayerScores.find(player) != biPlayerScores.end()) biPlayerScores.insert({player, newBi - biScore});
            else biPlayerScores[player] += newBi - biScore;
            biScore = newBi;
        }

        int ansScore = 0;
        string ansPlayer = "";
        // 인덕팀 승리
        if(inScore > biScore){
            for(auto it : inPlayerScores){
                if(it.second < ansScore) continue;
                ansScore = it.second;
                ansPlayer = it.first;
            }
        }
        // 비룡팀 우승
        else{
            for(auto it : biPlayerScores){
                if(it.second < ansScore) continue;
                ansScore = it.second;
                ansPlayer = it.first;
            }
        }

        cout << ansPlayer << " " << ansScore << "\n";
    }
}
