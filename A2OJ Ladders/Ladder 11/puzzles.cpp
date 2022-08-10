#include <bits/stdc++.h>
using namespace std;
#define MAXM 100
int n, m, f[MAXM], ans = 1500;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> f[i];
    
    sort(f, f + m);
    for(int i = n; i <= m; i++)
        ans = min(ans, f[i - 1] - f[i - n]);
    cout << ans << endl;
    return 0;
}