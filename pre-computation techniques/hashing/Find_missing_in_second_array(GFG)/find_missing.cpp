#include<bits/stdc++.h>

using namespace std;

vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{ 
	    vector<long long> arr;
	    unordered_map<long long, int> cnt;
	    for(int i = 0; i < N; i++){
	        cnt[A[i]] = 1;
	    }
	    for(int j = 0; j < M; j++){
	        cnt[B[j]] = 0;
	    }
        for(int i = 0; i < N; i++){
	        if(cnt[A[i]]){
                arr.push_back(A[i]);
            }
        }
	    
	    return arr;
      
	} 

int main(){
    int T;
    cin>>T;
    while(T--){
    int N, M;
    cin>>N>>M;
    long long A[N], B[M];
    
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }    
    for(int j = 0; j < M; j++){
        cin>>B[j];
    }
    vector<long long> ans;
    ans = findMissing(A, B, N, M);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    }
    return 0;
}