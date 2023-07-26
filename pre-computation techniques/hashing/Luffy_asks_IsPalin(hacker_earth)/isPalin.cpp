#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
int hsh[N][26];

int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < N; j++){
                hsh[j][i] = 0;
            }
        }
        
        string s;
        int n, q;
        cin>>n>>q;
        cin>>s;
        for(int i = 0; i < n; i++){
            hsh[i+1][s[i] - 'a'] = 1;
        }
        for(int i  = 0; i < 26; i++){
            for(int j = 1; j <= n; j++){
                hsh[j][i] += hsh[j-1][i];
            }
        }
        
        while(q--){
            int l, r;
            cin>>l>>r;
            int odd_count = 0;
            for(int i = 0; i < 26; i++){
                int count = hsh[r][i] - hsh[l-1][i];
                if(count%2 != 0) odd_count++;
            }
            if(odd_count > 1){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
    }
}