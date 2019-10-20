/*****
ID: ansh1221
LANG: C++
PROG: kimbits
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXL 35

int n,l,q;
vector <string> dp [MAXL][MAXL];
int main()
{
    ifstream cin("kimbits.in");
     ofstream cout("kimbits.out");
    cin >> n >> l >> q;

    for(int i = 0; i < MAXL; i++)
    {
        dp[i][0].push_back("");
        dp[0][i].push_back("");
    }

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= i; k++)
        {
            cout << i << " " << k << endl;
            for(string s : dp[i - 1][k])
            {
                cout << "Adding " << s + '0' << endl;
                dp[i][k].push_back(s + '0');
            }

            cout << "Switch States" << endl;
            for(string s : dp[i - 1][k - 1])
            {
                cout << "Adding " << s + '1' << endl;
                dp[i][k].push_back(s + '1');
            }
        }
    }


    int s = dp[n][l].size() -1;
   cout << dp[n][l][s] << endl;
   return 0;
}