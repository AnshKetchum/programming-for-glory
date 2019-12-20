#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005

int finalPosition[MAXN],t,n,groups = 1,speed[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    for(int i = 0; i < n; i++)
    {
        int a,s; cin >> a >> s;
        finalPosition[i] = a + s * t;
    }

    for(int i = n - 1; i > 0; i--)
    {
        if(finalPosition[i - 1] >= finalPosition[i])
            finalPosition[i - 1] = finalPosition[i];
        else groups++;
    }

    cout << groups << endl;
    return 0;
}
