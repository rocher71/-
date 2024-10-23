#include<iostream>
#include<stack>
using namespace std;
int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		string str, ans = "";
		stack<string> st;
		cin >> str;

		bool isTag = false;
		string tagString = "";
		for (int i = 0; i < str.length(); i++) {
			// �±� �ƴϸ鼭, < �ƴҶ�
			if (!isTag && str[i] != '<') continue;

			// < ã��, �� �±� ����
			if (!isTag && str[i] == '<') {
				//tagString += str[i];
				isTag = true;
				continue;
			}

			// �±� ����
			if (isTag && str[i] != '>') {
				tagString += str[i];
				continue;
			}

			// �±� ��
			if (isTag && str[i] == '>') {
				isTag = false;
				
				// ���� �±��� �� ���ÿ� �ٷ� push
				if(tagString[0] != '/'){
					st.push(tagString);
					tagString = "";
					continue;
				}
				
				// �ǹٸ� ��ġ�� �ݴ� �±����� Ȯ�� -> ���� ���ǻ� Ȯ�� ���ص���
				//if (st.top() == tagString.substr(1)) {
				//	st.pop();
				//	continue;
				//}
				// �ݴ� �±׸� ���ÿ� push ���ʿ����, top�� pop����
				st.pop();
				tagString = "";
			}
		}

		while (!st.empty()) {
			string name = st.top();
			st.pop();

			ans = ans + "</" + name + '>';
		}
		cout << ans << "\n";
	}


}
