#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    set <int> active_groups;
    int parent[MAXN],n;

    DSU()
    {
        init();
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

    void set_nodes(int cnt)
    {
        n = cnt;
    }

    int init()
    {
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

};