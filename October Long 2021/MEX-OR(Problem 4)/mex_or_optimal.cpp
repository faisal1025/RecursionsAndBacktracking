#include<bits/stdc++.h>
#define size 1000000000
using namespace std;

int main(){
    vector<int> arr(size+1);
    int ans = 0;
    for(int i = 0; i <= size; i = i+i+1){
        ans++;
        arr[i] = i+1;
    } 
    cout<<ans;
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(arr[x]) cout<<arr[x]<<endl;
        else{
            while (arr[x] == 0)
            {
                x--;
            }
            cout<<arr[x]<<endl;
        }
    }
    return 0;
}