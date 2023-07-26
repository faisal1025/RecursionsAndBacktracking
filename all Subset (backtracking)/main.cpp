#include <iostream>
#include <vector>
using namespace std;

void all_Subset(int i, int n, char s[], vector<char> &osf){
    if (i == n){
        cout<<"[";
        for(int j = 0; j < osf.size(); j++)
            cout<<" "<<osf[j]<<" ";
        cout<<"]";
        cout<<endl;
        return;
    }
    osf.push_back(s[i]);
    all_Subset(i+1, n, s, osf);
    osf.pop_back();
    all_Subset(i+1, n, s, osf);
}

int main()
{
    vector<char> osf;
    int n;
    cin>>n;
    char *s = new char;
    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    all_Subset(0, n, s, osf);
    return 0;
}
