#include<bits/stdc++.h>
using namespace std;

vector<int> getDigit(int n){
    vector<int> li;
    while (n != 0)  
    {
        int dig = n%10;
        li.push_back(dig);
        n = n/10;
    }
    return li;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, d;
        cin>>n>>d;
        vector<int> digs = getDigit(n);
        
        if(d == 0){
            int flag = 0;
            for(int i = digs.size()-1; i >= 0; i--){
                if(digs[i] == d and flag == 0){
                    digs[i] = 1;
                    flag = 1;
                }
                else if(flag) digs[i] = 1;
            }
        }

        if(d == 9){
            int flag = 0;
            for(int i = digs.size()-1; i >= 0; i--){
                if(digs[i] == d and flag == 0){
                    digs[i] = 0;
                    if(i+1 > digs.size()-1){
                        digs.push_back(1);
                    }else{
                        int j = i+1;
                        digs[j] += 1;
                        while(digs[j] == 9){
                            digs[j] = 0;
                            j = j+1;
                            if(j <= digs.size()-1)
                            digs[j] += 1;
                            else{
                                digs.push_back(1);
                                break;
                            }
                        }
                    }
                    flag = 1;
                }
                else if(flag) digs[i] = 0;
            }
        }

        if(0 < d and d < 9){
            int flag = 0;
            for(int i = digs.size()-1; i >= 0; i--){
                if(digs[i] == d and flag == 0){
                    digs[i] += 1;
                    flag = 1;
                }
                else if(flag) digs[i] = 0;
            }
        }

        // makeing new number
        int newn = 0;
        for(int r = digs.size()-1; r >= 0; r--){
            newn = newn*10+digs[r];
        }

        int ans = newn - n;
        cout<<ans<<endl;
    }
    return 0;
}