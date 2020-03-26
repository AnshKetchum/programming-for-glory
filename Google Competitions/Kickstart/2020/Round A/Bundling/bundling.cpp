#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
using namespace std;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

string strs[MAXN];

int get_pref(int l, int r)
{
    int ret = 0;
    size_t minlen = MAXN;
    for(int i = l; i < r; i++)
        minlen = min(minlen, strs[i].length());
    
    bool out = false;
    for(int i = 0; i < minlen && !out; i++)
    {
        char c = strs[l][i];
        for(int j = l + 1; j < r && !out; j++)
            if(strs[j][i] != c)
                out = true;
        if(!out)
            ret++;
    }
    return ret;
}

void solve(int tc)
{
    int n,k,ans = 0; cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> strs[i];

    sort(strs, strs + n);
    
    for(int i = k; i <= n; i += k)
    {
        ans += get_pref(i - k,i);
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
