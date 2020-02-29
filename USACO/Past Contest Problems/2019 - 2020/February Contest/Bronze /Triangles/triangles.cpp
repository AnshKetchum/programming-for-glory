#include <bits/stdc++.h>
using namespace std;
#define MAXN 150
#define INF 1e9
typedef pair<int,int> pii;

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n, ans = -INF;
pii coords[MAXN];
int main()
{
    setIO("triangles");
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second;
    
    for(int a = 0; a < n; a++) //A & B are parallel, C is top / Bottom
        for(int b = 0; b < n; b++)
            for(int c = 0; c < n; c++)
                if(a != b && b != c && a != c && (coords[a].second == coords[b].second) && (coords[a].first == coords[c].first))
                    ans = max(ans,abs(coords[a].first - coords[b].first) * abs(coords[c].second - coords[a].second));
    cout << ans << endl;
    return 0;
}