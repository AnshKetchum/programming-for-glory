#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 1500
#define INF 2e9

typedef pair<int,int> pii;
struct Edge
{
    int edge_count,node, sum;

	Edge(int e, int n, int s)
	{
		edge_count = e;
		node = n;
		sum = s;
	}

};

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,m,c,bonus[MAXN],ans;
vector <int> connections [MAXN];
vector<Edge> optimal_edges;
bool visited[MAXN];

void bfs()
{
	queue <Edge> enque;
	enque.push(Edge(0,1,0));

	while(!enque.empty())
	{
		Edge top = enque.front();
		enque.pop();

		visited[top.node] = true;		
		for(int nn : connections[top.node])
		{
			if(nn == 1)
			{
				optimal_edges.push_back(Edge(top.edge_count + 1,1,top.sum));
				continue;
			}

			else if(!visited[nn])
				enque.push(Edge(top.edge_count + 1, nn, top.sum + bonus[nn]));
		}
	}
}

int f(int x, int S, int X)
{
	int c1 = S * x;
	int c2 = X * x * x;
	return c1 - c2;
}

struct State
{
	int node, time, cost;

	State(int n, int t, int c)
	{
		node = n;
		time = t;
		cost = c;
	}
};

int get_cost(int t)
{
	return c * t * t;
}

int bfs2()
{
	int ret = 0;
	queue <State> enque;
	enque.push(State(1,0,0));

	while(!enque.empty())
	{
		State top = enque.front();
		enque.pop();

		if(top.node == 1)
			ret = max(ret,top.cost - get_cost(top.time + 1));

			for(int x : connections[top.node])
				if(top.cost + bonus[x] - get_cost(top.time + 1) >= 0)
				enque.push(State(x,top.time + 1,top.cost + bonus[x] ));

	}
	return ret;

}

int solve_equation(Edge optimal)
{
	int X = c * (optimal.edge_count * optimal.edge_count);
	int S = optimal.sum;

	int xmax = (S / (2 * X));
	int a1 = f(xmax, S,X);
	int a2 = f(xmax + 1, S, X);
	return max(a1,a2);
}



int main()
{	
	setIO("time");
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++)
		cin >> bonus[i];
	for(int i = 0; i < m; i++)
	{
		int a,b; cin >> a >> b;
		connections[a].push_back(b);
	}

/*	bfs();
	//cout << optimal_edges.size() << endl;

	for(Edge e : optimal_edges)
	{
//		cout << "CYCLE: " << e.sum << " " << e.edge_count << endl;
		ans = max(ans, solve_equation(e));
	}
	cout << ans << endl; */
	cout << bfs2() << endl;
    return 0;
}