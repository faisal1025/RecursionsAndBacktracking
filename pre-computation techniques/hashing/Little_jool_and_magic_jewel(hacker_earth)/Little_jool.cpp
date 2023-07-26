/* Given a string "rrruubbbyy". Find how many number of "ruby" can be written from
 the given string
 constraints:
 1 <= t <= 100
 1 <= |s| <= 100
*/ 
#include <bits/stdc++.h>

using namespace std;

int no_of_ruby(string str){
    unordered_map<char, int> ump;
    int min_count = INT_MAX;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'r' || str[i] == 'u' || str[i] == 'b' || str[i] == 'y')
            ump[str[i]] += 1;
    }
    
    if(ump['r'] != 0 && ump['u'] != 0 && ump['b'] != 0 && ump['y'] != 0){
        for(unordered_map<char, int>::iterator iter = ump.begin(); iter != ump.end(); iter++){
            if(min_count > iter->second)
                min_count = iter->second;
        }
    }else{
        return 0;
    }
    return min_count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = no_of_ruby(s);
        cout<<ans<<"\n";
    }
}