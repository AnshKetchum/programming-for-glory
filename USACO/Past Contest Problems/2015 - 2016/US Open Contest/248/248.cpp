#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
#define NEG -1
#define PA(x) for(int i = 0; i < n; i++) cout << x[i] << " "; cout << endl;

int n,dp[MAXN],v[MAXN],ans;

void compute(int ind)
{
    dp[ind] = v[ind];
    
    int i = ind;
    while( (dp[ind] == dp[i - 1] || (dp[ind] == v[i - 1]) && i > 0))
    {
        dp[ind]++;
        i--;
    }
    cout << "DP END OF " << ind << ": " << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("248.in");
    //ofstream cout("248.out");
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> v[i];
    compute(0);    
    for(int i = 1; i < n; i++)
    {
        compute(i);
        ans = max(ans,dp[i]);
    }

    for(int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << endl;

    cout << max(ans,dp[0]) << endl;
    return 0;
}
