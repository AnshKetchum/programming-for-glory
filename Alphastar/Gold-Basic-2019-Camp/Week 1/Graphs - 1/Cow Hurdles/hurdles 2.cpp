#include <bits/stdc++.h>
using namespace std;
#define MAXN 400
#define INF 100000000

int best[MAXN][MAXN],n,m,t;

void floyd_warshall()
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                 best[i][j] = min(best[i][j], max(best[i][k],best[k][j]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            best[i][j] = INF;

    for(int i = 0; i < m; i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        a--;
        b--;
        best[a][b] = min(best[a][b],d);
    }

    floyd_warshall();

    for(int i = 0; i < t; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(best[a][b] == INF)
            best[a][b] = -1;
        cout << best[a][b] << endl;
    }

    return 0;
}
