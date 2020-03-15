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


int n,a[MAXN],ans,minLeft[MAXN], minRight[MAXN]; 
stack <pii> to_eval;
int main()
{
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        while(!to_eval.empty() && to_eval.top().first >= a[i])
        {
            cout << "Setting: " << to_eval.top().first << " to: " << a[i] << endl;
            cout << "Setting: " << to_eval.top().second << " to: " << i << endl;
            minLeft[to_eval.top().second] = i;
            to_eval.pop();
        }
        to_eval.push(pii(a[i], i + 1));
    }

    while(!to_eval.empty())
    {
        minLeft[to_eval.top().second] = n;
        to_eval.pop();
    } 


    for(int i = n; i > 0; i--)
    {
        while(!to_eval.empty() && to_eval.top().first >= a[i])
        {
            cout << "Setting: " << to_eval.top().first << " to: " << a[i] << endl;
            cout << "Setting: " << to_eval.top().second << " to: " << i << endl;
            minRight[to_eval.top().second] = i;
            to_eval.pop();
        }
        to_eval.push(pii(a[i], i - 1));
    }

    while(!to_eval.empty())
    {
        minRight[to_eval.top().second] = n;
        to_eval.pop();
    } 


    for(int i = 1; i <= n; i++)
        cout << minRight[i] << " " << minLeft[i] << endl;

    return 0;
}