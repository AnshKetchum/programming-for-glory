/*****
ID: ansh1221
LANG: C++
PROG: kimbits
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXL 50
#define MAX_BITS 32

typedef long long ll;
ll n,l,q,dp[MAXL][MAXL],ind,ones;
int main()
{
    ifstream cin("kimbits.in");
    ofstream cout("kimbits.out");
    cin >> n >> l >> q;
    ll temp = q - 1;
    q--;

    for(int i = 0; i <= MAX_BITS; i++)
        dp[0][i] = 1;
    for(int i = 1; i <= MAX_BITS; i++)
        for(int j = 0; j <= MAX_BITS; j++)
            dp[i][j] = (j ? dp[i - 1][j] + dp[i - 1][j - 1] : 1);
    
    ones = l;
    for(int i = n; i > 0; i--)
    {
        ind = dp[i - 1][ones];
        cout << (ind <= q ? "1" : "0");
        ones = (ind <= q ? ones - 1 : ones);
        q = (ind <= q ? q - ind : q);
    } 
    cout << endl;
   return 0;
}