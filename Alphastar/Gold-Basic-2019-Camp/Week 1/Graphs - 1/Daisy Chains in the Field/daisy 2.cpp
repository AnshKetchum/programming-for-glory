#include <bits/stdc++.h>
using namespace std;
#define MAXN 300

bool visited[MAXN],connection[MAXN][MAXN],zero = true;
int m,n;

void bfs()
{
    queue <int> enque;
    enque.push(1);

    while(!enque.empty())
    {
        int top = enque.front();
        enque.pop();

        visited[top] = true;

        for(int i = 1; i <= n; i++)
            if(connection[top][i] && !visited[i])
             {
                 enque.push(i);
                 visited[i] = true;
             }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        connection[a][b] = true;
        connection[b][a] = true;
    }

    bfs();

    for(int i = 1; i <= n; i++)
        if(!visited[i])
        {
            zero = false;
            cout << i << endl;
        }
    if(zero)
        cout << 0 << endl;

    return 0;
}
