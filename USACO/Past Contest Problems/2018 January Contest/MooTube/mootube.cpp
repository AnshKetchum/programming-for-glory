#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 100000000

typedef pair<int,int> pii;  
int n,q;
vector <pii> connections [MAXN];

void prims()
{
    int cost [MAXN];
    fill(cost, cost + n + 5,INF);
    bool visited[MAXN] = {false};
    priority_queue<pii> best_edges;

    best_edges.push(pii(0,1));
    cost[1] = 0;

    cout << "\n\n";
    
    while (!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;

        cout << top.first << " " << top.second << endl;
        visited[top.second] = true;

        for(pii x : connections[top.second])
            if(!visited[x.second])
            {
                cost[x.second] = min(cost[x.second],x.first);
                cout << "Cost of " << x.second << " is: " << cost[x.second] << endl;

                cout << "Adding: " << x.first << " " << x.second << endl;
                best_edges.push(pii(-x.first,x.second));
            }
    }

    for(int i = 1; i <= n; i++)
        cout << cost[i] << " ";
    cout << endl;
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections[a].push_back(pii(b,c));
        connections[b].push_back(pii(a,c));
    }

    prims();

    return 0;
}