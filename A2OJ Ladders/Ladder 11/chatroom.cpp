#include <bits/stdc++.h>
using namespace std;
string s;
int j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    for(int i = 0; i < s.length() && j < 5; i++)    
        if(s[i] == "hello"[j])
            j++;
    cout << (j == 5 ? "YES" : "NO") << endl;
    return 0;
}