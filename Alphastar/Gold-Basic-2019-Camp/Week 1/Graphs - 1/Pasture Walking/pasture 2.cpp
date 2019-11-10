#include <bits/stdc++.h>
using namespace std;
#define MAX_COWS 1500
#define INF 10000000

int n,q;
bool visited[MAX_COWS];
typedef pair<int,int> pii;
vector <pii> connections [MAX_COWS];
int bfs(int starting, int ending)
{
    queue <pii> enque;
    enque.push(pii(starting,0));

    for(int i = 1; i <= n; i++)
        visited[i] = false;

    int query = INF;
    while(!enque.empty())
    {
        pii top = enque.front();
        enque.pop();

        if(top.first == ending)
        {
            query = min(query,top.second);
        }
        visited[top.first] = true;

        for(pii x : connections[top.first])
            if(!visited[x.first])
            {
                visited[x.first] = true;
                enque.push(pii(x.first,top.second + x.second));
            }
    }
    return query;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i = 0; i < n - 1; i++)
    {
        int a,b,l;
        cin >> a >> b >> l;
        connections[a].push_back(pii(b,l));
        connections[b].push_back(pii(a,l));
    }

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        cout << bfs(a,b) << endl;
    }

    return 0;
}
