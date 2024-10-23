#include <iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;

int tc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		int cnt, indeok = 0, biryong = 0;
		vector<pair<int, string>> inScore, biScore; //{������, �̸�}
		cin >> cnt;
	
		for (int i = 0; i < cnt; i++) {
			int newIn, newBi;
			string player;
			cin >> newIn >> newBi >> player;

			//�δ��� ����
			if (newIn != indeok) {
				int idx = -1;
				for (int i = 0; i < inScore.size(); i++) {
					if (inScore[i].second == player) {
						idx = i;
						break;
					}
				}

				//���� ����
				if (idx != -1) {
					inScore[idx].first += (newIn - indeok);
					indeok = newIn;
					continue;
				}
				//���ο� ����
				inScore.push_back({ newIn - indeok, player });
				indeok = newIn;
				continue;
			}

			//����� ����
			int idx = -1;
			for (int i = 0; i < biScore.size(); i++) {
				if (biScore[i].second == player) {
					idx = i;
					break;
				}
			}

			//���� ����
			if (idx != -1) {
				biScore[idx].first += (newBi - biryong);
				biryong = newBi;
				continue;
			}
			//���ο� ����
			biScore.push_back({ newBi - biryong, player });
			biryong = newBi;
			continue;
		}

		//�δ��� �¸��� �δ��� �� �ִٵ����� ���
		if (indeok > biryong) {
			sort(inScore.begin(), inScore.end());
			cout << inScore[inScore.size() - 1].second << " " << inScore[inScore.size() - 1].first << "\n";
			continue;
		}

		//����� �¸��� ����� �� �ִٵ����� ���
		sort(biScore.begin(), biScore.end());
		cout << biScore[biScore.size() - 1].second << " " << biScore[biScore.size() - 1].first << "\n";


	}
}

/*
1
6
2 0 a
5 0 a
9 0 a
9 4 b
9 11 c
9 13 d

*/
