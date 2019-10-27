#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

int n,k,gems[MAXN],ans = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> gems[i];
    sort(gems, gems + n);
        
    int divider = n / k;
    for(int i = 0; i < n - 1; i += divider)
        ans *= (gems[i + 1] - gems[i] - 1);
        
    cout << ans << endl;
    return 0;
} 
