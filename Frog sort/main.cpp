#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int index(vector<int> &w, int ele){
    auto it = find(w.begin(), w.end(), ele);
    int index = it - w.begin();
    return index;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, curr_i = 0, ans = 0, dupt, temp_dupt = -1;
        cin>>n;
        vector<int>  pos(10, 0);
        vector<int> w_;
        vector<int>w(10, 0);
        vector<int> l(10, 0);

        for(int i = 0; i < n; i++){
            cin>>w[i];
        }

        for(int i = 0; i < n; i++){
            pos[i] = i;
        }

        for(int j = 0; j < n; j++){
            cin>>l[j];
        }

        w_ = w;

        sort(w_.begin(), w_.end() - (w.size()-n));

        for(int k = 0; k < n-1; k++){
            int pos1 = pos[index(w, w_[k])];
            int pos2 = index(w, w_[k+1]);

            curr_i = pos2;
            if (pos2 <= pos1){

                do{
                    curr_i = curr_i + l[pos2];
                    ans++;

                    if (curr_i > pos1){
                        pos[pos2] = curr_i;
                    }

                }while(curr_i <= pos1);
            }

        }
        cout<<ans<<endl;
    }
	return 0;
}
