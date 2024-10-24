#include <iostream>
#include <vector>
#include <map>
using namespace std;

int tc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
    while(tc--){
        int cnt, indeokScore = 0, biryongScore = 0;
        map<string, int> inPlayerScores, biPlayerScores;
        cin >> cnt;

        for(int i = 0; i< cnt; i++){
            int newIn, newBi;
            string player;
            cin >> newIn >> newBi >> player;

            // 인덕팀 득점
            if(newIn != indeokScore){
                if(inPlayerScores.find(player) == inPlayerScores.end()) inPlayerScores.insert({player, newIn - indeokScore});
                else inPlayerScores[player] += newIn - indeokScore;
                indeokScore = newIn;
                continue;
            }

            // 비룡팀 득점
            if(biPlayerScores.find(player) == biPlayerScores.end()) biPlayerScores.insert({player, newBi - biryongScore});
            else biPlayerScores[player] += newBi - biryongScore;
            biryongScore = newBi;
        }

        int ansScore = 0;
        string ansPlayer = "";
        // 인덕팀이 이긴 경우
        if(indeokScore > biryongScore){
            for(map<string, int>::iterator it = inPlayerScores.begin(); it != inPlayerScores.end(); it++){
                if(ansScore > it->second) continue;
                ansScore = it->second;
                ansPlayer = it->first;
            }
        }
        // 비룡팀이 이긴 경우
        else {
            for(map<string, int>::iterator it = biPlayerScores.begin(); it != biPlayerScores.end(); it++){
                if(ansScore > it->second) continue;
                ansScore = it->second;
                ansPlayer = it->first;
            }
        }
        cout << ansPlayer << " " << ansScore <<  "\n";
    }
}
