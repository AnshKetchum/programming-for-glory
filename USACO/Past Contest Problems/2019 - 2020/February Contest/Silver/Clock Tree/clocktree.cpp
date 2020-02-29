#include <bits/stdc++.h>
using namespace std;
#define MAXN 2700

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

bool works;
int n,cloc[MAXN],ans,goodcnt;
vector <int> connections [MAXN];

void dfs(int node, int fin)
{
    if(cloc[node] >= 12)
        return;
    cloc[node]++;
    if(cloc[node] == 12)
    {
        fin++;
        if(fin == n)
            works = true;
    }

    for(int i = 0; i < connections[node].size() && !works; i++)
        dfs(connections[node][i], fin);
    
    cloc[node]--;
}

void upd(int i)
{
    cloc[i]--;
    works = false; 
    
    if(cloc[i] + 1 == 12)
        dfs(i, goodcnt - 1);
    else
        dfs(i, goodcnt);
    cloc[i]++;
    ans += works;
}

int main()
{
    setIO("clocktree");
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> cloc[i];
        goodcnt += (cloc[i] == 12);
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a,b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++)
        upd(i);
    cout << ans << endl;
    return 0;
}