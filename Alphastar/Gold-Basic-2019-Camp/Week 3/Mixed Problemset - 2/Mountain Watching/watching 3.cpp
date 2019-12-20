#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define int long long
bool decreasing;
int v[MAXN],ans,runningCounter = 1,sameCounter = 1,n;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 1; i < n; i++)
    {
        if(v[i] == v[i - 1])
            sameCounter++;

        if(v[i] < v[i - 1])
            decreasing = true;

        if(v[i] > v[i - 1] && decreasing)
        {
            decreasing = false;
            ans = max(ans,runningCounter);
            runningCounter = sameCounter;
            sameCounter = 1;
        }
        runningCounter++;
        
        if(v[i] != v[i - 1])
            sameCounter = 1;
    }

    cout << max(ans,runningCounter) << endl;
    return 0;
}
