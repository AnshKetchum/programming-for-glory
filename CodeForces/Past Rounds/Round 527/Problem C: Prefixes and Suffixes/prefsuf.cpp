#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 1500 
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,len[MAXN];
vector <string> longest;
string strings[MAXN], op,op2,ans;

void combine(string a, string b)
{
    string prefa = a.substr(0, n - 2);
    string suba  = a.substr(1,n - 2);

    string prefb = b.substr(0, n - 2);
    string subb  = b.substr(1, n - 2);

    op = a[0] + prefb + b[b.length() - 1] + "";
    op2 = b[0] + prefa + a[a.length() - 1] + "";
}

bool suffix(string s, string op)
{
    return (op.substr(op.length() - s.length(), s.length()) == s);
}

bool prefix(string s, string op)
{
    return (op.substr(0,s.length()) == s);
}

char solve(string s, string op)
{
    if(prefix(s,op))
    {
        if(suffix(s,op) && len[s.length()] < 0)
        {
            len[s.length()]++;
            return 'S';
        }

        len[s.length()]--;
        return 'P';
    }
    len[s.length()]++;
    return 'S';
}

bool test(string op)
{
    fill(len, len + 3 * n, 0);

    ans = "";
    for(int i = 0; i < 2 * n - 2; i++)
        ans.push_back(solve(strings[i], op));

    for(int i = 0; i < 2 * n - 2; i++)
    {
        if(len[strings[i].length()] != 0 && prefix(strings[i], op) && suffix(strings[i], op))
        {
            if(len[strings[i].length()] < 0)
            {
                ans[i] = 'S';
                len[strings[i].length()]++;
            }
            else if(len[strings[i].length()] > 0)
            {
                ans[i] = 'P';
                len[strings[i].length()]--;
            }
        }
    }

    for(int i = 0; i < 2 * n - 2; i++)
        if(len[strings[i].length()] != 0)
            return false;
    return true;
}

int main()
{
	setIO();
    cin >> n;
    for(int i = 0; i < 2 * n - 2; i++)
    {
        cin >> strings[i];
        if(strings[i].length() == n - 1)
            longest.push_back(strings[i]);
    }

    combine(longest[0], longest[1]);

    if(!test(op))
        test(op2);
    cout << ans << endl;
    return 0;
}

