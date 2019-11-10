#include <bits/stdc++.h>
using namespace std;
#define MAX_BITS 5000
#define MAX_AMOUNT_BITS 11

int dp [MAX_BITS][MAX_AMOUNT_BITS],n,k;
bool ans [MAX_BITS];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    if(k == 1)
    {
        cout << "1";
        for(int i = 0; i < n - 1; i++)
            cout << "0";
        cout << endl;
    }
    
    
    
    else 
    {
    dp[0][0] = 1;
    for(int i = 1; i < MAX_BITS; i++)
        for(int j = 0; j < MAX_AMOUNT_BITS; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }

    while(k > 0)
    {
        int i;
        for(i = 0;i < MAX_BITS; i++)
            if(dp[i][k] >= n)
                break;
        ans[MAX_BITS - i] = true;
        n -= dp[i - 1][k];
        k--;
    }

    int i = 0;
    while(!ans[i]) i++;   

    for(; i < MAX_BITS; i++)
        cout << (ans[i]);
    cout << endl;
    }
}
