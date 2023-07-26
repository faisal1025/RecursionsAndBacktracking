#include<bits/stdc++.h>
using namespace std;

int noRepeatCaracter(string s){
   unordered_map<char, int> cnt;
        int max = 0;
        string temp = "";
        if(s.length() == 0 || s.length() == 1)
            return s.length();
        temp += s[0];
        for(int i = 1; i < s.length(); i++){
            if(temp.find(s[i]) == -1){
                temp += s[i];
            }else{
                if(max < temp.length()){
                    max = temp.length();
                }
                int pos = temp.find(s[i]);
                temp += s[i];
                temp = temp.substr(pos+1);
            }
        }
        if(max < temp.length())
            max = temp.length();
        return max;
}

int main(){
    string s;
    cin>>s;
    cout<<noRepeatCaracter(s)<<endl;
}