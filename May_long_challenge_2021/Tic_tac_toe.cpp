#include <bits/stdc++.h>
using namespace std;

void count(string line, int &x, int &o, int &_)
{
    for (int i = 0; i < 3; i++)
    {
        if (line[i] == 'X')
        {
            x++;
        }
        else if (line[i] == 'O')
        {
            o++;
        }
        else if (line[i] == '_')
        {
            _++;
        }
    }
}

int win(string line1, string line2, string line3, int x, int o)
{
    if (x - o == 1)
    {
        if ((line1 == "OOO") || (line2 == "OOO") || (line3 == "OOO") || (line1[0] == 'O' and line2[0] == 'O' and line3[0] == 'O') ||
                  (line1[1] == 'O' and line2[1] == 'O' and line3[1] == 'O') || (line1[2] == 'O' and line2[2] == 'O' and line3[2] == 'O') ||
                   (line1[0] == 'O' and line2[1] == 'O' and line3[2] == 'O') || (line1[2] == 'O' and line2[1] == 'O' and line3[0] == 'O'))
         {
            return 3;
        }
        else if ((line1 == "XXX" || line2 == "XXX" || line3 == "XXX") and (line1 == "OOO" || line2 == "OOO" || line3 == "OOO"))
        {
            return 3;
        }
        else if ((line1[0] == 'X' and line2[0] == 'X' and line3[0] == 'X' || line1[1] == 'X' and line2[1] == 'X' and line3[1] == 'X' || line1[2] == 'X' and line2[2] == 'X' and line3[2] == 'X') and (line1[0] == 'O' and line2[0] == 'O' and line3[0] == 'O' ||
                                                                                                                                                                                                      line1[1] == 'O' and line2[1] == 'O' and line3[1] == 'O' || line1[2] == 'O' and line2[2] == 'O' and line3[2] == 'O'))
        {
            return 3;
        }
        else if ((line1 == "XXX") || (line2 == "XXX") || (line3 == "XXX") || (line1[0] == 'X' and line2[0] == 'X' and line3[0] == 'X') || (line1[1] == 'X' and line2[1] == 'X' and line3[1] == 'X') || (line1[2] == 'X' and line2[2] == 'X' and line3[2] == 'X') || (line1[0] == 'X' and line2[1] == 'X' and line3[2] == 'X') || (line1[2] == 'X' and line2[1] == 'X' and line3[0] == 'X'))
        {
            return 1;
        }
        
    }
    if (x == o)
    {
        if ((line1 == "XXX") || (line2 == "XXX") || (line3 == "XXX") || (line1[0] == 'X' and line2[0] == 'X' and line3[0] == 'X') || (line1[1] == 'X' and line2[1] == 'X' and line3[1] == 'X') || (line1[2] == 'X' and line2[2] == 'X' and line3[2] == 'X') || (line1[0] == 'X' and line2[1] == 'X' and line3[2] == 'X') || (line1[2] == 'X' and line2[1] == 'X' and line3[0] == 'X'))
        {
            return 3;
        }
        else if ((line1 == "XXX" || line2 == "XXX" || line3 == "XXX") and (line1 == "OOO" || line2 == "OOO" || line3 == "OOO"))
        {
            return 3;
        }
        else if ((line1[0] == 'X' and line2[0] == 'X' and line3[0] == 'X' || line1[1] == 'X' and line2[1] == 'X' and line3[1] == 'X' || line1[2] == 'X' and line2[2] == 'X' and line3[2] == 'X') and (line1[0] == 'O' and line2[0] == 'O' and line3[0] == 'O' ||
                                                                                                                                                                                                      line1[1] == 'O' and line2[1] == 'O' and line3[1] == 'O' || line1[2] == 'O' and line2[2] == 'O' and line3[2] == 'O'))
        {
            return 3;
        }
        else if ((line1 == "OOO") || (line2 == "OOO") || (line3 == "OOO") || (line1[0] == 'O' and line2[0] == 'O' and line3[0] == 'O') || (line1[1] == 'O' and line2[1] == 'O' and line3[1] == 'O') || (line1[2] == 'O' and line2[2] == 'O' and line3[2] == 'O') || (line1[0] == 'O' and line2[1] == 'O' and line3[2] == 'O') || (line1[2] == 'O' and line2[1] == 'O' and line3[0] == 'O'))
        {
            return 1;
        }
    }
    if(x == 5 and o == 4)
        return 1;
    return 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        string line1;
        string line2;
        string line3;
        cin >> line1 >> line2 >> line3;
        if (line1.find('_') == -1 && line2.find('_') == -1 && line3.find('_') == -1)
        {
            int x = 0, o = 0, _ = 0;
            count(line1, x, o, _);
            count(line2, x, o, _);
            count(line3, x, o, _);
            if (x == 5 && o == 4)
            {
                ans = win(line1, line2, line3, x, o);
            }
            else
            {
                ans = 3;
            }
        }
        else
        {
            int x = 0, o = 0, _ = 0;
            count(line1, x, o, _);
            count(line2, x, o, _);
            count(line3, x, o, _);
            if (_ % 2 == 0)
            {
                if (x - o == 1)
                {
                    ans = win(line1, line2, line3, x, o);
                }
                else
                {
                    ans = 3;
                }
            }
            else
            {
                if (x == o)
                {
                    ans = win(line1, line2, line3, x, o);
                }
                else
                {
                    ans = 3;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}