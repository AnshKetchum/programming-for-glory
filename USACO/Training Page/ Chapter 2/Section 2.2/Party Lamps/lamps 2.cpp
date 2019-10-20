/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: lamps
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 150

int n,c,a;
vector <int> on,off;
set <string> ans;

string applyOp(int op, string str)
{
    switch(op)
    {
        case 0:
            for(int i = 0; i < str.length(); i++)
                str[i] = ((str[i] == '1') ? '0' : '1');
            break;
        case 1:
            for(int i = 1; i < str.length(); i+= 2)
                str[i] = ((str[i] == '1') ? '0' : '1');
            break;
        case 2:
            for(int i = 0; i < str.length(); i+= 2)
                str[i] = ((str[i] == '1') ? '0' : '1');
            break;
        case 3:
            for(int i = 0;i < str.length(); i += 3)
                str[i] = ((str[i] == '1') ? '0' : '1');
            break;
    }
    return str;
}

bool valid(string str)
{
    for(int i : on)
        if(str[i] == '0')
            return false;
    for(int i : off)
        if(str[i] == '1')
            return false;
    return true;
}

void permute(int x, string str,int sum)
{
    if(x >= 4)
    {
        if( (c - sum) % 2  == 0 && c >= sum && valid(str))
                ans.insert(str);
        return;
    }

    string temp = applyOp(x,str);
    permute(x + 1,temp, sum + 1);
    permute(x + 1,str,  sum );
}


int main()
{
    ifstream cin("lamps.in");
    ofstream cout("lamps.out");

    cin >> n >> c;
    while(a != -1)
    {
        cin >> a;
        if(a != -1)
            on.push_back(a - 1);
    }

    a = 0;
    while(a != -1)
    {
        cin >> a;
        if(a != -1)
            off.push_back(a - 1);
    }

    string s = "";
    for(int i = 0; i < n; i++)
        s += '1';


    permute(0,s,0);

    if(ans.size() == 0)
        cout << "IMPOSSIBLE" << endl;

    else
    {
        for(string s : ans)
            cout << s << endl;
    }
    return 0;
}
