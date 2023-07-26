#include <iostream>
#include <string>
using namespace std;

void allPermuation(char arr[], int i, int n, string temp){
    if (i == n){
        cout<<"["+temp+"]"<<endl;
        return;
    }
    allPermuation(arr, i+1, n, temp+arr[i]+" ");
    allPermuation(arr, i+1, n, temp);
}

int main()
{
    int n;
    cin>>n;
    char *arr = new char;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    allPermuation(arr, 0, n, " ");
    return 0;
}
