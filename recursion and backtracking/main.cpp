#include <iostream>

using namespace std;

int no_of_ways(int n);
int no_of_ways(int n){
    if (n == 1 || n == 2) return n;
    return no_of_ways(n-1) + (n-1)*no_of_ways(n-2);
}

int main()
{
    cout << no_of_ways(4);
    return 0;
}
