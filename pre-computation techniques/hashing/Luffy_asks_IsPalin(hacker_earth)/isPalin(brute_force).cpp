#include<bits/stdc++.h>
using namespace std;
const int N = 10^5+10;
int hsh[N][25];

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int n, q;
        cin>>n>>q;
        cin>>s;
        for(int i = 0; i < s.size(); i++){
            hsh[i+1][s[i] - 'a'] = 1;
        }
        for(int i  = 0; i < 26; i++){
            for(int j = 1; j <= s.size(); j++){
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
            if(odd_count <= 1){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}