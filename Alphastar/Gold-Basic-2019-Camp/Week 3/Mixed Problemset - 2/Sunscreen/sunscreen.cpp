#include <bits/stdc++.h>
using namespace std;

int c,l,ans,cowInd,sunscreenInd;
typedef pair<int, int> pii;
vector <pii> cows,sunscreens;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> l;

    for(int i = 0; i < c; i++)
    {
        int a,b; cin >> a >> b;
        cows.push_back(pii(a,b));
    }

    for(int i = 0; i < l; i++)
    {
        int a,b; cin >> a >> b;
        sunscreens.push_back(pii(a,b));
    }

    sort(cows.begin(),cows.end(),greater<pii>());
    sort(sunscreens.begin(),sunscreens.end(),greater<pii>());

    for(int i = 0; i < cows.size(); i++)
        for(int j = 0; j < sunscreens.size(); j++)
            if(cows[i].first <= sunscreens[j].first && cows[i].second >= sunscreens[j].first && sunscreens[j].second > 0)
            {
                ans++;
                sunscreens[j].second--;
                break;
            }

    cout << ans << endl;
    return 0;
}
