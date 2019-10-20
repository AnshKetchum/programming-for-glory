#include <bits/stdc++.h>
using namespace std;

string str;
int cnt [26];
char best = 'a';

char to_char(int c)
{
    char a = 'a'; a += c;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    for(int i = 0; i < str.length(); i++)
        cnt[(str[i] - 'a')]++;
    for(int i = 0; i < 26; i++)
        if(cnt[i] > cnt[(best - 'a')])
            best = to_char(i);
    cout << best << "" << endl;
    cout << str << endl;

    return 0;
}