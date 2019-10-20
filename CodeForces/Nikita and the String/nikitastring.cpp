//pray ::geniosity::
#include <bits/stdc++.h>
using namespace std;
#define MAX_STRING 5005

string str = "";

int add(int i, char c)
{
    if(str[i] == c)
        return 1;
    return 0;
}

int dp[MAX_STRING][3]; //Index, and current Stage
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;

    dp[0][0] = add(0,'a');
    dp[0][1] = add(0,'b');

    for(int i = 1; i < str.length(); i++)
    {
        for(int j = 0; j < i; j++)//Computing best option at first stage
        {
            dp[i][0] = max(dp[i][0],dp[j][0] + add(i,'a'));
            dp[i][1] = max(max(dp[i][1],dp[i][0] + add(i,'b')), dp[j][1] + add(i,'b')); 
            dp[i][2] = max(dp[i][2], max(dp[j][1] + add(i,'a'),dp[j][2] + add(i,'a')));
        }
    }

    int ans = max(dp[str.length() - 1][0],max(dp[str.length() - 1][1],dp[str.length() - 1][2]));

    cout << ans << endl;
    return 0;
}