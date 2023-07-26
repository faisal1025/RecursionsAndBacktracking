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
        set<int> ele;
        int operation = 0;
        for(int i = n-1; i >= 0; i--){
            if(arr[i] == 0) operation = 1;
            ele.insert(i);
        }
        ele.insert(n);

        // Operation required
        if(operation){
            vector<int> b;
            for(int z = 0; z < n; z++){
                set<int> sub = ele;
                cout<<"\n";
                for(int i = z; i < n; i++){
                    auto it = sub.find(arr[i]); 
                    if(it != sub.end()){
                        sub.erase(it);
                    }
                    auto mex = sub.begin();
                    b.push_back(*mex);
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