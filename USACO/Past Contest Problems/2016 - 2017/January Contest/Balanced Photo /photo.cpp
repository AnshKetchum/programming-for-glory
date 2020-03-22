#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll n,a[MAXN],l[MAXN],r[MAXN];
int main()
{
    setIO("bphoto");
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    multiset<int> ms;
    l[1] = 0;
    ms.insert(a[1]);
    for(int i = 2; i <= n; i++)
    {
        l[i] = distance(ms.upper_bound(a[i]), ms.end());
        ms.insert(a[i]);
    }
    ms.clear();

    r[n] = 0;
    ms.insert(a[n]);
    for(int i = n; i > 0; i--)
    {
        r[i] = distance(ms.upper_bound(a[i]), ms.end());
        ms.insert(a[i]);
    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
        if(l[i] > 2 * r[i] || r[i] > 2 * l[i]) 
            ret++;
    cout << ret << endl;
    return 0;
}
