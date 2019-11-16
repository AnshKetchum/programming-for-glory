#include <bits/stdc++.h>
using namespace std;
#define MAXN 350000

int n,m,order[MAXN];
vector <int> connections [MAXN];
bool active_nodes [MAXN];
string ans [MAXN];
struct DSU
{
    set <int> active_groups;
    int parent[MAXN];

    DSU()
    {
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    void make_set(int node)
    {
        active_groups.insert(node); //Group with root here
    }

    void merge_sets(int f, int t)
    {
        int par_f = get_root(f);
        int par_et = get_root(t);

        if(par_f != par_et)
        {
            parent[par_f] = par_et;
            active_groups.erase(par_f); //After merger, only 1 combined group exists
        }
    }

    int get_root(int node)
    {
        int p;
        for(p = node; parent[p] != p; p = parent[p])
            parent[p] = parent[parent[p]];
        return p;
    }

    bool answer_query()
    {
        return active_groups.size() <= 1;
    }
    
    int count_sets()
    {
        return active_groups.size();
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("closing.in");
    ofstream cout("closing.out");

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    for(int i = 0; i < n; i++)
        cin >> order[i];

    DSU solver = DSU();

    for(int i = n - 1; i >= 0; i--)
    {   
        active_nodes[order[i]] = true;
        solver.make_set(order[i]);
        for(int node : connections[order[i]])
            if(active_nodes[node])
                solver.merge_sets(order[i],node);
        ans[i] = (solver.answer_query() ? "YES" : "NO"); 

    } 



    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}