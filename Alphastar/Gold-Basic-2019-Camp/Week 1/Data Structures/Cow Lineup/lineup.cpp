#include <bits/stdc++.h>
using namespace std;
#define MAX_COWS 55000

typedef pair<int,int> pii;
pii cows[MAX_COWS];
int n;
long long ans = 1000000000;
set <int> recents;
map <int,int> recents_id;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
         cin >> cows[i].first >> cows[i].second;
         recents_id[cows[i].second]++;
    }

    int total_breeds = recents_id.size();
    recents_id.clear(); //+ O(N) here
    sort(cows, cows + n); // NLogN + O(N)

    for(int i = 0; i < n; i++)
    {
        recents_id[cows[i].second]++;
        if(recents_id[cows[i].second] > 1)
             recents.erase(recents_id[cows[i].second] - 1);
         
        recents_id[cows[i].second] = cows[i].first;
        recents.insert(recents_id[cows[i].second]);

        if(recents.size() == total_breeds)
        {
            auto it = recents.end();
            it--;
            int totalDist = *(it) - *(recents.begin());
            ans = min(ans,(long long)totalDist);
        }

    }
    cout << ans << endl;
    return 0;
}
