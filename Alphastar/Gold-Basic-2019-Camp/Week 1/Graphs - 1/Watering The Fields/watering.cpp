#include <bits/stdc++.h>
#define MAXN 4000
#define INF 10000000000
using namespace std;

typedef long long ll;
ll n,c, cost[MAXN];
pair<ll,ll> coords [MAXN];
bool visited[MAXN];

ll getDist(ll x1, ll y1, ll x2, ll y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int get_mst()
{
    int ans = 0,to_visit = 0,min_node = -1;
    visited[0] = true;
    cost[0] = 0;

    while(to_visit != -1)
    {
        min_node = 2999;
        for(int i = 0; i < n; i++)
        {
            ll dist = getDist(coords[i].first,coords[i].second,coords[to_visit].first,coords[to_visit].second);

            if(i == to_visit)
                continue;
            if(cost[i] > dist && dist >= c && !visited[i])
                 cost[i] = dist;
        }

        for(int i = 0; i < n; i++)
            if(!visited[i] && cost[i] < cost[min_node])
                min_node = i;

        visited[min_node] = true;
        if(min_node == 2999)
            min_node = -1;
        to_visit = min_node;
    }

    for(int i = 0; i < n; i++)
    {
        ans += cost[i];
        if(cost[i] == INF)
        {
            ans = -1;
            break;
        }
    }


    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;

    cost[2999] = INF;

    for(int i = 0; i < MAXN; i++)
        cost[i] = INF;

    for(int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second;

    cout << get_mst() << endl;
    return 0;
}
