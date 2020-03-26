#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll n,m,sums[MAXN];
pll bales[MAXN];
int main()
{
    setIO("hayfeast");
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> bales[i].first >> bales[i].second;
        sums[i] = bales[i].first;
    }



    return 0;
}
