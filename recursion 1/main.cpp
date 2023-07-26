#include <iostream>

using namespace std;

int noOfString(int n){
    //base case
    if(n == 1 || n == 2) return n+1;
    //recursion subproblem
    int subproblem = noOfString(n-1);
    int subproblem_1 = noOfString(n-2);
    //self work
    return subproblem+subproblem_1;
}
int main()
{
    cout << noOfString(4);
    return 0;
}
