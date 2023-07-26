#include<bits/stdc++.h>

using namespace std;

void pair_exist(vector<long long>arr, int n){
    unordered_map<long long, pair<int, int> > mpp;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int sum = arr[i] + arr[j];
            if(mpp.find(sum) != mpp.end()){
                int x = mpp[sum].first;
                int y = mpp[sum].second;
                if(x != i && x != j && y != i && y != j){
                    cout<<"YES"<<endl;
                    cout<<i<<" "<<j<<" "<<x<<" "<<y;
                    return;
                }
            }
            mpp[sum] = {i, j};
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<long long>arr(n+10);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    pair_exist(arr, n);
    return 0;
}