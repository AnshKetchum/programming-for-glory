#include <bits/stdc++.h>
using namespace std;
#define MAXN 500

int n,ans;
string s;
map<string,int> cnt;
bool impos[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("whereami.in");
    cin >> n >> s;

    for(int len  = 1; len <= s.length(); len++)
        for(int i = 0; i + len <= s.length(); i++)
            cnt[s.substr(i,len)]++;

    ans = n;
    for(auto const& x : cnt)
        impos[x.first.length()] = (impos[x.first.length()] || x.second > 1);
    for(int i = 1; i <= n; i++)
        if(!impos[i])
        {
            ans = i;
            break;
        }
    ofstream cout("whereami.out");
    cout << ans << endl;
    return 0;
}