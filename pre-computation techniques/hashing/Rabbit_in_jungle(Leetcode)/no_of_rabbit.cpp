#include<bits/stdc++.h>
using namespace std;

int numRabbits(vector<int>& answers) {
        vector<int> hsh(1010, 0);
        if(answers.empty())
            return 0;
        
        for(int i = 0; i < answers.size(); i++){
            hsh[answers[i]]++;
        }
        
        int rabbit = 0;
        for(int i = 0; i < hsh.size(); i++){
            if(hsh[i] != 0){
                if(hsh[i] > i+1){
                    int ans = hsh[i]/(i+1);
                    int r = hsh[i]%(i+1);
                    if(r != 0)
                        rabbit += (ans*(i+1))+(i+1);
                    else if(r == 0)
                        rabbit += ans*(i+1);
                }
                if(hsh[i] <= i+1)
                    rabbit += i+1;
            }
        }
        return rabbit;
    }

int main(){
    vector<int> answers;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        answers.push_back(x);
    }
    cout<<numRabbits(answers);
}