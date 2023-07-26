#include<bits/stdc++.h>
using namespace std;
const int m = 5e5+5;
vector<vector<int>> v(m);

void sieve(){
    for(int i = 1; i < m; i++)
        for(int j = i; j < m; j += i)
            v[j].push_back(i);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    int t;
    cin>>t;
    while(t--){
        int n, m, b;
        cin>>n>>m;
        long long int cnt = 0;
        for(b = 2; b <= n; b++){
            int x = m-(m%b);
            if(x > 0)
                cnt += lower_bound(v[x].begin(), v[x].end(), b) - v[x].begin();
            else
                cnt += b-1;
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}