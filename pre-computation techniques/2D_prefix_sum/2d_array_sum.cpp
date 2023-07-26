//given an 2d-array and dimension n and m . Given Q queries in each queries given 
//a point (i, j) and (x, y) find the sum of all the elements in that range. 

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, Q;
    cin >> n >> m;
    int arr[n+1][m+11], prefix_sum[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                prefix_sum[i][j] = 0;
            }
            else{
                cin>>arr[i][j];
                prefix_sum[i][j] = arr[i][j]+prefix_sum[i][j-1]+prefix_sum[i-1][j]-prefix_sum[i-1][j-1];
            }
        }
        cout<<endl;
    }
    
    cin>>Q;
    
    while(Q--){
        int sum = 0;  
        int i, j, x, y;
        cin>>i>>j>>x>>y;
        sum = prefix_sum[x][y] - prefix_sum[x][j-1] - prefix_sum[i-1][y] + prefix_sum[i-1][j-1];
         /*
        Time complexity = O(Q*N*M)
        for(int k = i; k <= x; k++){
            for(int l = j; l <= y; l++){
                sum+=arr[k][l];
            }
        }
        */
        cout<<sum;
    }

    return 0;
}