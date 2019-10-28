#include <bits/stdc++.h>
using namespace std;
#define MAX_FRUIT 15000
 
 
int dp_a[MAX_FRUIT],dp_b[MAX_FRUIT],p,a,b,q_a,q_b,options_a[MAX_FRUIT],options_b[MAX_FRUIT],ans;
 
void compute_dp(int dp [MAX_FRUIT], int options [MAX_FRUIT], int cost, int x)
{
    for(int i = 0; i < x; i++)
        for(int j = p; j >= 0; j--)
                dp[j + cost] = max(dp[j + cost], dp[j] + options[i]);
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> p >> a >> b >> q_a >> q_b;
    for(int i = 0; i < q_a; i++)
        cin >> options_a[i];
    for(int i = 0; i < q_b; i++)
        cin >> options_b[i];
    
    compute_dp(dp_a,options_a,a,q_a);
    compute_dp(dp_b,options_b,b,q_b);
    
    
    for(int i = 0; i <= p; i++)
        ans = max(ans,(dp_a[i] + dp_b[p - i]));
    cout << ans << endl;
    return 0;
}
