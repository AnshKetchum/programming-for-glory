#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
typedef pair<int,int> pii;

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n;
pii coords[MAXN],active_interval;

int count_intersections()
{
	int ret = 0;
	sort(coords, coords + n);
	active_interval = coords[0];

	for(int i = 1; i < n; i++)
	{
	
	}
}

int main()
{
	setIO("help");
	
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> coords[i].first >> coords[i].second;

	cout << (1 << count_intersections()) << endl;
    return 0;
}