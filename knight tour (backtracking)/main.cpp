#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int> > &grid, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool notvisited(vector<vector<int> > &grid, int n, int i, int j, vector<vector<bool> > &visited){
    return (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == false);
}

void knight_tour(vector<vector<int> > &grid, int n, int i, int j, int steps, vector<vector<bool> > &visited){

    //base case
    if (steps == (n*n)-1){
        grid[i][j] = steps;
        display(grid, n);
        cout<<"\n\n";
        return;
    }
    if (steps >= (n*n))
        return;

    int row_axis[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
    int col_axis[8] = {1, -1, 2, -2, 1, -1, -2, 2};

    visited[i][j] = true;
    grid[i][j] = steps;

    for(int k = 0; k < 8; k++){
        if (notvisited(grid, n, i+row_axis[k], j+col_axis[k], visited)){
            knight_tour(grid, n, i+row_axis[k], j+col_axis[k], steps+1, visited);
        }
    }
    grid[i][j] = -1;
    visited[i][j] = false;

}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > grid(n, vector<int>(n, -1));
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    knight_tour(grid, n, 0, 0, 0, visited);
    return 0;
}
