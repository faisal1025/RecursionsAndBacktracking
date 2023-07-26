/*count all the pairs in an array A[] those sum is equal to a given number k.
constraint:
1 <= N <= 10^5
1 <= K <= 10^8
1 <= Arr[i] <= 10^6
*/
#include<bits/stdc++.h>
using namespace std;

int getPairCount(int arr[], int n, int k){
    int cnt = 0;
    unordered_map<int, int> pair;
    for(int i = 0; i < n; i++){
        int x = k - arr[i];
        if(pair.find(x) != pair.end()){
            cnt+=pair[x];
        }
        pair[arr[i]] += 1;
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int c = getPairCount(arr, n, k);
        cout<<c<<"\n";
    }
}
