#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 100000000000000

typedef long long ll;
ll n,d,chocolate[MAXN],day[MAXN];
bool pos(ll happiness_value)
{
    fill(day, day + n + 1, d);

    ll sum = 0;
    for(int i = 0,day_count = 1,x = 0; i < n && day_count <= d; i++)
    {
        if(sum < happiness_value)
        {
            sum += chocolate[i];
            day[i] = day_count;

        }
        while(sum >= happiness_value && day_count < d)
        {
            sum /= 2;
            day_count++;
        }

    }

    return sum >= happiness_value;
}


ll binary_search(ll l, ll r)
{
    if(l == r)
        return l;

    if(r - l == 1)
    {
        int x = pos(l);
        if(!x)
            pos(r);
        return (x ? l : r);
    }
    ll mid = (l + r) / 2;

    if(!pos(mid))
        return binary_search(l, mid);

    return binary_search(mid, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> chocolate[i];

    cout << binary_search(0,INF) << endl;
    for(int i = 0; i < n; i++)
        cout << day[i] << endl;
    return 0;
}
