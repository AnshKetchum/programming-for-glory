#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500

int n,p[MAXN];


int answer_query(int start)
{
    int hole_count [MAXN];
    fill(hole_count, hole_count + n + 5, 0);

    int node = start;
    while(hole_count[node] < 2) 
    {
        hole_count[node]++;
        node = p[node];
    }
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        cout << answer_query(i) << " ";
    cout << endl;
    return 0;
}