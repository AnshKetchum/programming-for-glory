#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define NEGINF -2e9
#define MAXN 350000
typedef long long ll;
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

ll n,a[MAXN],dp[MAXN][3],ans; // 0 -> Not used 1, 1 for used
int main()
{
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    //There will always be a maximum of 1 for a size 1 element
    dp[1][0] = dp[1][2] = 1; dp[1][1] = NEGINF;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = (a[i] > a[i - 1] ? dp[i - 1][0] + 1 : 1);

        if(i > 2)
        {
            if(a[i] > a[i - 2])
                dp[i][1] = dp[i - 2][0] + 1;
            else
                dp[i][1] = 1;
        }
        else
            dp[i][1] = NEGINF;

        dp[i][2] = max(dp[i][1],dp[i][0]);
        if(a[i] > a[i - 1])
            dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
        
    }
    
    for(int i = 1; i <= n; i++) 
        ans = max(ans, dp[i][2]);
    cout << ans << endl;
    return 0;   
}