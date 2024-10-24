#include <iostream>
#include <math.h>
using namespace std;

int tc, h, q;
unsigned long long sum[32];

void binarySearch(unsigned long long number, unsigned long long start, unsigned long long last){
    unsigned long long mid;
    while(start != last - 1){
        mid = (start + last)/2;
        if(number > mid){
            cout << 'R';
            start = mid + 1;
            continue;
        }
        cout << 'L';
        last = mid;
    }

    if(number == start){
        cout << "L\n";
        return;
    }
    cout << "R\n";
    return;
}

int main(){
    sum[0] = 1;
    for(int i = 1; i< 32; i++) sum[i] = pow(2, i) + sum[i-1];

    cin >> tc;
    while(tc--){
        cin >> h >> q;
        for(int i = 0; i< q; i++){
            unsigned long long number, numHeight = 0;
            cin >> number;

            for(int j = 0; j < 32; j++){
                if(number > sum[j]) continue;
                numHeight = j;
                break;
            }

            binarySearch(number, pow(2, numHeight), pow(2, numHeight + 1) - 1);
        }
    }
}
/*
1
3
7
15
31
63
127
255
511
1023
2047
4095
8191
16383
32767
65535
131071
262143
524287
1048575
2097151
4194303
8388607
16777215
33554431
67108863
134217727
268435455
536870911
1073741823
2147483647 : pow(2, 31) - 1;
4294967295
*/
