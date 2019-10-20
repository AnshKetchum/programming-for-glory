#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500
#define INF 1000000000
#define PRINTCOORD(i) cout << coords[i].first << " " << coords[i].second << endl;
typedef pair<int,int> pii;
typedef pair<double,int> pid;
pii coords [MAXN];

double get_dist(int i, int j)
{   
    pii a = coords[i];
    pii b = coords[j];
    double dx = a.first - b.first,dy = a.second - b.second;
    return abs(sqrt(dx * dx + dy * dy));
}


int n,w;
bool visited[MAXN];
double m;
double connections[MAXN][MAXN],cost[MAXN];


void dijkstra()
{
    fill(cost, cost + n + 5, INF);
    cost[1] = 0;
    priority_queue <pid> enque;
    enque.push(pid(0,1));

    while(!enque.empty())
    {
        pid top = enque.top();

        enque.pop();

        if(visited[top.second])  
            continue;

        visited[top.second] = true;

        for(int i = 1; i <= n; i++)
            if(!visited[i] && connections[top.second][i] <= m)
            {
                double c = abs(top.first) + connections[top.second][i];
             
                cost[i] = min(cost[i],c);
                enque.push(pid(-c,i));
            }
     } 

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ifstream cin("failure.in");

    cin >> n >> w >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            connections[i][j] = INF;

    for(int i = 1; i <= n; i++)
        cin >> coords[i].first >> coords[i].second;

    for(int i = 0; i < w; i++) 
    {
        int a,b; cin >> a >> b;
        connections[a][b] = connections[b][a] = 0;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            connections[i][j] = min(connections[i][j], get_dist(i,j));


    dijkstra();


    cout << (cost[n] == INF  ? -1 : ((int)(cost[n] * 1000))) << endl;    
    return 0;
}
