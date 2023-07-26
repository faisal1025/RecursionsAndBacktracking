#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool is_perm(string s, string str){
    int needle[26] = {0};
    int haystack[26] = {0};
    bool ans = true;
    for(int i = 0; i < s.size(); i++){
        needle[s[i] - 'a']+=1;
        haystack[str[i] - 'a']+=1;
    }
    
        for(int i = s.length(); i <= str.length(); i++)
        {
            ans = true; 
            for(int i = 0; i < 26; i++){
                if(haystack[i] != needle[i]){
                    ans = false;
                    break;
                }
            }
            if(ans == true)
                return true;
            haystack[str[i-s.size()] - 'a']-=1;
            haystack[str[i] - 'a']+=1;
             
        }
    
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        string str;
        cin>>s;
        cin>>str;
        if(is_perm(s, str)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}