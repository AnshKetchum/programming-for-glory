#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

typedef long long ll;
const ll MOD = 1000007;
ll n,k,gems[MAXN],ans = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> gems[i];
    sort(gems, gems + n);
        
    ll divider = n / k;
    for(int i = divider; i < n; i += divider)
    {
        ans *=  (gems[i] - gems[i - 1] - 1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}