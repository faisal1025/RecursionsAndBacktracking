// Time Complexity = O(n!)

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset<100> col, ld, rd;
int ans = 0;

void display(vector<vector<bool> > &grid, int n) {
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++) {
            if (grid[row][col])
                cout<<"Q"<<" ";
            else
                cout<<"."<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}
void N_queen(vector<vector<bool> > &grid, int n, int cr) {
    if(cr == n){
        ans++;
        display(grid, n);
        return;
    }
    for(int cc = 0; cc < n; cc++){
        if(col[cc] == 0 && ld[(cr - cc)+(n-1)] == 0 && rd[cr+cc] == 0) {
            col[cc] = ld[(cr - cc)+(n-1)] = rd[(cr+cc)] = grid[cr][cc] = 1;
            N_queen(grid, n, cr+1);
            col[cc] = ld[(cr - cc)+(n-1)] = rd[cr+cc] = grid[cr][cc] = 0;
        }
    }

}

int main()
{
    int n;
    //why integer vector doesn't work
    vector<vector<bool> > grid(n, vector<bool> (n, 0));
    cin >> n;
    N_queen(grid, n, 0);
    cout<<ans;
    return 0;
}
