#include <bits/stdc++.h>
using namespace std;
#define MAXN 550000

typedef long long ll;
ll n,k,a[MAXN],median,ans;

bool pos(ll median_value)
{
    ll diff = 0;
    for(int i = n / 2; i < n; i++)
        if(median_value - a[i] > 0)
            diff += (median_value - a[i]);
    return diff <= k;
}

int get_best(ll l, ll r)
{
    if(l == r)
        return l;

    if(r - l == 1)
    {
        if(pos(r))
            return r;
        return l;
    }

    ll mid = (l + r) / 2;
    if(pos(mid))
        return get_best(mid,r);
    return get_best(l,mid - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << get_best(0, 100000000000) << endl;
}
