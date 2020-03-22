#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,k,a[MAXN];
priority_queue <int> pq; 

int main()
{
	setIO();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    SegTree seg;
    for(int i = 1; i <= n; i++)
    {
        int bestSwitch = seg.rmq(i + 1, i + k + 1);
        if(a[i] < bestSwitch && a[i] < -pq.top())
            cout << a[i] << " ";
        else
        {
            while(!pq.empty() && -pq.top() < bestSwitch)
            {
                cout << -pq.top() << " ";
                pq.pop();
            }
            
            pq.push(a[i]);
            k--;
        }
        

    }

    return 0;
}

