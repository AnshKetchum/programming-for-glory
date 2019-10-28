#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define MAXM 150

int n,m,x,ans = INF,dp[MAXM][MAXM];
string input;

int count_pal(int l, int r)
{
    string pal = input.substr(l, r - l );

    int ret = 0;
    for(int i = 0; i < pal.length() / 2; i++)
        if(pal[pal.length() - i - 1] != input[i])
            ret++;
    return ret;    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> x >> input;
    for(int i = 0; i < MAXM; i++)
        fill(dp[i],dp[i] + MAXM - 1, INF);

    dp[0][0] = 0; //Base Case
    for(int i = 0; i < n; i++) //Compute DP
    {
        dp[i][0] = count_pal(0,i + 1);
        for(int k = 1; k < m; k++)
            for(int j = i; j >= 0; j--)
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + count_pal(j,i));
    } 

    if(dp[n - 1][m - 1] > x)
        cout << "NO" << endl;
    else
        cout << "YES\n" << dp[n - 1][m - 1] << endl;  
    
    
    return 0;
}