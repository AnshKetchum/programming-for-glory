#include <bits/stdc++.h>
using namespace std;
#define MAXN 150
#define INF 1000000

int connections [MAXN][MAXN],n,cost[MAXN];
bool visited[MAXN],needUpdate = true;
int get_mst()
{
    int ans = 0,to_visit = 0,min_node = 149;
    visited[0] = true;
    cost[0] = 0;


    while(to_visit != -1)
    {
        min_node = 149;
        for(int i = 0; i < n; i++)
        {
            if(i == to_visit)
                continue;
            if(cost[i] > connections[to_visit][i] && !visited[i])
                cost[i] = connections[to_visit][i];
        }

        for(int i = 0; i < n; i++)
            if(!visited[i] && cost[i] < cost[min_node])
                min_node = i;

        visited[min_node] = true;
        if(min_node == 149)
            min_node = -1;
        to_visit = min_node;
    }

    for(int i = 0; i < n; i++)
        ans += cost[i];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cost[149] = INF;
    for(int i = 1; i < n; i++)
            cost[i] = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        cin >> connections[i][j];

    cout << get_mst() << endl;
    return 0;
}
