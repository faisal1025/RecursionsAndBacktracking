//given an array of size n and Q queries in each query range from L to R calculate sum from L to R
//(including L and R).

//CONSTRAINT
//t = 1sec

#include<bits/stdc++.h>

using namespace std;

int main (){
    int n, arr[100], Q, prefix_sum[100];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int pre = 0;
    for(int i = 0; i < n; i++){
        prefix_sum[i] = arr[i]+pre;
        pre = prefix_sum[i];
    }
    cin>>Q;
    while(Q--){
        int sum = 0;
        int L, R;
        cin>>L>>R;
        /*
        time complexity = O(N)+O(Q*N) = O(N^2)
        for(int j = L; j < R; j++){
            sum+=arr[j];
        }
        */
        sum = prefix_sum[R] - prefix_sum[L-1];
        cout<<sum;
    }

    return 0;
}