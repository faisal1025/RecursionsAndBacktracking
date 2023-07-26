#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    double k1, k2, k3, v, total_speed, total_time, round_time;
    cin>>t;
    while(t--){
        cin>>k1>>k2>>k3>>v;
        total_speed = k1*k2*k3*v;
        total_time = 100/total_speed;
        round_time = floor(total_time*100+0.5)/100;
        if(round_time >= 9.58)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    
}