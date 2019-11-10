#include <bits/stdc++.h>
using namespace std;
#define MAX_V 2000
#define INF 100000000

int connections [MAX_V][MAX_V],n,m,b,dist[MAX_V];
bool visited [MAX_V];
typedef pair<int,int> pii;

void get_path()
{
    for(int i = 0; i < n; i++)
        dist[i] = INF,visited[i] = false;

    dist[1500] = INF;
    visited[0] = true;
    dist[0] = 0;
    int to_visit = 0,min_node = 1500;

    while(to_visit != -1)
    {

        min_node = 1500;
        for(int i = 0; i < n; i++)
        {
            if(i == to_visit)
                continue;
            if(dist[i] > dist[to_visit] + connections[to_visit][i] && !visited[i])
                dist[i] = dist[to_visit] + connections[to_visit][i];
        }

        for(int i = 0; i < n; i++)
            if(!visited[i] && dist[i] < dist[min_node])
                min_node = i;

        visited[min_node] = true;
        if(min_node == 1500)
            min_node = -1;
        to_visit = min_node;
    }


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> b;

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

    for(int i = 0; i < b; i++)
    {
        int a,b; cin >> a >> b;
        a--;
        b--;
        int ans = dist[a] + dist[b];
        cout << ans << endl;
    }
    
    
    return 0;
}
