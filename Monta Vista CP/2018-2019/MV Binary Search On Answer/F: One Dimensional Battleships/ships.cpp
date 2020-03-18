//https://codeforces.com/group/bO58xxnmVp/contest/239264/problem/F
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

int n,k,a,m,moves[MAXN];
bool sim[MAXN];

bool pos(int mval)
{
    fill(sim, sim + n + 5, true);
    for(int i = 0; i < mval; i++)
        sim[moves[i]] = false;
    
    int cnt = 0,placed = 0;
    for(int i = 1; i <= n; i++)
    {
        placed = (sim[i] ? placed + 1 : 0);

        if(placed == a)
        {
            cnt++;
            i++;
        }
        placed %= a;
    }

    return (cnt >= k);
}

int bin_search(int l, int r)
{
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(r - l == 1)
        {
            if(!pos(l))
                return l;
            return r;
        }
        if(!pos(mid))
            r = mid;
        else
            l = mid + 1;       
    }
    return l;
}

int main()
{
    setIO();
    cin >> n >> k >> a >> m;
    for(int i = 0; i < m; i++)
        cin >> moves[i];

    int ans  = bin_search(0, m + 1);
    cout << (pos(ans) ? -1 : ans) << endl;   
    return 0;
}
