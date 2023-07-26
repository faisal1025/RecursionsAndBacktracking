#include<bits/stdc++.h>
using namespace std;

int main(){
    long long m = 1000000007;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans = 1;
        long long pow = n-1;
        long long base = 2;
        while(pow > 0){
            if(pow % 2 != 0){
                ans = (ans * base) % m;
            }
            pow = pow / 2;
            base = (base * base) % m;
        }
        cout<<ans;
    }
    return 0;
}