#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,x,y;
priority_queue <int> current,wanted;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    //X is added, Y is removed
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
    {
        int c,w; cin >> c >> w;
        current.push(-c);
        wanted.push(-w);
    }


    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cur = current.top() * -1;
        int want = wanted.top() * -1;
        current.pop(); wanted.pop();

        if(cur < want)
            ans += (want - cur) * x;
        else if(cur > want)
            ans += (cur - want) * y;
    }
    cout << ans << endl;
    return 0;
}
