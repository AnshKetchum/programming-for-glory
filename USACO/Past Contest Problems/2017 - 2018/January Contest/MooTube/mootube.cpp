#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 100000000


struct Edge
{
    int a,b,kval;
    Edge(int a, int b, int kval)
    {
        this->a = a;
        this->b = b;
        this->kval = kval;
    }

};

int n,q;
typedef pair<int,int> pii;
pii queries[MAXN];
bool used[MAXN];
vector <Edge> connections;
struct DSU
{
    set <int> active_groups;
    int parent[MAXN],sz,group_counts[MAXN];

    DSU(int sz)
    {
        this->sz = sz;
        init();
    }

    void make_set(int node)
    {
        active_groups.insert(node); //Group with root here
    }

    int get_size(int node)
    {
        return group_counts[get_root(node)];
    }

    void merge_sets(int f, int t)
    {
        int par_f = get_root(f);
        int par_et = get_root(t);


        if(par_f != par_et)
        {
            parent[par_f] = par_et;
            group_counts[par_et] += group_counts[par_f];    
            active_groups.erase(par_f); //After merger, only 1 combined group exists
        }
    }

    int get_root(int node)
    {
        int p;
        for(p = node; parent[p] != p; p = parent[p])
            parent[p] = parent[parent[p]]; //Compressing path for future
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

    void set_node_count(int cnt)
    {
        sz = cnt;
    }

    int init()
    {
        for(int i = 0; i <= sz; i++)
        {
            parent[i] = i;
            group_counts[i] = 1;
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for(int i = 0; i < n - 1; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections.push_back(Edge(a,b,c));
    }
    for(int i = 0; i < q; i++)
        cin >> queries[i].first >> queries[i].second;
    sort(queries, queries + n), greater<pii>());
    
    DSU graph = DSU(n);
    for(int i = 0; i < q; i++)
    {
        for(int i = )

        cout << 
    }
    
    
    return 0;
}