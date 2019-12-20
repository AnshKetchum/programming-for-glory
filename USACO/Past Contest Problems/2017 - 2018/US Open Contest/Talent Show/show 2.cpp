#include <bits/stdc++.h>
using namespace std;
#define MAXN 550

typedef pair<int,int> pii;
int n,w,num,denom;
pii vals[MAXN];

bool comp( pii a,  pii b)
{
        double ra = (double)a.second / a.first;
        double rb = (double)b.second / b.first;
        return ra > rb;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for(int i = 0; i < n; i++)
        cin >> vals[i].second >> vals[i].first;

    sort(vals, vals + n,comp);

    for(int i = 0; i < n && (denom < num || vals[i].first > vals[i].second ) ; i++)
    {
        num += vals[i].first;
        denom += vals[i].second;
    }

    int ans = 1000 * ((double)num / denom);
    cout << ans << endl;
    return 0;
}