#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

//Printing Debug Functions for easy reading
#define BREAKOUTPUT for(int i = 0; i < 100; i++) cout << "*";
#define NEWLINE cout << "\n\n\n";
#define STOPDEBUG(c) c ? exit(1) 
#define UNWANTED -10000
#define BREAKDEBUG BREAKOUTPUT NEWLINE

/*
Logic: Let dp(i) represent the maximum sum of skill levels. Therefore, the answer will be the dp value at the 
Nth index - dp(N). 

How can we calculate dp(i) ? Suppose we want to create a team of size D (D <= K). In order to maximize the value of 
a team with size D, we must find the max over the range [i - D, i] and multiply it by the total number of values.
(i - D + 1). Finally, we need the skill level that we can get before the range, which is represented by the previous dp
value. There is no base case, so the algorithm is simple.

Final Complexity: O(NKlogN + 2N) or O(NKlogN)
*/

int n,k,dp[MAXN],s[MAXN],segmentTree[2 * MAXN];

int getInclusive(int i, int j) //Returns the inclusive sum of all values i and j
{
    return max(i,j) - min(i,j) + 1;
}

int main()
{
    ifstream cin("teamwork.in"); //Opening Input / Output
    ofstream cout("teamwork.out");

    cin >> n >> k;
    for (int i = 1; i <= n; i++) //Reading in from input formal specified in problem
        cin >> s[i];

    for(int i = 1; i <= n; i++) //Implementation of logic above 
    {
        int bestValue = s[i];
        for(int j = i; j > 0 && getInclusive(i,j) <= k; j--)
        {
            bestValue = max(bestValue,s[j]);
            dp[i] = max(dp[i], dp[j - 1] + bestValue * getInclusive(i,j));  
        }
    }
    cout << dp[n] << endl;
    return 0;
}