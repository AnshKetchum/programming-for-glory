#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define INF 2e10
#define MAXN 250000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n,ans,tree[MAXN * 5];
priority_queue <pii> pq;

struct BIT
{
    BIT() {}
    void update(int i)
    {
        for(; i <= n; i += (i & -i))
            tree[i]++;
    }

    int query(int i)
    {
        int ans = 0;
        for(; i; i -= (i & -i))
            ans += tree[i];
        return ans;
    }

    int range_query(int l, int r)
    {
        if(r < l)
            return 0;
        return query(r) - query(l - 1);
    }
};

int main()
{
    setIO("bphoto");
    cin >> n;
    for(int i = 1, a; i <= n; i++)
    {
        cin >> a;
        pq.push(pii(a,i));
    }

    BIT bit = BIT();

    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();

        int leftGreater = bit.range_query(1, top.second - 1);
        int rightGreater = bit.range_query(top.second + 1, n);

        if(rightGreater > 2 * leftGreater || leftGreater > 2 * rightGreater)
        {
            //cout << top.first << " is unbalanced: " << leftGreater << " " << rightGreater << " " << endl;
            ans++;
        }
        bit.update(top.second);
    }
    cout << ans << endl; 
    return 0;
}
