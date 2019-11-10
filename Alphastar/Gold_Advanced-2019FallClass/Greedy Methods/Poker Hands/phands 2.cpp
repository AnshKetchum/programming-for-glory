#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

typedef long long ll;
ll n,a[MAXN],ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
        ans += max((ll)0,a[i] - a[i - 1]);
    cout << ans + a[0] << endl;
    return 0;
}