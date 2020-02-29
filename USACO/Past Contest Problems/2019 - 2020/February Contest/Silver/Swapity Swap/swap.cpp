#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define pb push_back


int n,k,m;
vector <int> cur_seq,ret;
pair <int,int> ranges[MAXN];
vector < vector<int> >  orderings;

bool works()
{
    for(int i = 0; i < cur_seq.size(); i++)
    {
        if(cur_seq[i] != i)
        {
            return false;
        }
    }
    return true;
}

void reverse_seq(int fr, int tr)
{
    vector <int>  g;
    for(int i = fr; i <= tr; i++)
    {
        g.pb(cur_seq[i]);
    }
    for(int i = 0; i < g.size(); i++)
    {
        cur_seq[tr - i] = g[i];
    }
}

int main()
{
    ifstream cin("swap.in");
    ofstream cout("swap.out");

    cin >> n >> m >> k;
    cur_seq.push_back(0);
    for(int i = 1; i <= n; i++)
        cur_seq.push_back(i);    
    for(int i = 0; i < m; i++)
    {
        
        
        
        cin >> ranges[i].first >> ranges[i].second;
    }




    orderings.push_back(cur_seq);
    for(int i = 1; i <= k; i++)
    {
        for(pair <int,int> x : ranges)
        {
            reverse_seq(x.first, x.second);
        }
        if(works())
        {
            ret = orderings[k % i];
            break;
        }
        orderings.push_back(cur_seq);
        ret = cur_seq;
    }
    
    for(int i = 1; i <= n; i++)
        cout << ret[i] << endl; 
    return 0;
}