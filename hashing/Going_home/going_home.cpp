#include<bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ld>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x, y, m, k;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(y == x)
                continue;
            for(int k = 0; k < n; k++){
                if(k == x || k == y)
                    continue;
                else
                    m = k;
        for(int j = 0; j < n; j++){
            if(j == x || j == y || j == m)
                continue;
            else
                k = j;
            if(arr[x] + arr[y] == arr[m] + arr[k])
                cout<<"YES";
                cout<<x<<" "<<y<<" "<<m<<" "<<k;
        }
    } 
        }
    }

    


    return 0;
}