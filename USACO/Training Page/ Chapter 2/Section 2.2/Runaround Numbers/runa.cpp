/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: runround
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBER 11

int valueOf(char c)
{
    return c - '0';
}

bool isRunaround(string str)
{
    bool used [] = {false,false,false,false,false,false,false,false,false,false,false,false};
    int starting = 0,total_used = 0,m = str.length();

    while(total_used < m && !used[valueOf(str[starting])])
    {
        used[valueOf(str[starting])] = true;
        starting += valueOf(str[starting]);
        starting %= m;
        total_used++;
    }
    return total_used == m && starting == 0;
}


int main()
{
    ifstream cin("runround.in");
    ofstream cout("runround.out");

    int m; cin >> m;
    while(!isRunaround(to_string(++m)));
    cout << m << endl;
    return 0;
}
