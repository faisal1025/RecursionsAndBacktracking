/*code
 road
 step 1.'r' ko hataya
 step 2.'c' ko laya
 step 3.'a' ko hataya
 step 4.'e' ko laya
 ans : 4
*/
#include<bits/stdc++.h>

using namespace std;

int no_of_operation(string s, string t){
    unordered_map<char, int> ms;
    unordered_map<char, int> mt;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        ms[s[i]]+=1;
    }
    
    for(int j = 0; j < t.size(); j++){
        mt[t[j]]+=1;
    }

    for(int i = 0; i < s.size(); i++){
        if(ms[s[i]] > mt[s[i]]){
            t = t+s[i];
            mt[s[i]]+=1;
            cnt++;
        }
    }
    
    for(int j = 0; j < t.size();){
        if(mt[t[j]] > ms[t[j]]){
            mt[t[j]]-=1;
            t = t.substr(0, j)+t.substr(j+1);
            cnt++;
        }else{
            j++;
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s, t;
        cin >> s;
        cin >> t;
        cout<<no_of_operation(s, t)<<endl;
    }
    return 0;
}