#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 250000
using namespace std;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

int houses[MAXN];
void solve(int tc)
{
    int ans = 0,n = 0, b = 0; 
    cin >> n >> b;
    for(int i = 0; i < n; i++)
        cin >> houses[i];
    sort(houses, houses + n);

    for(int i = 0; i < n; i++)
    {
        if(b - houses[i] < 0)
            break;
        ans++;
        b -= houses[i];
    }

    cout << "Case #" << tc << ": " << ans << endl;
}


int main()
{
    setIO();
    int t; cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);

    return 0;
}
