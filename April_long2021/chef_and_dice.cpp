#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    long long int n;
    map<int, int> pipe;
    cin>>t;
    while(t--){
        long long int ans, rem;
        pipe.insert({{1, 20}, {2, 36}, {3, 51}});
        cin>>n;
        if(n == 1 || n == 2 || n == 3){
            cout<<pipe[n]<<"\n";
            continue;
        }else{
            rem = n % 4;            
            ans = (11*(n-rem)) + 16;
            if(rem == 0){
                cout<<ans<<"\n";
            }else{
                cout<<ans+pipe[rem]-4*rem<<"\n";
            }

        }
    }
}