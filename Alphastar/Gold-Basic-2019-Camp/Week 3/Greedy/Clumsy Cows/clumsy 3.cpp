#include <bits/stdc++.h>
using namespace std;

int open,swapped;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
            open++;
        else open--;
        if(open == -1)
        {
            swapped++;
            open = 1;
        }
    }
    cout << open / 2 + swapped << endl;
    return 0;
}
