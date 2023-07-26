#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void jump1_6(int i, int n, string osf){
    if (i > n)
        return;
    if (i == n){
        cout << osf << endl;
        return;
    }

    jump1_6(i+1, n,osf+"1"+"->");
    jump1_6(i+2, n,osf+"2"+"->");
    jump1_6(i+3, n,osf+"3"+"->");
    jump1_6(i+4, n,osf+"4"+"->");
    jump1_6(i+5, n,osf+"5"+"->");
    jump1_6(i+6, n,osf+"6"+"->");
}
int main()
{
    int n;
    cin>>n;
    jump1_6(0, n, "");
    return 0;
}
