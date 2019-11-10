#include <bits/stdc++.h>
using namespace std;
#define MAX_V 2000
#define INF 100000000

int connections [MAX_V][MAX_V],n,m,dist[MAX_V],from[MAX_V],ans = 0,specialNumber = 2500;
bool visited [MAX_V];
typedef pair<int,int> pii;
vector <int> nodes;
void get_path()
{
    for(int i = 0; i < n; i++)
        dist[i] = INF,visited[i] = false;

    dist[specialNumber] = INF;
    visited[0] = true;
    dist[0] = 0;

    int to_visit = 0,min_node = specialNumber;

    while(to_visit != -1)
    {
        min_node = specialNumber;
        for(int i = 0; i < n; i++)
        {
            if(i == to_visit)
                continue;
            if(dist[i] > dist[to_visit] + connections[to_visit][i] && !visited[i])
            {
                dist[i] = dist[to_visit] + connections[to_visit][i];
                from[i] = to_visit;
            }
        }

        for(int i = 0; i < n; i++)
            if(!visited[i] && dist[i] < dist[min_node])
                min_node = i;

        visited[min_node] = true;

        if(min_node == specialNumber)
            min_node = -1;

        to_visit = min_node;
    }


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j )
                connections[i][j] = INF;

    for(int i = 0; i < m; i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        a--;
        b--;
        connections[a][b] = min(connections[a][b],d);
        connections[b][a] = min(connections[b][a],d);
    }

    get_path();

    int a = n - 1;
    while(a != 0)
    {
        nodes.push_back(a);
        a = from[a];
    }
    nodes.push_back(0);

    int orig_dist = dist[n - 1];
    for(int i = 1; i < nodes.size(); i++)
    {
        connections[nodes[i]][nodes[i - 1]] *= 2;
        connections[nodes[i - 1]][nodes[i]] *= 2;
        
        get_path();
        
        ans = max(ans,dist[n - 1] - orig_dist);
        connections[nodes[i]][nodes[i - 1]] /= 2;
        connections[nodes[i - 1]][nodes[i]] /= 2;
    }


    cout << ans << endl;
    return 0;
}