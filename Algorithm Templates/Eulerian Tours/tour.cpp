#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

int n; //# of edges
bool visited[MAXN];
vector <int> connections[MAXN],euler_path;

void eulerp(int node)
{
    visited[node] = true;
    euler_path.push_back(node);
    for(int x : connections[node])
        if(!visited[x])
        {
            eulerp(x);
            euler_path.push_back(node);
        }
}

void print_euler()
{
    for(int node : euler_path)
        cout << node << " ";
    cout << endl;
}

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

    //Assuming the root is node 1:
    eulerp(1);
    print_euler();
    return 0;
}