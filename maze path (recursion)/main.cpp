#include <iostream>

using namespace std;

int totalpath = 0;

void mazePath(int i, int j, int n , int m, string osf){
    //base case
    if (i == n-1 && j == m-1){
        totalpath += 1;
        cout<<"[ "+osf+" ]"<<endl;
        return ;
    }
    //recursive hypothesis there can be two choice of one box right or down
    if (j < m)
        mazePath(i, j+1, n, m, osf+" R ");//right path
    else
        return;
    if (i < n)
        mazePath(i+1, j, n, m, osf+" D ");//down path
    else
        return;
    if (j < m && i < n)
        mazePath(i+1, j+1, n, m, osf+" Dia ");//diagonal move
    else
        return;
}
int main()
{
    int n, m;
    cin>> n >> m;
    mazePath(0, 0, n, m, "");
    cout << "Total path = "<<totalpath;
    return 0;
}
