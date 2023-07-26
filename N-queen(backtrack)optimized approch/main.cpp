// Time Complexity = O(n!)

#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int> > &board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isItSafe(vector<vector<int> > &board, int n, int row, int col){
    for(int i = row-1; i >= 0; i--){
        if (board[i][col] == 1){
            return false;
        }
    }
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1){
            return false;
        }
    }
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if (board[i][j] == 1){
            return false;
        }
    }
    return true;
}

int possiblity = 0;

void n_queen(vector<vector<int> > &board, int n, int curren_row){
    if (curren_row == n) {
        display(board, n);
        possiblity++;
        cout<<"\n\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isItSafe(board, n, curren_row, i)){
            board[curren_row][i] = 1;  // initialize
            n_queen(board, n, curren_row+1);
            board[curren_row][i] = 0; // reinitialize
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > board(n, vector<int> (n, 0));
    n_queen(board, n, 0);
    cout<<"possibilities = "<<possiblity<<endl;
    return 0;
}
