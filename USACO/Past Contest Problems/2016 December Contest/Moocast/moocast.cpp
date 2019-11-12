#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500
#define SQ(x) x * x
#define INF 10000000000000
typedef long long ll;
typedef pair<int,int> pii;


int n,cnt;
pii coords [MAXN];
bool visited[MAXN];

int get_squared_dist(int i, int j)
{
    pii c1 = coords[i], c2 = coords[j];
    ll dx = c1.first - c2.first;
    ll dy = c1.second - c2.second;
    return SQ(dx) + SQ(dy);
}

void dfs(int node,int md)
{
    if(visited[node])
        return;
    cnt++;
    visited[node] = true;

    for(int i = 0; i < n; i++)
        if(get_squared_dist(node,i) <= md)
            dfs(i,md);
}

bool pos(int val)
{
    fill(visited, visited + n,false);
    cnt = 0;
    dfs(0,val);
    return cnt == n;
}


int get_best(ll l, ll r)
{
    if(l == r)
        return l;
    ll mid = (l + r) / 2;

    if(pos(mid))
        return get_best(l,mid);
    return get_best(mid + 1,r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("moocast.in");
    ofstream cout("moocast.out");

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second;
        
    cout << get_best(0,INF) << endl;
}