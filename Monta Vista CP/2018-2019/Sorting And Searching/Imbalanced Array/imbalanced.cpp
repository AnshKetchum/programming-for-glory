#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500000
typedef pair <int,int> pii;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


int n,a[MAXN],ans; 
stack <pii> to_eval;
set <pii> visited;

void add(pii a)
{
    to_eval.push(a);
}

void clear(int sn, int st) 
{ 
    while(!to_eval.empty()) 
    {
        cout << "Removing: " << to_eval.top().first << " " << to_eval.top().second << endl;
        //ans += (sn) * abs(to_eval.top().second - st) * to_eval.top().first;
        to_eval.pop();
    }
}

int main()
{
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    //If the min is lower index of the range
    for(int i = 1; i <= n; i++)
    {
        while(!to_eval.empty() && to_eval.top().first < a[i])
        {
            cout << "LeftMin Index: " << to_eval.top().second << " " << i  << endl;
            cout << "Value: " << a[to_eval.top().second] << endl;
            ans -= (to_eval.top().first) * (i - to_eval.top().second);
            to_eval.pop();
        }
        add(pii(a[i],i));
    }

    cout << ans << endl;
    return 0;
}