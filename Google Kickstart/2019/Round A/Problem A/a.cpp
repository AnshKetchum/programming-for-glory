#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 1e9

int t,sum[MAXN],n,p,ans;
vector <int> a; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        ans = INF; 
        a.clear();
        cin >> n >> p;
        fill(sum, sum + n + 5, 0);
        
        for(int j = 1,b = 0; j <= n; j++) 
            cin >> b, a.push_back(b);
        sort(a.begin(),a.end());
        
        for(int j = 1; j <= n; j++)
            sum[j] = sum[j - 1] + a[j - 1];

        for(int j = p; j <= n; j++)
            ans = min(ans, (a[j - 1] * p - (sum[j] - sum[j - p]) ) );
        
        cout << "Case #" << i << ": " << ans << endl;
    }
    
    return 0;
}
