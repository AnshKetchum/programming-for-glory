#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

int dp[2][MAXN],ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2; cin >> str1 >> str2;

    for(int i = 0; i < str1.length(); i++)
    {
        for(int j = 0; j < str2.length(); j++)
        {
            if(str1[i] == str2[j])
            {   
                dp[1][j] = 1;
                if(i > 0 && j > 0)
                    dp[1][j] += dp[0][j - 1];
                ans = max(ans,dp[1][j]);
            }

            else
            {
                if(i > 0 && j > 0)
                    dp[1][j] = max(dp[0][j], dp[1][j - 1]);
                else if(i > 0)
                    dp[1][j] = dp[0][j];
                else if(j > 0)
                    dp[1][j] = dp[1][j - 1];
            }
        }
        for(int j = 0; j < str2.length(); j++)
        {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
        }
    }        
    cout << ans  << endl;
 
    return 0;
}
