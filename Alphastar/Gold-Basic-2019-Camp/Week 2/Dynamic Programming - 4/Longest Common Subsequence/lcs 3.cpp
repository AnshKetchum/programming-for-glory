#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500

int dp[MAXN][MAXN],extra = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2; cin >> str1 >> str2;


    for(int i = 0; i < str1.length(); i++)
        for(int j = 0; j < str2.length(); j++)
        {
            if(str1[i] == str2[j])
            {   
                dp[i][j] = 1;
                if(i > 0 && j > 0)
                    dp[i][j] += dp[i - 1][j - 1];
            }

            else
            {
                if(i > 0 && j > 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else if(i > 0)
                    dp[i][j] = dp[i - 1][j];
                else if(j > 0)
                    dp[i][j] = dp[i][j - 1];
            }
        
        }
    cout << dp[str1.length() - 1][str2.length() - 1] + extra << endl;
 
    return 0;
}
