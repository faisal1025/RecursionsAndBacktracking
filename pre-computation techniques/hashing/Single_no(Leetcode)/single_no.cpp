/*[2, 1, 1, 3, 2]
print :- 3 count=1
*/
#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        for(int j = 0; j < nums.size(); j++){
            if(cnt[nums[j]] == 1){
                return nums[j];
            }
        }
        return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans = singleNumber(nums);
    cout<<ans<<endl;   
}