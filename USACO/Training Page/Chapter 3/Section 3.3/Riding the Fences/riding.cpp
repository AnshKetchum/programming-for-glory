/*****
ID: ansh1221
LANG: C++
PROG: fence
**/
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 1500 
#define MAX_NODES 500
#define pb push_back 
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

void setIO(string name) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}


int n;
bool vis[MAXN],works;
vi ans,cur; 
vpii connections[MAXN]; //First node to go to, second is index of edge (for visited)

void dfs(int node, int edges)
{
    cout << node << " " << edges << endl;
    if(!edges)
    {
        for(int i = 0; i < cur.size(); i++)
        {
            if(cur[i] < ans[i])
            {
                ans = cur;
                works = true;
                break;
            }
            //Current answer is better, forget new one
            else if(ans[i] < cur[i])
                break;
        }

        return;
    }
    for(pii conn : connections[node])
        if(!vis[conn.second])   
        {
            vis[conn.second] = true;
            cur.pb(conn.first);

            dfs(conn.first, edges - 1);
            
            cur.pop_back();
            vis[conn.second] = false;
        }
}



int main()
{
    setIO("fence");
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        connections[a].pb(pii(b,i));
        connections[b].pb(pii(a,i));
    }

    for(int i = 0; i < n + 1; i++)
        ans.pb(MAX_NODES + 1);
    
    for(int i = 1; i <= MAX_NODES && !works; i++)
    {
        fill(vis, vis + MAX_NODES + 5, false);
        cur.clear();
        cur.pb(i);
        dfs(i, n); //Launch DFS with root at node i 
    }

    for(int x : ans)
        cout << x << endl;

    return 0;
}