#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define first f
#define second s
#define MAXP 550000
#define INF 1e9


struct Edge
{
	int node, cost,x,y,index;
	bool spring;

	Edge(int n, int c, int xc, int yc, bool s)
	{
		node = n;
		cost = c;
		x = xc;
		y = yc;
		spring = s;
	}

};

struct comp_edge
{ // defining the comparemarks structure
   bool operator()(Edge const& s1, Edge const& s2)
   //overloading the operators of the student structure
   {
      return s1.cost < s2.cost;
   }
};

int manhattan_dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
//	freopen((name+".out").c_str(),"w",stdout);
}

int n,p, cost[MAXP];
bool visited[MAXP];
pii from[MAXP],to[MAXP];
vector<pii> points;

void dijkstra()
{
	cost = INF;
   	priority_queue< Edge, vector<Edge>, comp_edge> best_edges;
	best_edges.push(Edge(0,0,0,0,0,false));

	while(!best_edges.empty())
	{
		Edge top = best_edges.top();
		best_edges.pop();

		if(visited[top.node])
			continue;
		visited[top.node] = true;

		if(top.spring)
		{
			cost[top.node + 1] = min(cost[top.node + 1], cost[top.node])
			best_edges.push(Edge(top.node + 1, cost[top.node],))
		}

		for(pii x : points)
	}	


}


int main()
{		
	setIO("boards");
	cin >> n >> p;

	points.push_back(pii(0,0));
	for(int i = 0; i < p; i++)
	{
		cin >> from[i].f >> from[i].s >> to[i].f >> to[i].s;
		points.push_back(from[i]);
		points.push_back(to[i]);
	}

	points.push_back(pii(n,n));
	dijkstra();
	
	cout << cost << endl;
    return 0;
}