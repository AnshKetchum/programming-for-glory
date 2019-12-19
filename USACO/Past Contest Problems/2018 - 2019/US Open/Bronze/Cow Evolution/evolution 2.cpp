#include <bits/stdc++.h>
using namespace std;
#define MAXN  25
#define fnd(x,k) characs[x].find(k) != characs[x].end()

int n,r;
set <string> every_charac;
set <string> characs [MAXN];
bool possible;

bool is_subset(int i, int j) //Check if characs[i] contains characs[j]
{
    set <string> a = characs[i];
    set <string> b = characs[j];

    for(string t : a)
    {
        bool fnd = false;
        for(string s : b)
            if(t == s)
            {
                fnd = true;
                break;
            }
        if(!fnd)
            return false;
    }
}   

bool has_intersect(int i, int j)
{
    int ac = 0,bc = 0,intc = 0;
    for(string k : every_charac)
    {
        if(fnd(i,k))
            ac++;
        if(fnd(j,k))
            bc++;
        if(fnd(i,k) && fnd(j,k))
            intc++;
    }   
    return ac > 0 && bc > 0 && intc > 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("evolution.in");
    cin >> n; 
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        for(int j = 0; j < a; j++)
        {
            string s; cin >> s;
            characs[i].insert(s);
            every_charac.insert(s);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && !is_subset(i,j) && !is_subset(j,i) && has_intersect(i,j))
                possible = false;

    cout << (possible ? "yes" : "no") << endl;
    return 0;
}