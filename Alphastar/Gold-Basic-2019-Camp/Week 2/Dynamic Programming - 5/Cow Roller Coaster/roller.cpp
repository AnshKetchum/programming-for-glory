#include <bits/stdc++.h>
using namespace std;
#define MAXN 3005
#define MAXC 3005
#define MAXAL 10005
#define INF -100000000000

struct Component
{
    int startLoc,totalLength,funRating,cost;

    Component(){}
    Component(int startLoc,int totalLength, int funRating, int cost)
    {
        this->startLoc = startLoc;
        this->totalLength = totalLength;
        this->funRating = funRating;
        this->cost = cost;
    }
};

int l,n,b,dp[MAXN][MAXC],ans;
Component listOfComponents [MAXAL];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> l >> n >> b;
    for(int i = 0; i < n; i++)
    {
        int x,w,f,c; cin >> x >> w >> f >> c;
        listOfComponents[i] = Component(x,w,f,c);
    }

    sort(listOfComponents, listOfComponents + n, [](const Component a, const Component b){
         return a.startLoc < b.startLoc;
    });
    for(int i = 0; i <= l; i++)
        for(int j = 0; j <= b; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
    {
        Component cur = listOfComponents[i];
        for(int j = 0; j <= b; j++)
            if(dp[cur.startLoc][j] != INF)
                dp[cur.startLoc + cur.totalLength][j + cur.cost] = max(dp[cur.startLoc + cur.totalLength][j + cur.cost],dp[cur.startLoc][j] + cur.funRating);
    }

    for(int j = 0; j <= b; j++)
        ans = max(ans,dp[l][j]);
   cout << ((ans == 0) ? -1 : ans) << endl;
    return 0;
}
