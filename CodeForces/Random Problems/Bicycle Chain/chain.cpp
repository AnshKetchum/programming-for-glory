#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int n, m, a[MAXN], curmx, ans; 

/*
What I didn't realize after reading the problem for the first time:
1. That all pairs can be used
2. What the problem wanted me to do - critical mistake, increased solve time by +2-3 mins
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0, b; i < m; i++)
    {
        cin >> b;
        for(int j = 0; j < n; j++)
            if(b % a[j] == 0 && (b / a[j]) >= curmx)
            {
                if(b / a[j] > curmx)
                {
                    ans = 0;
                    curmx = b / a[j];
                }
                ans++;
            }
    }
    
    
    cout << ans << endl;
    return 0;
}