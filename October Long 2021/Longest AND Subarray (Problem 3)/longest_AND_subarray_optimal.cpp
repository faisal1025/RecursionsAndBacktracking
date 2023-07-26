#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p = log2(n);
        float p1 = (float)p;
        int i = pow(2.0, p1);
        int l1 = i/2;
        int l2 = (n-i)+1;
        if(l1 > l2) cout<<l1<<"\n";
        else cout<<l2<<"\n";
    }
    return 0;
}