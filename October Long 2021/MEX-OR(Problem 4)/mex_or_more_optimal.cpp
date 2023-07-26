#include<bits/stdc++.h>
#define size 1000000000
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int ans = 0;
        for(int i = 0; i <= x; i = i+i+1){
            ans = i+1;
        } 
        cout<<ans<<endl;
    }
    return 0;
}