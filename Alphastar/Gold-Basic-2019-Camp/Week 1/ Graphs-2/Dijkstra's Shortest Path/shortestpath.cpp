#include <bits/stdc++.h>
using namespace std;
#define MAX_V 4000
#define INF 100000000


int connections [MAX_V][MAX_V],v,e,s,dist[MAX_V];
bool visited [MAX_V];
typedef pair<int,int> pii;

void get_path()
{
    int to_visit = s,min_node = 3449;

    for(int i = 0; i < v; i++)
        dist[i] = INF;
    dist[3449] = INF;
    visited[s] = true;
    dist[s] = 0;
    while(to_visit != -1)
    {

        min_node = 3449;
        for(int i = 0; i < v; i++)
        {
            if(i == to_visit)
                continue;
            if(dist[i] > dist[to_visit] + connections[to_visit][i] && !visited[i])
                dist[i] = dist[to_visit] + connections[to_visit][i];
        }

        for(int i = 0; i < v; i++)
            if(!visited[i] && dist[i] < dist[min_node])
                min_node = i;

        visited[min_node] = true;
        if(min_node == 3449)
            min_node = -1;
        to_visit = min_node;
    }

    for(int i = 0; i < v; i++)
    {
        if(dist[i] == INF)
            dist[i] = -1;
        cout << dist[i] << endl;
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> e >> s;

    s--;
    for(int i = 0;i < v; i++)
        for(int j = 0; j < v; j++)
            if(i != j )
                connections[i][j] = INF;

    for(int i = 0; i < e; i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        a--;
        b--;
        connections[a][b] = connections[b][a] = d;
    }

    get_path();
    return 0;
}
