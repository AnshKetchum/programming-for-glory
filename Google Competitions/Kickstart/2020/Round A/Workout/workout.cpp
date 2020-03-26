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

int times[MAXN],diff[MAXN],n,k;

bool pos(int tval)
{
    int div = 0;
    for(int i = 1; i <= n - 1; i++)
        if(tval <= diff[i])
            div += (ceil(diff[i] / (double)tval) - 1);
    return (div <= k);
}

int bin_search(int l, int r)
{
    while(l < r)
    {
        if(r - l == 1)
        {
            if(pos(l))
                return l;
            return r;
        }

        int mid = (l + r) >> 1;

        if(pos(mid))
            r = mid;
        else 
            l = mid + 1;

    }
    return l;
}


void solve(int tc)
{
    fill(times, times + MAXN - 1,0);
    fill(diff, diff + MAXN - 1,0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> times[i];

    int mxdiff = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        diff[i] = times[i + 1] - times[i];
        mxdiff = max(mxdiff, diff[i]);
    }

    int ans = bin_search(1, mxdiff);
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

