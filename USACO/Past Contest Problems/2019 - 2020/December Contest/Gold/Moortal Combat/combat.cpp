/*
Problem 3: USACO
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100500
#define MAXM 27
#define INF 1e8
string str;
int cost[MAXM][MAXM],dp[MAXM][MAXN],pref[MAXM][MAXN],n,m,k,minDP[MAXN];

int int_value(char c)
{
    return c - 'a';
}

void floyd_warshall()
{
    for(int k = 0; k < m; k++)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                cost[i][j] = min(cost[i][j] , cost[i][k] + cost[k][j]);
}

int query(int letter, int from, int to)
{
    return pref[letter][to + 1] - pref[letter][from];
}

void build_prefix()
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            pref[i][j + 1] = pref[i][j] + cost[int_value(str[j])][i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> str;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin >> cost[i][j];
    
    fill(minDP, minDP + n + 1, INF);
    floyd_warshall();
    build_prefix();

    for(int i = 0; i < m; i++) //Debug cost
    {
        for(int j = 0; j < m; j++)
            cout << cost[i][j] << " ";
        cout << endl;
    }

    for (int col = k + 1; col < n; col++)
        for(int row = 0; row < m; row++)
            dp[row][col] =  query(row, col - k, col);

    for(int i = 0; i < m; i++) //Computing DP states 
    {
        int temp1 = INF,temp2 = INF;
        for(int j = 1; j <= n; j++)
        {
            if(j >= k)
                temp1 = (minDP[j - k - 1] + query(i, j - k, j) );
            temp2 = dp[i][j - 1] + cost[int_value(str[j])][i];
    
            cout << temp1 << " " << temp2 << endl; //Printing the values of temp1 / temp2
            dp[i][j] = min(temp1,temp2);
            minDP[j] = min(minDP[j], dp[i][j]);
        }
    }

    for(int i = 0; i < n; i++) //Debug: Printing all values of minDP
        cout << minDP[i] << endl;
    return 0;
}
