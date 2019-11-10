#include <bits/stdc++.h>
using namespace std;
#define MAX_CONN_LENGTH 15
#define MAX_ENDPOINTS 250
#define DEBUG_PRINT  cout <<"MADE IT HERE" << endl;
#define INF 10000000000

typedef pair<int,int> pii;
vector <pii> front [MAX_ENDPOINTS];
vector <pii> back [MAX_ENDPOINTS];

set <int> ans [MAX_ENDPOINTS];
int m,cost[MAX_ENDPOINTS],fn;

void dijkstra(int source) //Find the shortest path from the front node
{
    bool visited[MAX_ENDPOINTS] = {false};
    fill(cost, cost + fn + 1, INF);
    cost[source] = 0;

    priority_queue <pii> best_edges;
    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;
        visited[top.second] = true;

        for(pii x : back[top.second])
            if(!visited[x.second])
            {
                int c = cost[top.second] + x.first;
                cost[x.second] = min(cost[x.second],c);
                best_edges.push(pii(-c,x.second));
            }
    }

    for(int i = 1; i <= fn; i++)
        if(cost[i] != INF)
            ans[cost[i]].insert(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("test.in");

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        front[b].push_back(pii(c,a));
        back[a].push_back(pii(c,b));
        fn = max(fn,max(a,b));
    }
    DEBUG_PRINT

    for(int i = 1; i <= fn; i++)    //Finding the first node - or the one with no front
        if(front[i].empty())
        {
            cout << "Source node: " << i << endl;
            dijkstra(i);
            break;
        }

    DEBUG_PRINT
    for(int dist = 1; dist <= MAX_CONN_LENGTH; dist++)
        if(!ans[dist].empty())
        {
            auto ending = (--ans[dist].end());
            for(auto it = ans[dist].begin(); it != ending; it++)
                cout << *it << ",";
            cout << *ending << endl;
        }
    DEBUG_PRINT
    return 0;
}