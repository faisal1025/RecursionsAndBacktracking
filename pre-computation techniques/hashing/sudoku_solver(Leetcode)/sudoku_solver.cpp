#include<bits/stdc++.h>
using namespace std;

bool isvalidsudoku(vector<vector<char> > &board){
    unordered_map<char, int>row;
    unordered_map<char, int>col;
    unordered_map<char, int>dia;
    for(int i = 0; i < 9; i++){
        row.clear();
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4'
                    ||board[i][j] == '5' || board[i][j] == '6'||board[i][j] == '7'|| 
                    board[i][j] == '8'|| board[i][j] == '9' ){
                if(row[board[i][j]] > 0){
                    return false;
                }
                row[board[i][j]] += 1;
            }
        }
    }
    for(int j = 0; j < 9; j++){
        col.clear();
        for(int i = 0; i < 9; i++){
            if(board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4'
                    ||board[i][j] == '5' || board[i][j] == '6'||board[i][j] == '7'|| 
                    board[i][j] == '8'|| board[i][j] == '9' ){
                if(col[board[i][j]] > 0){
                    return false;
                }
                col[board[i][j]] += 1;
            }
        }
    }
    for(int i = 0; i < 9; i += 3){
        for(int j = 0; j < 9; j += 3){
            dia.clear();
            for(int x = i; x < i+3; x++){
                for(int y = j; y < j+3; y++){
                    if(board[x][y] == '1' || board[x][y] == '2' || board[x][y] == '3' || board[x][y] == '4'
                    ||board[x][y] == '5' || board[x][y] == '6'||board[x][y] == '7'|| 
                    board[x][y] == '8'|| board[x][y] == '9' ){
                        if(dia[board[x][y]] > 0){
                            return false;
                        }
                        dia[board[x][y]] += 1;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char> > board(9, vector<char>(9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>board[i][j];
        }
    }
    if(isvalidsudoku(board)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}