#include <iostream>
#include <vector>
using namespace std;

int totalpath = 0;

void display(vector<vector<int> > &arr, int n){
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool isItSafe(int i, int j, int n){
    return i>=0 && i<n && j>=0 && j<n;
}

void Run_Maze(vector<vector<int> > &arr, int i, int j, int n, vector<vector<bool> > &visited){
    //base case
    if(i == n-1 && j == n-1){
        arr[i][j] = 5;
        display(arr, n);
        totalpath++;
        arr[i][j] = 0;
        return;
    }
    arr[i][j] = 5;
    visited[i][j] = false;
    if (isItSafe(i-1, j, n) && arr[i-1][j] == 0 && visited[i-1][j] == true){ // UP
        Run_Maze(arr, i-1, j, n, visited);
    }
    if (isItSafe(i, j-1, n) && arr[i][j-1] == 0 && visited[i][j-1] == true){ //LEFT
        Run_Maze(arr, i, j-1, n, visited);
    }
    if (isItSafe(i+1, j, n) && arr[i+1][j] == 0 && visited[i+1][j] == true){ //DOWN
        Run_Maze(arr, i+1, j, n, visited);
    }
    if (isItSafe(i, j+1, n) && arr[i][j+1] == 0 && visited[i][j+1] == true){ //RIGHT
        Run_Maze(arr, i, j+1, n, visited);
    }
    visited[i][j] = true;
    arr[i][j] = 0;
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>(n, 0));
    vector<vector<bool> > visited(n, vector<bool>(n, true));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    Run_Maze(arr, 0, 0, n, visited);
    cout<<totalpath;
    return 0;
}
