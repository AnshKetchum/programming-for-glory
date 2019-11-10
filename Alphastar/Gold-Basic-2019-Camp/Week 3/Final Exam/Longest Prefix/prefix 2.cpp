#include <bits/stdc++.h>
using namespace std;
#define MAX_PRIMITIVES 205
#define MAX_STRING 400005

vector <string> primitives;
string str;
bool dp [MAX_STRING];

bool possible(int startIndex, string compareTo)
{
    return str.substr(startIndex,compareTo.length()) == compareTo;
}
int main()
{
    string s = "";
    str = "";

    while(s != ".")
    {
        cin >> s;
        if(s != ".")
            primitives.push_back(s);
    }

    s = "";

    while(cin >> s)
        str += s;
        
    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 0; j < primitives.size(); j++)
        {
            if(i + primitives[j].length() > str.length() || !possible(i,primitives[j]))
                continue;

            if(i == 0 && !dp[i])
                dp[i] = true;

            if(dp[i])
                dp[i + primitives[j].length()] = true;
        }
    }

    int ans = -1;
    for(int i = 0; i <= MAX_STRING; i++)
        if(dp[i])
            ans = i;

    cout << (ans == -1 ? 0 : ans) << endl;
    return 0;
}
