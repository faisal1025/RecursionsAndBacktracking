#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int, int, int);
void ratRun(vector<vector<int>>&arr, int i, int j, int n, vector<vector<int>>&visited);

bool isSafe(int i, int j, int n){
    //Make sure that rat don't move out of maze
    return (i >= 0 && i < n && j >= 0 && j < n);
}
int path = 0;

void ratRun(vector<vector<int>>&arr, int i, int j, int n, vector<vector<int>>&visited){
    if (arr[n-1][n-1] == 1){
        //cheese is not in place
        return;
    }
    if (i == n-1 && j == n-1){
        // if rat reaches to (n-1,n-1) 1 path is found
        path++;
        return;
    }
    visited[i][j] = 1;

    if (isSafe(i-1, j, n) && arr[i-1][j] == 0 && visited[i-1][j] == 0){
            // For up
            ratRun(arr, i-1, j, n, visited);
    }
    if (isSafe(i+1, j, n) && arr[i+1][j] == 0 && visited[i+1][j] == 0){
            // For down
            ratRun(arr, i+1, j, n, visited);
    }
    if (isSafe(i, j-1, n) && arr[i][j-1] == 0 && visited[i][j-1] == 0){
            // For left
            ratRun(arr, i, j-1, n, visited);
    }
    if (isSafe(i, j+1, n) && arr[i][j+1] == 0 && visited[i][j+1] == 0){
            // For right
            ratRun(arr, i, j+1, n, visited);
    }
    visited[i][j] = 0;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> visited(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int i = 0, j = 0;
    ratRun(arr, i, j, n, visited);
    cout<<path;
    return 0;
}
