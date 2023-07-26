/*
Given an array of N size . you have given Q queries in each queries given a number 
x find the number of count of number x in the array.

Constraints:
1 <= N <= 10^5
1 <= a[i] <= 10^7
1 <= Q <= 10^5
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 10^7+10;
int hsh[N];
int main(){
    int n, x, q;
    cin>>n;
    int arr[n];
    /*to perform operation in O(1) we have to pre-compute the counts of all the numbers
    came in array.For this I have used hashing technique by declaring a hsh[N] array of
    size 10^7 that could be the max element of input array. If the max element will be 
    more we can not consider to use much larger array insted of that we will use map.
    */ 
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        hsh[arr[i]]++;
    }
    cin>>q;
    while(q--){
        cin>>x;
        /*while runing a loop in a while loop makes the time complexity O(N^2)
        O(N) + O(Q*N) = O(Q*N) = 10^5 * 10^5 = 10^10 = O(N^2) 
        which doesn't run in 1 sec.
        
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == x)
                count++;
        }
        cout<<count<<endl;
        */
       cout<<hsh[x]<<endl;
    }

}
