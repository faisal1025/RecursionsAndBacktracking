#include<bits/stdc++.h>
#define size 1000000000
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int flag = 1;
        int i, j = 0;
        for(i = 1; i <= x; i++){
            if((j | i) <= x){
                j++;
            }else{
                cout<<i<<"\n";
                flag = 0;
                break;
            }
        }
        if(flag) cout<<i<<"\n";
    }
    return 0;
}