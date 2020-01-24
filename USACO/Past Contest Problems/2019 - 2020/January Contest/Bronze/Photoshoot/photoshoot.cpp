#include <bits/stdc++.h> //Thanks to Bavarchi for helping out with the code!
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 1005

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,b[MAXN];
string ans;
bool used[MAXN]; 

void works(int start)
{
    int last = start;
    string tm = "";
    fill(used, used + MAXN - 1, false);

    tm += to_string(start) + " ";
    for(int i = 0; i < n - 1; i++)
    {
        int nv = b[i] - last;
        if(nv >= MAXN || used[nv] || nv > n || nv < 0)
            return;
        
        used[nv] = true;
        tm += to_string(nv) + " ";
        last = nv;
    }

    if(n == 2)
        tm += to_string(b[0] - last);
    else
        tm = tm.substr(0, tm.length() - 1);
    
    if(tm < ans)
        ans = tm;

}


int main()
{
    setIO("photo");
    cin >> n;
    for(int i = 0; i < n - 1; i++)
        cin >> b[i];

    for(int i = 0; i < MAXN * 10; i++)
        ans += "9";

    for(int i = 1; i < b[0]; i++)
        works(i); 

    cout << ans << endl;
    return 0;
}