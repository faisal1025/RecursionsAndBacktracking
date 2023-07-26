#include<bits/stdc++.h>

using namespace std;

bool is_double_string(string s){
    unordered_map<char, int> cnt;
    for(int i = 0; i < s.size(); i++){
        cnt[s[i]] += 1;
        if(cnt[s[i]] > 1){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        if(is_double_string(s))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
}