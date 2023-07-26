#include<bits/stdc++.h>

using namespace std;

bool follow_pattern(string pattern, string s){
    unordered_map<char, string> c_ump;
    unordered_map<string, char> s_ump;
         s += " ";
        string t = s;
        int words = 0;
        while(!t.empty()){
            int pos = t.find(" ");
            t = t.substr(pos+1);
            words++;
        }
        if(words != pattern.size()){
            return false;
        }
        for(int i = 0; i < words; i++){
            string temp = " ";
            int pos = s.find(" ");
            temp = s.substr(0, pos);
            s = s.substr(pos+1);
            if(c_ump[pattern[i]].empty() && s_ump[temp] == NULL|| c_ump[pattern[i]] ==                      temp && s_ump[temp] == pattern[i]){
                c_ump[pattern[i]] = temp;
                s_ump[temp] = pattern[i];
            }else{
                return false;
            }
        }
        return true;
}

int main(){ 
     string s, pattern;
     getline(cin, s);
     cin>>pattern;
     if(follow_pattern(pattern, s)){
         cout<<"true"<<endl;
     }else{
         cout<<"false"<<endl;
     }
  return 0;
}