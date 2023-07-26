#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        int mp[n+1];
        set<int> s;
        for(int i = 0; i <= n; i++){
            s.insert(i);
        }
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            mp[arr[i]]++;
            s.erase(arr[i]);
        }
        auto it = s.begin();
        int mex = *it;
        if(mex == 0){ cout<<0; } 
        else{
            vector<int> noZero;
            if(arr[0] != 0){
                noZero.push_back(0);
            }   
            int i, sub = 0, cnt = 0;
            for(i = 0; i < n; i++){
                if(arr[i] == 0){
                    noZero.push_back(i);
                    sub += cnt*(cnt+1)/2;
                    cnt = 0;
                    continue;
                }
                cnt++;
            }
            sub += cnt*(cnt+1)/2;
            k = k - sub;
            vector<int> b;
            b.push_back(mex);
            if(k <= 0){
                cout<<0<<endl;
            }else{
                for(int i = 0; i < noZero.size()-1; i++){
                    for(int j = noZero[i]; j < noZero[i+1]; j++){
                        mp[j]--;
                        if(mp[j] == 0 and arr[j] < mex){
                            b.push_back(arr[j]);
                        }
                            
                        for(int z = n-1; z > noZero[i+1]; z--){
                            mp[arr[z]]--;
                            if(mp[arr[z]] == 0 and arr[z] < mex) {
                                s.insert(arr[z]);
                            }
                            auto it = s.begin();
                            mex = *it;
                            b.push_back(mex); 
                        }
                        if(mp[j] == 0){
                            s.insert(j);
                        }
                    }
                }
                        int j = noZero[i];
                        mp[j]--;
                        if(mp[j] == 0 and arr[j] < mex){
                            b.push_back(arr[j]);
                        }
                            
                        for(int z = n-1; z > noZero[i]; z--){
                            mp[arr[z]]--;
                            if(mp[arr[z]] == 0 and arr[z] < mex) {
                                s.insert(arr[z]);
                            }
                            auto it = s.begin();
                            mex = *it;
                            b.push_back(mex); 
                        }
                        if(mp[j] == 0){
                            s.insert(j);
                        }
            }
        }

        

    }
    


}