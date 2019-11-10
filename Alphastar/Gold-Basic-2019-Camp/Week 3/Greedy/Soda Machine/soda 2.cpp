#include <bits/stdc++.h>
using namespace std;

typedef pair<int,bool> pib;
vector <pib> points;
int n,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int s_i,e_i; cin >> s_i >> e_i;
        points.push_back(pib(s_i,false));
        points.push_back(pib(e_i,true));

    }
    sort(points.begin(),points.end());

    int cnt = 0;
    for(int i = 0; i < points.size(); i++)
    {
        cnt += (points[i].second ? -1 : 1);
        ans = max(ans,cnt);
    }

    cout << ans << endl;
    return 0;
}
