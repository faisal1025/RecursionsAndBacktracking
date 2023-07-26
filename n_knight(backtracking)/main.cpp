#include <iostream>
#include<vector>
using namespace std;

int ans = 0;

bool isItSafe(vector<vector<bool> > &grid, int i, int j, int n){
    if(i - 2 >= 0 && j + 1 <= n-1 && grid[i-2][j+1]) return false;
    if (i - 2 >= 0 && j - 1 >= 0 && grid[i-2][j-1]) return false;
    if (i - 1 >= 0 && j + 2 <= n-1 && grid[i-1][j+2])return false;
    if (i - 1 >= 0 && j - 2 >= 0 && grid[i-1][j-2])return false;
    return true;
}

void n_knight(vector<vector<bool> > &grid, int n, int cr, int cc, int countn){
    if(countn == n){
        ans++;
        return;
    }
    for(int i = cr; i < n; i++){
        for(int j = (i == cr)?cc : 0; j < n; j++){
            if(isItSafe(grid, i, j, n)){
                grid[i][j] = true;
                n_knight(grid, n, i, j+1, countn+1);
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
    n_knight(grid, n, 0, 0, 0);
    cout<<ans;
    return 0;
}
