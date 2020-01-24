#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 2500

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void print_set(multiset<int> m)
{
    cout << "[";
    for(int y : m)
        cout << y << ",";
    cout << "end]" << endl;
}


int n,k,a[MAXN],ret[MAXN];
multiset<int> ms;
int main()
{   
    setIO("berries");
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    for(int i = 0; i < k; i++)
        ms.insert(a[i]);

    while(true)
    {
        int beg = *(ms.rbegin());
        int div = 1;

        for(int x : ms)
        {
            if(beg / (div + 1) <= x)
                break;
            div++;
        }

        if(div == 1)
            break;

        ms.erase((--ms.end()));
        for(int i = 1; i <= div - 1; i++)
        {        
            ms.erase(ms.begin());
            ms.insert(beg / div);
        }
        ms.insert(beg / div);
    }     

    int i = 0,sum = 0; 
    for(auto it : ms)
    {
        if(i >= k / 2)
            break;
        sum += it;
        i++;
    }
    cout << sum << endl;
}