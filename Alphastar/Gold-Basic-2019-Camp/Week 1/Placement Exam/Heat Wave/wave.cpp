#include <bits/stdc++.h>
using namespace std;
#define MAX_V 3000
#define INF 100000000

int connections [MAX_V][MAX_V],t,c,t_s,t_e,dist[MAX_V],specialNumber = 2500;
bool visited [MAX_V];
typedef pair<int,int> pii;
void get_path()
{
    for(int i = 0; i < t; i++)
        dist[i] = INF,visited[i] = false;

    dist[specialNumber] = INF;
    visited[t_s] = true;
    dist[t_s] = 0;
    int to_visit = t_s,min_node = specialNumber;

    while(to_visit != -1)
    {
        min_node = specialNumber;
        for(int i = 0; i < t; i++)
        {
            if(i == to_visit)
                continue;
            if(dist[i] > dist[to_visit] + connections[to_visit][i] && !visited[i])
                dist[i] = dist[to_visit] + connections[to_visit][i];
        }

        for(int i = 0; i < t; i++)
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

    cin >> t >> c >> t_s >> t_e;

    for(int i = 0;i < t; i++)
        for(int j = 0; j < t; j++)
            if(i != j )
                connections[i][j] = INF;

    for(int i = 0; i < c; i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        a--;
        b--;
        connections[a][b] = min(connections[a][b],d);
        connections[b][a] = min(connections[b][a],d);
    }

    t_s --;
    t_e --;
    get_path();

    cout << dist[t_e] << endl;
    return 0;
}
