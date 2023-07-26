/*
Given a no t no of test cases . In each line of test cases given a no n calculate 
factorial of n.

Constraints:
1 <= T <= 10^5
1 <= n <= 10^5
*/
#include<iostream>
#define ll long int
using namespace std;

const int N  = 10^5;

int main(){
    ll t;
    cin>>t;
    /*For computing factorial of n in O(1) we should pre-compute factorials till N first 
    and store it in an array fact[N] and then print the fact[n] n given by user
    in our main loop t in O(1).
    Time complexity = O(T) + O(N) = 10^5 + 10^5 = overall TC = 10^5 O(N).
    */
    ll fact[N];
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = fact[i-1]*i;
    }
    while(t--){
        ll n;
        cin>>n;
        /*
        ll fact = 1;
        Time complexity = O(T*N) = 10^5 * 10^5 = 10^10 which doesn't run in 1 sec
        for(int i = 2; i <= n; i++){
            fact = fact*i;
        }
        */
        cout<<fact[n]<<endl;
    }
}