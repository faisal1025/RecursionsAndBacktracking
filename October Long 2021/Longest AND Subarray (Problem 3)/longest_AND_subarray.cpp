#include<bits/stdc++.h>
#define size 100000000
using namespace std;


int main(){
    vector<int> arr(1000000001);
    int max = arr[1] = 1;
    int cnt = 1;
    long long i, j = 1;
    for(i = 2; i <= size; i++){
        if((j & i) > 0){
            j = j & i;
            cnt++;
        }else{
            cnt = 1;
            j = i;
        }
        if(max < cnt) max = cnt;
        arr[i] = max;
    }
    for(; i <= 1000000001; i++){
        if((j & i) > 0){
            j = j & i;
            cnt++;
        }else{
            cnt = 1;
            j = i;
        }
        if(max < cnt) max = cnt;
        arr[i] = max;
    }
    
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<arr[n]<<"\n";
    }
    return 0;
}