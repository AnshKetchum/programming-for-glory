#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 550

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,mn;
multiset <int>  connections [MAXN];
vector <int> ans;

void tour(int node)
{
    ans.push_back(node);
    

}

int main()
{
    setIO("fence.in");
    cin >> n;

    for(int i = 0; i < n; i++)  
    {
        int a,b; cin >> a >> b;
        connections[a].insert(b);
        connections[b].insert(a);
    }

    for(int i = 1; i <= n; i++)
        if(!connections[i].empty())
        {
            tour(i);
            break;
        }

    return 0;
}