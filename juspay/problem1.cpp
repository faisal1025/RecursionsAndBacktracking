/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
using namespace std;

bool canReach(vector<pair<int, int> > edge, int a, int b){
	for(int i = 0; i < edge.size(); i++){
		if(edge[i].first == a ){
			if(edge[i].second == b)
				return true;
			else
				return canReach(edge, edge[i].second, b);
		}
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	vector<pair<int, int> > edge;
	for(int i = 0; i < k; i++){
        int val1, val2;
        cin>>val1>>val2;
		edge.push_back({val1, val2});
	}
	int a, b;
	cin>>a>>b;
	if(canReach(edge, a, b)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
