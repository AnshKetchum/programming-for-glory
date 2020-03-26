#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXS 7500
using namespace std;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

string s;
int dp[MAXS][MAXS],q;
bool is_palindrome[MAXS][MAXS],visited[MAXS][MAXS]; 

bool get_palindromes(int l , int r)
{   
    cout << l << " " << r << endl;
    if(l < 0 || r >= s.length())
        return false;
    if(visited[l][r])
        return is_palindrome[l][r];
    visited[l][r] = true;
    if(l == r)
        return true;
    is_palindrome[l][r] = get_palindromes(l + 1, r - 1) && (s[l] == s[r]); 
}

int main()
{
    setIO();
    cin >> s;

    for(int i = 0; i < s.length(); i++)
        dp[i][i] = 1;

   cout << get_palindromes(1, 2) << endl;

    /*computeDP(0, s.length() - 1);
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = 0; j < s.length(); j++)
            cout << dp[i][j];
        cout << endl;
    }

    while(q--)
    {
        int a,b; cin >> a >> b;
        cout << dp[a - 1][b - 1] << endl;
    } */

    return 0;
}
