#include <iostream>

using namespace std;

/*
* * * *
* * *
* *
*
print this as output when n=4 recursively
*/
void pattern1(int n, int i){
    if (n == 0) return;
    if (i < n){
        cout<<"* ";
        pattern1(n, i+1);

    }
    else {
        cout<<endl;
        pattern1(n-1, 0);
    }
}

/*
*
* *
* * *
* * * *
print this pattern when n = 4 recursively
*/
void pattern2(int n, int i){
    //base case
    if (n == 0){
        cout<<endl;
        return;
    }
    //recursion
    if (i == 0)
        pattern2(n-1, 0);
    if (i < n){
        cout<<"* ";
        pattern2(n, i+1);
    }
    else
        cout<<endl;
}

/*
* * * *
  * * *
    * *
      *
print this pattern when n = 4 recursively
*/
void pattern3(int n, int i, int j){
    //base case
    if (n == 0) return;
    //print all column of one row
    if(i < n){
        cout<<"* ";
        pattern3(n, i+1, j);
    }
    //changing the row
    else{
        if(i == n)
            cout<<endl;
        if (j > 0){
            cout<<"  ";
            pattern3(n, i+1, j-1);
        }
        else{
            pattern3(n-1, 0, (i-n)+1 );
        }
    }
}


int main()
{
    pattern1(5, 0);
    pattern2(5, 0);
    cout<<endl;
    pattern3(5, 0, 1);
    return 0;
}
