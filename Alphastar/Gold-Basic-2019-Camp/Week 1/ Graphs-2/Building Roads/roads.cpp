#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500
#define INF 100000000
typedef long double ld;
typedef pair<ld,ld> pii;


ld getDist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int n,m;
ld cost [MAXN],dist[MAXN][MAXN];
bool visited [MAXN];
pii coords [MAXN];
double get_mst()
{
    ld ans = 0 ;
    int to_visit = 0,min_node = 1499;

    for(int i = 0;i < n; i++)
        cost[i] = INF;
    cost[min_node] = INF;
    visited[0] = true;
    cost[0] = 0;

    while(to_visit != -1)
    {
        min_node = 1499;
        for(int i = 0; i < n; i++)
        {
            if(i == to_visit)
                continue;
            if(cost[i] > dist[to_visit][i] && !visited[i])
                cost[i] = dist[to_visit][i];
        }

        for(int i = 0; i < n; i++)
            if(!visited[i] && cost[i] < cost[min_node])
                min_node = i;

        visited[min_node] = true;
        if(min_node == 1499)
            min_node = -1;
        to_visit = min_node;
    }

    for(int i = 0; i < n; i++)
        ans += cost[i];
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                dist[i][j] = getDist(coords[i].first,coords[i].second,coords[j].first,coords[j].second);

    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        a--;
        b--;
        dist[a][b] = 0;
        dist[b][a] = 0;
    }

    cout << fixed << setprecision(2) << get_mst() << endl; //Answer is to two decimal places 
    return 0;
}

