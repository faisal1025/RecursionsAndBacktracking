#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string ans;
        int N, x, k;
        cin>>N>>x>>k;
        if(N-1 == x || x == 0){
            cout<<"Yes";
            continue;
        }
        if(x >= k){
            if(x % k  == 0){
                ans = "Yes";
            }else{
                int limit = (N+1)-x;
                if(limit % k == 0){
                    ans = "Yes";
                }else{
                    ans = "No";
                }
            }
        }else{
            int limit = (N+1)-x;
            if(limit % k == 0){
                ans = "Yes";
            }else{
                ans = "No";
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}