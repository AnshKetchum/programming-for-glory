#include <bits/stdc++.h>
using namespace std;
#define MAX_N 55000
#define BAD_VAL

typedef pair<int,int> pii;
pii cows [MAX_N];
int rightC[MAX_N],leftC[MAX_N],n,cnts[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> cows[i].first >> cows[i].second;

    for(int i = 0; i < n; i++)
    {
        leftC[i] = -1;
        rightC[i] = -1;
        for(int j = i + 1; j < n; j++)
            if(cows[j].first > cows[i].first)
              {
                 rightC[i] = j;
                 break;
              }
        for(int j = i - 1; j >= 0; j--)
            if(cows[j].first > cows[i].first)
            {
                leftC[i] = j;
                break;
            }
    }

    for(int i = 0; i < n; i++)
    {
        if(rightC[i] != -1)
                cnts[rightC[i]] += cows[i].second;
        if(leftC[i] != -1)
                cnts[leftC[i]] += cows[i].second;
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(cnts[i],ans);
    cout << ans << endl;
    return 0;
}
