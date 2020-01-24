#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 10001
typedef long long ll;
typedef pair<int,int> pii;

struct Plane
{
    int cows;
    pii coord1,coord2;
};

int n,k;
Plane planes[MAXN];
ll count_hits(int pos)
{
    ll ret = 0;
    for(int i = 0; i < n; i++)
        if(pos >= planes[i].coord1.first && pos <= planes[i].coord2.first)
            ret += (ll)planes[i].cows;
    return ret;
}

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main()
{
    FASTIO
    setIO("test");

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> planes[i].coord1.first >> planes[i].coord1.second >> planes[i].coord2.first >> planes[i].coord2.second >> planes[i].cows;

    for(int i = 0; i < k; i++)
    {
        int x; cin >> x;
        cout << count_hits(x) << endl;
    }

    return 0;
}