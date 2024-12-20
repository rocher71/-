#include <iostream>
using namespace std;

int tc;
int arr[501][501], cnt[501][501];
int row, col, trashCnt;

int main(){
    cin >> tc;
    while(tc--){
        cin >> row >> col;

        fill(&arr[0][0], &arr[row][col], 0);
        fill(&cnt[0][0], &cnt[row][col], 0);
        trashCnt = 0;

        for(int i = 0; i< row; i++){
            for(int j = 0; j< col; j++){
                cin >> arr[i][j];
                if(arr[i][j]) trashCnt++;
            }
        }

        for(int i = row - 1 ;i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                int bottomCnt = i +1 >= row ? 0 : cnt[i+1][j];
                int rightCnt = j +1 >= col ? 0 : cnt[i][j+1];
                cnt[i][j] = max(bottomCnt, rightCnt);
                if(arr[i][j]) cnt[i][j]++;
            }
        }

        cout << trashCnt - cnt[0][0] << "\n";
    }
}
