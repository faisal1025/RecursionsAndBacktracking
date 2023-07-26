#include<bits/stdc++.h>

using namespace std;

string strong_lang(string str, int count, int k){
    if(count == k)
        return "Yes";
    if(str.empty()){
        return "No";
    }
    if(str[0] == '*'){
        return strong_lang(str.substr(1), ++count, k);
    }else{
        return strong_lang(str.substr(1), 0, k);
    }
    
}

int main(){
    int t, n, k;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;
        cout<<strong_lang(s, 0, k)<<"\n";
    }
}