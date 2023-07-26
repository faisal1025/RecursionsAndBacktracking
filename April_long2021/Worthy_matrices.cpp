#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll minimum(ll a, ll b){
    if(a<b)
        return a;

    return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, m, k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<vector<double> > matrix(n+1, vector<double>(m+1));
        for(ll i = 0; i <= n; i++){
            for(ll j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    matrix[i][j] = 0;
                }
                else{
                    cin>>matrix[i][j];
                }
            }
        }

        for(ll i = 0; i <= n; i++){
            double pre_sum = 0;
            for(ll j = 0; j <= m; j++){
                matrix[i][j] += pre_sum;
                pre_sum = matrix[i][j];
            }
        }

        for(ll j = 0; j <= m; j++){
            double pre_sum = 0;
            for(ll i = 0; i <= n; i++){
                matrix[i][j] += pre_sum;
                pre_sum = matrix[i][j];
            }
        }

        ll min_dimension = minimum(n, m);
        ll ans = 0;

        for(ll size = 1; size < min_dimension; size++){
            for(ll i = size; i <= n; i++){
                for(ll j = size; j <= m; j++){
                    ll x = matrix[i][j] + matrix[i-size][j-size] - matrix[i][j-size] - matrix[i-size][j];
                    if(x / (size*size) >= k)
                        ans++;
            
                }
            }
        }
        cout<<ans<<"\n";

    }

    return 0;
}