#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
typedef pair<int,int> pii;
#define MAXN 150000

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

struct Interval
{
    int s,e,i;
    Interval(int a,int b, int c)
    {
        s = a;
        e = b;
        i = c;
    }

};

bool comp(Interval a, Interval b)
{
    return a.s < b.s;
}

int n,avg,denom,cnt; 
vector<Interval> coords;
bool seen[MAXN];
int main()
{
    setIO();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        coords.pb(Interval(a,c,i));
        coords.pb(Interval(b,c,i));
    }

    coords.pb(Interval(0,0,-1));
    sort(coords.begin(), coords.end(), comp);

    for(int i = 1; i < coords.size(); i++)
    {
        avg += (coords[i].s - coords[i - 1].s) * cnt;
        if(seen[coords[i].i])
            cnt -= coords[i].e;
        else 
            cnt += coords[i].e;
        seen[coords[i].i] = true;
    } 

    cout << (avg / coords[coords.size() - 1].s) << endl;
    return 0;
}