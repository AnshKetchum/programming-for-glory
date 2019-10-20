#include <bits/stdc++.h>
using namespace std;

int n,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        int tot = (a == 1) + (b == 1) + (c == 1);
        ans += (tot >= 2 ? 1 : 0);
    }
    cout << ans << endl;
}