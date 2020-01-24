#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> connections;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    return 0;
}