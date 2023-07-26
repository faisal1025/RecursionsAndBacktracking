#include <iostream>
#include<vector>
using namespace std;

int ans = 0;

void display(vector<vector<bool> > &grid, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (grid[i][j])
                cout<<"K"<<" ";
            else
                cout<<"."<<" ";
        }
        cout<<endl;
    }
}

bool isItSafe(vector<vector<bool> > &grid, int i, int j, int n){
    if (i - 1 >= 0 && grid[i-1][j]){
            return false;
    }
    if (i - 1 >= 0 && j - 1 >= 0 && grid[i-1][j-1]){
            return false;
    }
    if (i - 1 >= 0 && j + 1 <= n-1 && grid[i-1][j+1]){
            return false;
    }
    if (j - 1 >= 0 && grid[i][j-1]){
            return false;
    }
    return true;
}

void n_king(vector<vector<bool> > &grid, int n, int cr, int cc, int countn){

    if(countn == n){
        ans++;
        display(grid, n);
        cout<<"\n\n";
        return;
    }
    for(int i = cr; i < n; i++){
        for(int j = (i == cr)?cc : 0; j < n; j++){
            if(isItSafe(grid, i, j, n)){
                grid[i][j] = true;
                n_king(grid, n, i, j+2, countn+1);
                grid[i][j] = false;
            }
        }
    }
}

int main()
{
    int n;
    vector<vector<bool> > grid(n, vector<bool>(n, false));
    cin>>n;
    n_king(grid, n, 0, 0, 0);
    cout<<ans;
    return 0;
}
