//abcabcbb
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> used;
    int max_len=0, start=0;
    for (int i=0;i<s.size();++i){
        if (used.find(s[i])!=used.end() && start<=used[s[i]]){
            start = used[s[i]] + 1;
        }
        else{
            max_len = max(max_len, i - start + 1);
        }
        used[s[i]] = i;
    }
    return max_len;
}

int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<"\n";
}