#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n;
vector <string> a;


void format(string str)
{
    for(int i = 0; i < str.length(); i++)
        cout << (str[i] == '0' ? 'O' : 'X');
    cout << endl;
}

void comb()
{
    a.push_back("0");
    a.push_back("1");

    for(int i = 2; i < (1 << n); i = i << 1)
    {
        for(int j = i - 1; j >= 0; j--)
            a.push_back(a[j]);
        for(int j = 0; j < i; j++)
            a[j] = "0" + a[j];
        for(int j = i; j < 2 * i; j++)
            a[j] = "1" + a[j];
    }

    for(string s : a)
        format(s);
    format(a[0]);
}



int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    cin >> n;
    comb();
    return 0;
}