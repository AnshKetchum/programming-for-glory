#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 1500
#define TOTAL_COWS 3


void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int get_index(string cow_name)
{
    string cow_names [] = {"Bessie", "Elsie", "Mildred"};
    for(int i = 0; i < TOTAL_COWS; i++)
        if(cow_names[i] == cow_name)
            return i;
    return -1;
}

struct Entry
{
    int cow,change,day;
    Entry(){}
    Entry(string co, int ch, int da, char ad)
    {
        cow = get_index(co);
        change = ch;
        day = da;

        if(ad == '-')
            change *= -1;
    }
};

bool comp(Entry a, Entry b)
{
    return a.day < b.day;
}

int n,milk[TOTAL_COWS],ans;
Entry entries [MAXN];
vector<int> count_max()
{
    int mx = -1;
    vector<int> ret; 
    for(int i = 0; i < TOTAL_COWS; i++)
    {
        if(mx < milk[i])
        {
            ret.clear();
            mx = milk[i];
            ret.push_back(i);
        }
        else if(mx == milk[i])
            ret.push_back(i);
    }
    return ret;
} 


bool upd_ans(vector<int> ne, vector<int> p)
{
    if(p.size() != ne.size())
        return true;
    for(int i = 0; i < ne.size(); i++)
        if(p[i] != ne[i])
            return true;
    return false;
}

int main()
{
    setIO("measurement");
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int d,amt; string name; char ad; 
        cin >> d >> name >> ad >> amt;
        entries[i] = Entry(name, amt, d, ad);
    }

    sort(entries, entries + n,comp);
    for(int i = 0; i < n; i++)
    {
        Entry e = entries[i];
        vector<int> prev = count_max();
        milk[e.cow] += e.change;       
        ans += upd_ans(count_max(), prev);
    }

    cout << ans << endl;
    return 0;   
}