
/*****
ID: ansh1221
LANG: C++
PROG: fence
**/
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;
#define MAXN 1500

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n,smallest = MAXN;
multiset<int> connections[MAXN];
vector<int> cur;

void tour(int node)
{
    cur.push_back(node);
    while(!connections[node].empty())
    {
        int nxtNode = *connections[node].begin();
        connections[nxtNode].erase(connections[nxtNode].find(node));
        connections[node].erase(connections[node].find(nxtNode));
        tour(nxtNode);
    }
}

int main()
{
    setIO("fence");
    cin >> n;
    for(int i = 1,a = 0,b =0; i <= n; i++)
    {   
        cin >> a >> b;
        connections[a].insert(b);
        connections[b].insert(a);
        smallest = min(smallest, a);
        smallest = min(smallest, b);
    }

    tour(smallest);

    for(int x : cur)
        cout << x << endl;

    return 0;
}
