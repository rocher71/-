#include <iostream>
#include <algorithm>
using namespace std;

int tc;
int numbers[1000001];

int main(){
    cin >> tc;
    while(tc--){
        int n, m, q;
        cin >> n >> m;

        for(int i = 0 ;i < n * m; i++) cin >> numbers[i];

        cin >> q;
        while(q--){
            int num;
            cin >> num;
            if(binary_search(numbers, numbers + (n*m), num)){
                cout << "1 ";
                continue;
            }
            cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}
