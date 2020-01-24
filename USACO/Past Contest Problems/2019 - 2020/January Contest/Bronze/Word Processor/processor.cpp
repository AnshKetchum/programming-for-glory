#include <bits/stdc++.h> //Thanks, Bavarchi :)
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 500

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,k,cur;
string wd = "";
int main()
{
    setIO("word");
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        string word; cin >> word;
        if((int)(word.size()) + cur > k)
        {
            cout << wd.substr(0,wd.length() - 1) << endl;
            wd = "";
            cur = 0;
        }
        wd += word + " ";
        cur += word.length();
    }

    if(wd.length() > 0)
        cout << wd.substr(0,wd.length() - 1) << endl;
    return 0;
}