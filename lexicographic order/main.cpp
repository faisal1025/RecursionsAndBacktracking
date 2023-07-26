#include <iostream>

using namespace std;

void lexicoSeries(int i, int n){
    if(i > n) return;
    cout<<i<<endl;
    for(int j = (i == 0)? 1 : 0; j < 10; j++){
        lexicoSeries(10*i+j, n);
        /*
        i = (10*0)+1 = 1
        i = (10*1)+0 = 10
        i = (10*10)+0 = 100
        */
    }
}
int main()
{
    int n;
    cin >> n;
    lexicoSeries(0, n);
    return 0;
}
