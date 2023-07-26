#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long int n, msum = 0;
        cin>>n;
        std::vector<long int> arr(n);
        for(long int i = 0; i < n; i++){
            cin>>arr[i];
        }
        auto max = max_element(arr.begin(), arr.end());
        auto min = min_element(arr.begin(), arr.end());
        int diff = *max - *min;
        msum = diff*2;
        cout<<msum<<endl;
    }
	return 0;
}
