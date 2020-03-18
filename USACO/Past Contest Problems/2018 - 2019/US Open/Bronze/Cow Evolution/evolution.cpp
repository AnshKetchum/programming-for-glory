#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 1500
#define pb push_back 
using namespace std;
typedef vector <int> vi;

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}


int n;
string ans = "yes";
map <string, int> lookup;
vi characs, pops[MAXN];

bool bad_sets(int super, int sub)
{
    int oa = 0, ob = 0, both = 0;
    for(int i  = 0; i < n; i++)
    {
        bool a = false, b = false;
        for(int j = 0; j < pops[i].size(); j++)
        {
            if(pops[i][j] == super)
                a = true;
            else if(pops[i][j] == sub)
                b = true;
        }

        if(a && b)
            both++;
        else if(a)
            oa++;
        else if(b)
            ob++;
    }
    return (oa > 0 && ob > 0 && both > 0);
}

int main()
{
    setIO("evolution");
    cin >> n;    

    for(int i = 0; i < n; i++)
    {
        int k; cin >> k; 
        pops[i].resize(k);
        for(int j = 0; j < k; j++)
        {
            string s; cin >> s;
            if(lookup.find(s) == lookup.end())
            {
                lookup[s] = lookup.size(); 
                characs.pb(lookup[s]);
            }
            pops[i][j] = lookup[s];
        }
    }


    for(int i = 0; i < characs.size() && ans == "yes"; i++)
        for(int j = i + 1; j < characs.size() && ans == "yes"; j++)
            if(i != j  && bad_sets(characs[i], characs[j]))
                ans = "no";

    cout << ans << endl;
    return 0;
}