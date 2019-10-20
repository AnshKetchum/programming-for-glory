#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define INF 1000000000
#define int long long

int dp[MAXN][MAXN];
string s1,s2;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s1 >> s2;

    for(int i = 1; i <= s1.length(); i++) dp[i][0] = i;
    for(int i = 1; i <= s2.length(); i++) dp[0][i] = i;
    dp[0][0] = 0;
    
    for(int i = 1; i <= s1.length(); i++)
        for(int j = 1; j <= s2.length(); j++)
        {

            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
            
            int insdel = min(dp[i - 1][j],dp[i][j - 1]);
            dp[i][j] = min(dp[i][j],insdel + 1); //Insertion Case
        }

    cout << dp[s1.length()][s2.length()] << endl;
    return 0;
}
