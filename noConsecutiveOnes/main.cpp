#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void noConsecutiveOnes(int n, int i, string temp){
    if (i == n){
        cout<<"[ "<<temp<<" ]"<<endl;
        return;
    }
    noConsecutiveOnes(n, i+1, temp+"0");
    if (temp[i-1] != '1'){
        noConsecutiveOnes(n, i+1, temp+"1");

    }
}

int main()
{
    int n;
    cin>>n;
    noConsecutiveOnes(n, 0, "");
    return 0;
}
