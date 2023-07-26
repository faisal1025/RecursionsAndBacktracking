#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        // Taking input
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        // Checking if operation required or not
        int operation = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) operation = 1;
        }

        // Operation required
        if(operation){
            vector<int> b;
            for(int z = 0; z < n; z++){
                vector<int> sub(n+1, 0);
                for(int i = z; i < n; i++){
                    sub[arr[i]] = 1;
                    for(int j = 0; j < sub.size(); j++){
                        if(sub[j] == 0){
                            b.push_back(j);
                            break;
                        }
                    }
                }
            }
            // cout<<"Before sorting :";
            // for(int i = 0; i < b.size(); i++){
            //     cout<<b[i]<<" ";
            // }
            // cout<<endl;
            sort(b.begin(), b.end());
            // cout<<"After sorting :";
            // for(int i = 0; i < b.size(); i++){
            //     cout<<b[i]<<" ";
            // }
            // cout<<endl;
            cout<<b[k-1]<<"\n";

        // Operation not required
        }else{
            cout<<0<<"\n";
        }
    }
    return 0;
}