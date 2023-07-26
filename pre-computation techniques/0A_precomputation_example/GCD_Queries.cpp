#include<bits/stdc++.h>

using namespace std;
const int N = 10^5+10;

int forward_gcd[N];
int backward_gcd[N];

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     while(t--){
         int n, q;
         cin>>n>>q;
         int arr[n]; 
         for(int i = 1; i <= n; i++){
             cin>>arr[i];
             forward_gcd[i] = gcd(forward_gcd[i-1], arr[i]);
         }
         backward_gcd[n] = n;
         for(int j = n-1; j >= 1; j--){
             backward_gcd[j] = gcd(backward_gcd[j+1], arr[j]);
         }
         while(q--){
             int l, r;
             cin>>l>>r;
             int ans = gcd(forward_gcd[l-1], backward_gcd[r+1]);
             /*
             time complexity = O(Q*N*N) = O(N^3) = 10^5 * 10^5 * 10^5 = 10^15
             int temp = 0;
             for(int i = 1; i <= n; i++){
                 int found = 0;
                 for(int j = l; j <= r; j++){
                    if(i == j){
                        found = 1;
                        break;
                    }
                 }
                if(found == 0){
                    temp = gcd(arr[i], temp);
                }
                 
             }
             cout<<temp<<endl;
             */
            cout<<ans<<endl;
         }
         
     }
     return 0;
 }