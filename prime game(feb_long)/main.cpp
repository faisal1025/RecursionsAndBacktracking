#include <bits/stdc++.h>

using namespace std;

vector<long int> no_prime(1000000);

int seive(int n){
    long int cnt = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    no_prime[0] = no_prime[1] = 0;
    for (int i = 2; i < n; i++){
        if (prime[i]){
            cnt++;
            for (int j = 2*i; j < n; j = j+i){
                prime[j] = false;
            }
        }
        no_prime[i] = cnt;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, x, y;
    cin>>t;
    seive(1000001);
    while(t--){
        cin>>x>>y;
        if (no_prime[x] > y)
            cout<<"Divyam"<<"\n";
        else
            cout<<"Chef"<<"\n";
    }
    return 0;
}
