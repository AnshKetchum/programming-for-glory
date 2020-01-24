#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
#define INF 999999999
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);

struct Entry
{
    string type;
    int l,r;
};

int n;
Entry entries [MAXN];
void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}



int main()
{
    setIO("traffic");
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> entries[i].type >> entries[i].l >> entries[i].r;
    
    int mn = -INF, mx = INF;
    for(int i = n - 1; i >= 0; i--)
    {   
        if(entries[i].type == "none")
        {
            mn = max(mn, entries[i].l);
            mx = min(mx, entries[i].r);
        }

        else if(entries[i].type == "off")
        {
            mn += entries[i].l;
            mx += entries[i].r;
        }

        else if(entries[i].type == "on")
        {
            mn -= entries[i].r;
            mx -= entries[i].l;
        }
        mn = max(mn,0);
    }
    cout << mn << " " << mx << endl;

    mn = -INF, mx = INF;
    for(int i = 0; i < n; i++)
    {   
        if(entries[i].type == "none")
        {
            mn = max(mn, entries[i].l);
            mx = min(mx, entries[i].r);
        }

        else if(entries[i].type == "off")
        {
            mn -= entries[i].r;
            mx -= entries[i].l;
        }

        else if(entries[i].type == "on")
        {
            mn += entries[i].l;
            mx += entries[i].r;
        }
        mn = max(mn,0);

    }
    cout << mn << " " << mx << endl;

    return 0;
}