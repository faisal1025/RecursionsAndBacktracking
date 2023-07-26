#include <iostream>
#include <unordered_set>
using namespace std;

void perm(string str, string osf){
    if (str.size() == 0){
        cout<<osf<<endl;
        return;
    }

    unordered_set<char> s;

    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if (s.count(ch) == 0){
            s.insert(ch);
            string ros = str.substr(0, i)+str.substr(i+1);
            perm(ros, osf+ch);
        }
    }
}

int main()
{
    perm("AAC", "");
    return 0;
}
