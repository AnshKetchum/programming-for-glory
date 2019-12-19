#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000
#define MAXN 10500
#define BREAKOUTPUT for(int i = 0; i < 100; i++) cout << "*";
#define NEWLINE cout << "\n\n\n";
#define BREAKDEBUG BREAKOUTPUT NEWLINE

typedef long long ll;
typedef pair<ll,ll> pll;


ll cost [MAXN],n,m,t,cows[MAXN],cowsOnPath[MAXN],from [MAXN],ans;
vector <pll> connections [MAXN];
bool vis[MAXN] = {false};

void printArrs(ll array [], int start, int ending, string name)
{
    cout << "Printing: " << name << " ";
    for(int i = start; i <= ending; i++)
        cout << array[i] << " ";
    cout << endl;
}


void dijkstra() //Finding best time for 1 cow
{
    bool visited [MAXN] = {false};
    fill(cost, cost + MAXN - 1, INF);
    cost[1] = 0; //Set final node to zero 

    priority_queue <pll> best_edge;
    best_edge.push(pll(0,1));

    while (!best_edge.empty())
    {
        pll top = best_edge.top();
        best_edge.pop(); //Taking the first node

        if(visited[top.second]) //Have we visited the current node?
            continue;
        visited[top.second] = true; 


        for(pll x : connections[top.second]) //Look through the connections the node has
            if(!visited[x.second]) 
            {
                ll c = cost[top.second] + x.first;

                if(c < cost[x.second])
                {
                    cost[x.second] = c;
                    from[x.second] = top.second;
                    best_edge.push(pll( -c, x.second));
                }
                else if(c == cost[x.second] && top.second < from[x.second])
                {
                    from[x.second] = top.second;
                    best_edge.push(pll( -c, x.second));
                }
            }
        cout << endl;
    }
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

   
   ifstream cin("shortcut.in");
   //ofstream cout("shortcut.out");
   

    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
        cin >> cows[i];
    for(int i = 0; i < m; i++)
    {
        int a,b,t; cin >> a >> b >> t;
        connections[a].push_back(pll(t,b));
        connections[b].push_back(pll(t,a));
    }

    fill(from, from + MAXN - 1, INF);


    dijkstra(); 

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll j = i;
        while(j != INF)
        {
            cowsOnPath[j] += cows[i];
            j = from[j];
        }
    }
    
    for(int i = 1; i <= n; i++)
        ans = max(ans, cowsOnPath[i] * (cost[i] - t)); 
    cout << ans << endl;
    return 0;
}