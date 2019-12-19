#include <bits/stdc++.h>
using namespace std;
#define MAXN 750
#define MAXV 55

int n,out[MAXV][MAXV],compressed,edges[MAXV];

int getInd(char c)
{
    if('a' <= c && c <= 'z')
        return c - 'a' + 26;
    return c - 'A';
}

void delete_edges()
{
    for(int i = 0; i < MAXV)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++) //Apply second operation
    {
        char a = '-',b ='-'; int flow = -1;
        cin >> a >> b >> flow;
        if(out[getInd(a)][getInd(b)])
            ++compressed;
        else
            ++edges[a];
        out[getInd(a)][getInd(b)] += flow;
    }

    do
    {
        delete_edges();
        merge_edges();
    }
    while(compressed != n - 1);
    cout << 
    return 0;
}