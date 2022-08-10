#include <bits/stdc++.h>
using namespace std;
#define MAXM 1100
#define MAX_PASS 1000
int n, m, pref[MAXM], mx, mn;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0, a; i < m; i++)
    {
        cin >> a;
        pref[a + 1]--;
        pref[1]++;
    }

    for(int i = 2; i <= MAX_PASS; i++)
        pref[i] += pref[i - 1];
    for(int i = 1, j = n; i <= MAX_PASS && j > 0; i++)
        mn += i * (pref[i] > j ? j : pref[i]), j -= pref[i];
    for(int i = MAX_PASS, j = n; i > 0 && j > 0; i--)
        mx += i * (pref[i] > j ? j : pref[i]), j -= pref[i];
    cout << mx << " " << mn << endl;
    return 0;
}