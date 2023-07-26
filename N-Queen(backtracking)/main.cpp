#include <iostream>
#include <vector>
using namespace std;

bool isAttacked(int i, int j, vector<pair<int, int>> &v){
    for(int k = 0; k < v.size(); k++){
        int x = v[k].first;
        int y = v[k].second;
        if(i == x || j == y || y-x == j-i || x+y == i+j){
            return false;
        }

    }
    return true;
}

vector<vector<int> > board;
int flag = 0;

void QueenPlaced(int i, int j, int n, vector<vector<int> > arr, vector<pair<int, int> > v, int q){

    arr[i][j] = 1;
    q = q - 1;
    if (q == 0){
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        flag = 1;
        return;
    }
    v.push_back({i, j});

    for(int x = i; x < n; x++){
        for(int y = (x != i) ? 0 : j; y < n; y++){
            if (isAttacked(x, y, v) == true){
                if (flag == 1)
                    break;
                QueenPlaced(x, y, n, arr, v, q);
            }
        }
    }
    arr[i][j] = 0;
    v.pop_back();
    return;
}

int main()
{
    int n, q;
    cin>>n;
    q = n;
    vector<vector<int> > arr(n, vector<int>(n, 0));
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (flag == 1)
                break;
            QueenPlaced(i, j, n, arr, v, q);
        }
    }

    if (flag == 0){
        cout<<"NO"<<endl;
    }

    return 0;
}
