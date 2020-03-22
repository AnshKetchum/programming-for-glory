#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
#define MAXM 15
using namespace std;
typedef long long ll;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

int n,q; 
ll m,a[MAXN];

struct BIT
{
    int size;
    ll bit[MAXN],mod;

    void update(int index, ll val)
    {
        while(index <= n)
        {
            bit[index] = (bit[index] +  (val % mod)) % mod;
            index += (index & -index);
        }
    }

    BIT(ll a [], int n, ll m)
    {
        size = n;
        mod = m;
        for(int i = 1; i <= n; i++)
            update(i, a[i]);
    }

    ll query(int index)
    {
        ll sum = 0; 
        while(index)
        {
            sum += bit[index];
            index -= (index & -index);
        }
        return sum;
    }

    ll range_query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

};

int main()
{
    setIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    BIT bit = BIT(a,n, m);
    cout << bit.range_query(1, n) << endl;

    return 0;
}
