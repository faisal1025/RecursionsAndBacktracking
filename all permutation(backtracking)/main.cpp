#include <iostream>

using namespace std;

void all_permutation(string str, int j)
{
    //base case
    if (j == str.size()){
        cout<<str<<endl;
        return;
    }
    for(int i = j; i < str.size(); i++){
        swap(str[j], str[i]);
        all_permutation(str, j+1);
        swap(str[j], str[i]);
    }

}
int main()
{
    string s;
    cin>>s;
    cout<<"all permutations are:"<<endl;
    all_permutation(s, 0);
    return 0;
}
