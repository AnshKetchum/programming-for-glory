#include <bits/stdc++.h>
using namespace std;

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(nullptr);
    cin.tie(nullptr); 
    cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int dist(int a, int b)
{
    return abs(a - b);
}

int starting,ending,tele_a,tele_b;
int main()
{
    setIO("teleport");
    cin >> starting >> ending >> tele_a >> tele_b;
    cout << min(dist(starting,ending),min(dist(starting,tele_b) + dist(tele_a,ending), dist(starting,tele_a) + dist(tele_b,ending))) << endl;
    return 0;
}