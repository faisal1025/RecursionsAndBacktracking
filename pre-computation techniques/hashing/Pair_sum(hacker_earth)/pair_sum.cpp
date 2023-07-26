#include<bits/stdc++.h>

using namespace std;

bool is_pair_sum(int arr[], int n, int k){
    unordered_map<int, int> sum;
    for(int i = 0; i < n; i++){
        int x = k - arr[i];
        if(sum.find(x) != sum.end()){
            return true;
        }
        sum[arr[i]] = x;
    }
    return false;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(is_pair_sum(arr, n, k)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}