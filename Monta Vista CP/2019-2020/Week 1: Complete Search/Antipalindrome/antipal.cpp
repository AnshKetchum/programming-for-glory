#include <bits/stdc++.h>
using namespace std;

string str,s;
int ans;

bool is_palindrome(int l, int r)
{
     s = str.substr(l,r);
     for(int i = 0; i < s.length(); i++)
        if(s[i] != s[s.length() - i - 1])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    for(int l = 0; l < str.length(); l++)
        for(int r = 1; r + l <= str.length(); r++)
            if(!is_palindrome(l,r))
            {
               // cout << "Not Palindrome from Range: " << l << " to " << (l + r) << endl;
                
               // cout << s << endl;
                int len = s.length();
                ans = max(ans, len);    
            }
    cout << ans << endl;
    return 0;
}