#include <bits/stdc++.h>
#define MAXN 125000
#define x first
#define y second
#define INF 1e9
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;
typedef vector <ll> vi;

void setIO(string name) //Taken from USACO Legend Mr. Benjamin Qi (Benq)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll n,cost[MAXN];
pii fences[MAXN];
map<ll, vi> xcon, ycon;
bool visited[MAXN];

int dijkstra()
{
    fill(cost, cost + n + 5, INF);
    cost[1] = 0;

    priority_queue<pii> best_edges;
    best_edges.push(pii(0,1));

    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;

        visited[top.second] = true; 

        for(int i : xcon[fences[top.second].x])
            if(!visited[i])
            {
                ll c  = cost[top.second] + 1;
                cost[i] = min(cost[i], c);
                best_edges.push(pii(-c,i));
            }
        for(int i : ycon[fences[top.second].y])
            if(!visited[i])
            {
                ll c  = cost[top.second] + 1;
                cost[i] = min(cost[i], c);
                best_edges.push(pii(-c,i));
            }
    }
    
    return (cost[n + 1] == INF ? -1 : cost[n + 1] - 1);
}

void read_coord(ll i)
{
    cin >> fences[i].x >> fences[i].y;
    xcon[fences[i].x].push_back(i);
    ycon[fences[i].y].push_back(i);
}

int main()
{
    setIO("lasers");
    cin >> n; 

    read_coord(1);
    read_coord(n + 1);
    //Add the ending node as a point
    for(ll i = 2; i <= n; i++)
        read_coord(i);

    cout << dijkstra() << endl;
    return 0;
}
