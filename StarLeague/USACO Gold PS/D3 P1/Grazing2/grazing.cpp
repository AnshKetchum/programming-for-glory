#include <bits/stdc++.h>
using namespace std;
#define MAXN 1550
#define MAXS 1006005
#define INF 1e9
int n,s,dp[2][MAXS],pos[MAXN],d_min,d_max,d_max_cnt;

int get_cost(int ind,int newpos)
{
    return abs(newpos - pos[ind]);
}
void printA(int a[MAXS])
{
    for(int i = 1; i <= s; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> pos[i];

    sort(pos, pos + n); 
    
    d_min =  (n - 1 > 0 ? ((s - 1) / (n - 1)) : 0);
    d_max = d_min + 1;

    int so = 0,t = 1;
    fill(dp[so], dp[so] + s + 5, INF);
    dp[so][1] = get_cost(0,1);

    for(int i = 1; i < n; i++)
    {
        fill(dp[t], dp[t] + s + 5, INF);
        for(int j = s; j >= 1; j--)
        {
            if(j + d_min <= s)
                dp[t][j + d_min] = min(dp[t][j + d_min], dp[so][j] + get_cost(i, j + d_min));
            if(j + d_max <= s)
                dp[t][j + d_max] = min(dp[t][j + d_max], dp[so][j] + get_cost(i, j + d_max));
        }
        swap(dp[t],dp[so]);    
    }

    cout << (n == 1 ? 0 : dp[so][s]) << endl;
    return 0;
}