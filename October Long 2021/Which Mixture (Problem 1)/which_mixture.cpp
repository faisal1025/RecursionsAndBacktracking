#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int s, l;
        cin>>s>>l;
        if(s != 0 and l != 0) cout<<"Solution"<<endl;
        else if(s == 0 and l != 0) cout<<"Liquid"<<endl;
        else if(s != 0 and l == 0) cout<<"Solid"<<endl;
    }
    
}