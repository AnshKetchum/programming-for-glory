/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: fracdec
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500000
#define UNCOMPUTED -1
int n,d,remainders[MAXN];
string str = "";

char toChar(int c)
{
    return c + '0';
}

int main()
{

    ifstream cin("fracdec.in");
    ofstream cout("fracdec.out");
    cin >> n >> d;

    fill(remainders, remainders + MAXN - 5,UNCOMPUTED);
    string st = to_string(n / d);
    cout << st << ".";

    int cnt = 0;
    while(true)
    {
        n %= d;
        if(n == 0)
        {
            if(cnt == 0)
                str += "0";
            break;
        }

        if(remainders[n] != UNCOMPUTED)
        {
            string repetition = str.substr(remainders[n],str.length());
            str = str.substr(0,remainders[n]) + "(" + repetition + ")";
            break;
        }

        remainders[n] = cnt;
        cnt++;
        n *= 10;
        str += toChar(n / d);
    }

    int cnts = st.length() + 1; //1 for the '.' which isn't accounted
    for(int i = 0; i < str.length(); i++)
    {
        cnts++;
        cout << str[i];
        if(cnts % 76 == 0)
            cout << endl;
    }
    if(cnts % 76 != 0)
        cout << endl;

    return 0;
}
