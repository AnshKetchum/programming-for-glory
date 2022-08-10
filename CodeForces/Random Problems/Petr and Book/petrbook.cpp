#include <bits/stdc++.h>
using namespace std;
#define MAXN 7 
typedef long long ll;
ll n, s[MAXN];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < 7; i++)
        cin >> s[i];

    for(ll i = 0; n >= 0;) 
    {
        n -= s[i++ % 7]; 
        if(n <= 0)
        {
            if(i % 7 == 0 && i >= 7) cout << 7 << endl; 
            else cout << (i % 7) << endl;
            break;
        }
    }
    return 0;
}