#include <bits/stdc++.h>
using namespace std;
#define MAXN 150

int n,m,cnts[MAXN];
bool reach [MAXN][MAXN];
void floyd_warshall()
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                reach[i][j] = (reach[i][j] || (reach[i][k] && reach[k][j]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        reach[a][b] = true;
        reach[b][a] = false;
    }

    for(int i = 0; i < n; i++)
        reach[i][i] = true;

    floyd_warshall();

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
          if( (reach[i][j] || reach[j][i]) && i != j)
          {
              reach[i][j] = reach[j][i] = false;
              cnts[i]++;
              cnts[j]++;
          }
    }
    for(int i = 0; i < n; i++)
        if(cnts[i] == n - 1)
            ans++;


    cout << ans << endl;
    return 0;
}
