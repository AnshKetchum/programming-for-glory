#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
using namespace std;


void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n,a[MAXN],ans1;
struct BIT
{
    int bit[MAXN];
    int query(int i)
    {       
        int sum = 0;
        for(; i; i -= (i & -i))
            sum += bit[i];
        return sum;
    }

    void update(int i)
    {
        for(; i <= n; i += (i & -i))
            ++bit[i];
    }   
};


int main()
{
    setIO("sleepy");
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = n; i >= 0; i--)
    {   
        ans1++;
        if(a[i] < a[i - 1])
            break;
    }

    ans1 = (n - ans1);
    cout << ans1 << endl;
    /*BIT bit;

    for(int i = ans1; i <= n; i++)
        bit.update(i);

    for(int i = 1; i <= ans1; i++)
    {
        cout << (ans1 - i) + bit.query(a[i]) << " ";
        bit.update(a[i]);
    }
    cout << endl; */
    return 0;
}
