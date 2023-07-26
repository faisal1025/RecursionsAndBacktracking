#include<bits/stdc++.h>

using namespace std;
const int N = 10^7+10;

long long arr[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin>>n>>m;
    while(m--){
        long long a, b, k;
        cin>>a>>b>>k;
        arr[a] += k;
        arr[b+1] -= k;
    }
    for(int i = 1; i <= n; i++){
        arr[i] += arr[i-1];
    }
    long long max = 0;
    for(int i = 1; i <= n; i++){
        if(max < arr[i])
            max = arr[i];
    }
    cout<<max<<endl;
}