#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 350000
#define SHIFT 10005
#define MAX_COORDS 25000 * 5
typedef long long ll;
typedef pair<ll,ll> pll;

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

bool comp(pll a, pll b)
{
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int n;
pll coords[MAXN];
ll ans, heights[MAX_COORDS];
int main()
{
    setIO("triangles");
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> coords[i].first >> coords[i].second;
        heights[coords[i].first + SHIFT] += abs(coords[i].second);
    }

    sort(coords, coords + n, comp);

    for(int l = 0; l < n; l++)
    {
        int r = l + 1;
        while(coords[r].second == coords[l].second && heights[coords[l].first + SHIFT] && r < n)
        {
            //cout << "(" << coords[l].first << "," << coords[l].second << ") (" << coords[r].first << "," <<  coords[r].second << ")" << endl;
            ll area = (abs(coords[r].first - coords[l].first) * abs(heights[coords[l].first + SHIFT] - coords[l].second));
            ans = (ans + area) % MOD;
            r++;
        }
    }

    for(int r = n - 1; r >= 0; r--)
    {
        int l = r - 1;
        while(coords[r].second == coords[l].second && heights[coords[r].first + SHIFT] && l >= 0)
        {
            //cout << "(" << coords[l].first << "," << coords[l].second << ") (" << coords[r].first << "," <<  coords[r].second << ")" << endl;
            ll area = (abs(coords[r].first - coords[l].first) * abs(heights[coords[r].first + SHIFT] - coords[l].second));
            ans = (ans + area) % MOD;
            l--;
        }
    }

    cout << ans << endl;
    return 0;
}