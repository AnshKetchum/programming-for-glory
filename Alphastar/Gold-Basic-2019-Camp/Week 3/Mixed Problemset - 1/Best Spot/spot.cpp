#include <bits/stdc++.h>
using namespace std;
#define MAXN 905
#define INF 10000000

int distances[MAXN][MAXN],p,f,c,favorites[MAXN];
double averages[MAXN];

void floyd_warshall()
{
    for(int k = 1; k <= p; k++)
        for(int i = 1; i <= p; i++)
            for(int j = 1; j <= p; j++)
            {
                if(i == j || j == k || k == i)
                    continue;
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            if(i != j)
                distances[i][j] = INF;

    cin >> p >> f >> c;
    for(int i = 1; i <= f; i++) //1 Indexing
        cin >> favorites[i];

    for(int i = 0; i < c; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        distances[a][b] = min(distances[a][b],c);
        distances[b][a] = min(distances[b][a],c);
    }

    floyd_warshall();

    for(int i = 1; i <= p; i++)
    {
        int sum = 0;
        for(int j = 1; j <= f; j++)
            sum += distances[i][favorites[j]];
        averages[i] = (double)(sum) / f;
    }

    int ind = -1;
    for(int i = 1; i <= p; i++)
        if(averages[i] < averages[ind] || ind == -1)
            ind = i;
    cout << ind << endl;
    return 0;
}
