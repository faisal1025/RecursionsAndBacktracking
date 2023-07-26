#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int min = INT_MAX;

        // For a
        int cnt = 0;
        int bag = d;
        if(bag - a >= b || bag - a >= c){
            bag = bag - a;
            cnt = 1;
            if(bag - b >= c){
                bag = bag - b;
            }else if (bag - c >= b){
                bag = bag - c;
            }else{
                cnt = 2;
            }
        }else{
            cnt = 3;
        }
        if(min > cnt) min = cnt;
        
        // For b
        cnt = 0;
        bag = d;
        if(bag - b >= a || bag - b >= c){
            bag = bag - b;
            cnt = 1;
            if(bag - a >= c){
                bag = bag - a;
            }else if (bag - c >= a){
                bag = bag - c;
            }else{
                cnt = 2;
            }
        }else{
            cnt = 3;
        }
        if(min > cnt) min = cnt;

        // For c
        cnt = 0;
        bag = d;
        if(bag - c >= b || bag - c >= a){
            bag = bag - c;
            cnt = 1;
            if(bag - b >= a){
                bag = bag - b;
            }else if (bag - a >= b){
                bag = bag - a;
            }else{
                cnt = 2;
            }
        }else{
            cnt = 3;
        }
        if(min > cnt) min = cnt;
        cout<<min<<"\n";

    }
    
}