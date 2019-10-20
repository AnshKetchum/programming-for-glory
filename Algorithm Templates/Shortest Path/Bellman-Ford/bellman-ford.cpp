#include <bits/stdc++.h>
using namespace std;
#define MAXV 150000
#define INF 100000000 //Set to 10^8, update for larger sums

int e,v,s,en;

struct Edge
{
    int from,to,size;

    Edge(int from, int to, int size)
    {   
        this->from = from;
        this->to = to;
        this->size = size;
    }
};

vector <Edge> connections ;

int bellman_ford(int source, int stop)
{   
    bool visited[MAXV] = {false};
    int cost[MAXV];
    fill(cost, cost + MAXV - 2, INF);
    cost[source] = 0;

    for(int i = 1; i <= v - 1; i++)
        for(Edge a : connections)
            cost[a.to] = min(cost[a.to], (cost[a.from] + a.size));
    return cost[stop];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e >> s >> en;
    for(int i = 1; i <= e; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections.push_back(Edge(a,b,c));
        connections.push_back(Edge(b,a,c));
    }

    cout << "The Shortest Path from Node " << s << " to Node " << en << " is " << bellman_ford(s,en) << endl;
    return 0;
}