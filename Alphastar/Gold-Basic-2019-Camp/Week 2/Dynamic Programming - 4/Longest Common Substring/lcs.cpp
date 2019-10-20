#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int dp[MAXN][MAXN],ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

     for(int i = 0; i < str1.length(); i++)
        for(int j = 0; j < str2.length(); j++)
        {
            if(str1[i] == str2[j])
            {
                dp[i][j] = 1;
                if(i > 0 && j > 0)
                    dp[i][j] += dp[i - 1][j - 1];
                ans = max(ans,dp[i][j]);
            }

            else
                dp[i][j] = 0;
        }


    cout << ans << endl;
    return 0;
}
