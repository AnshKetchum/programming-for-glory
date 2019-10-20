#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
typedef pair<int,int> pii;
typedef long long ll;
pii cur,last,finalRange;
ll ans = 1,n;
 
void getUnion(pii a, pii b)
{
    ll mx = max(a.first,a.second),mn = min(b.first,b.second);
    ans += (mn >= mx ? (mn - mx + 1) : 0) + (a.first == a.second ? -1 : 0);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> cur.first >> cur.second;
        getUnion(last,cur);
        last = cur;
    }
 
    cout << ans << endl;
    return 0;
}