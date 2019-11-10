#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define BESSIE_PIE 0
#define ELSIE_PIE 1

typedef pair<int,int> pii;
int n,d;
pii pies [MAXN],best_choice[MAXN];
multiset <pii> best_edges[2]; 
bool visited [MAXN];

void bfs()
{
    queue <pii> enque;
    for(int i = 1; i <= n; i++)
    {
        enque.push(pii(i,BESSIE_PIE));
        best_edges[BESSIE_PIE].insert(pii(pies[i].second,i));
    }
    for(int i = n + 1; i <= 2 * n; i++)
        best_edges[ELSIE_PIE].insert(pies[i].first,i);

    while(!enque.empty())
    {
        pii top = enque.top();
        enque.pop();

        if(visited[top.first])
            continue;
        visited[top.first] = true;

        switch(top.second)
        {
            case BESSIE_PIE:
            pii best = best_edges[ELSIE_PIE].

            break;

            case ELSIE_PIE:


            break;
        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    for(int i = 1; i <= 2 * n; i++)
        cin >> pies[i].first >> pies[i].second;

    bfs();

    return 0;
}