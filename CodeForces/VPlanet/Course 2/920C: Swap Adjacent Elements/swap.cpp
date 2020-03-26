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


int n,sums[MAXN],a[MAXN];
string ans = "YES";

int query(int l, int r)
{
    return sums[r - 1] - sums[l - 1];
}


int main()
{
    setIO();
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n - 1; i++)
    {
        char c; cin >> c;
        sums[i] = sums[i - 1];
        if(c == '0') ++sums[i];
    }

    for(int i = 1; i <= n && ans == "YES"; i++)
        if(i != a[i] && query(max(i,a[i]), min(i,a[i])))
            ans = "NO";

    cout << ans << endl;
    return 0;
}
