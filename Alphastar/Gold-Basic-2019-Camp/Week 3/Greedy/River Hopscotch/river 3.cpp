#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define int long long
#define INF 1000000000000

typedef pair<int,int> pii;
int l,n,m,rocks[MAXN];
bool pos(int mVal)
{
    int safe = 0,removed = 0;
    for(int i = 0; i < n; i++)
    {
        if(rocks[i] - safe < mVal)
            removed++;
        else
            safe = rocks[i];
    }

    return removed <= m;
}

int binSearch(int lo, int hi)
{
    if(lo == hi)
        return lo;
    if(hi - lo == 1)
    {
        if(pos(lo))
            return lo;
        return hi;
    }

    int mid = (lo + hi) / 2;
    if(!pos(mid))
        return binSearch(lo,mid);
    else return binSearch(mid,hi);
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> l >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> rocks[i];
    sort(rocks, rocks + n);
    cout << (n == 0 ? l : binSearch(0,INF)) << endl;
    return 0;
}
