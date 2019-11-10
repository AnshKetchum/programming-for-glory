#include <bits/stdc++.h>
using namespace std;
#define MAXN 105000
#define OPEN_PARENTHESIS 0
#define CLOSED_PARENTHESIS 1
#define MOD 12345678910
#define int long long

int n,s[MAXN],far[MAXN];
stack <int> last;

int solve(int l, int r)
{
    if(l + 1 == r)
        return 1;
    if(far[l] == r)
        return ((2 * solve(l + 1, r - 1) % MOD) % MOD);
    else
        return ((solve(l,far[l]) % MOD + solve(far[l] + 1,r) % MOD) % MOD);
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == CLOSED_PARENTHESIS)
            last.push(i);
        else
        {
            far[i] = last.top();
            last.pop();
        }
    }

    cout << solve(0, n - 1) % MOD << endl;
    return 0;
}
