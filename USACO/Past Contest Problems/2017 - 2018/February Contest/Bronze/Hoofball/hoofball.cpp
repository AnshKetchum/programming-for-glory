#include <bits/stdc++.h>
using namespace std;
#define MAXN 500

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,a[MAXN], to[MAXN],ans;
bool processed[MAXN];

int dist(int f, int t){ return abs(a[f] - a[t]); }
void find_parent(int node)
{
    int ptr = 0;
    for(int i = 1; i <= n; i++)
        if(i != node)
            if( (dist(i,node) < dist(ptr,node)) || (dist(i,node) == dist(ptr,node) && i - node < ptr - node) )
                ptr = i;
    to[node] = ptr;
}

bool never_given_ball(int node)
{
    for(int i = 1; i <= n; i++)
        if(to[i] == node)
            return false;
    return true;
}

void give_ball(int node)
{
    while(true)
    {
        if(node == 0 || processed[node])
            break;
        processed[node] = true;

        if(to[to[node]] == node)
        {
            processed[to[node]] = true;
            break;
        }
        node = to[node];
    }
    ans++;
}

int main()
{
    setIO("hoofball");
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i]; 
    a[0] = 1e9;
    for(int i = 1; i <= n; i++)
        find_parent(i);

    for(int i = 1; i <= n; i++)
        if(!processed[i] && never_given_ball(i))
            give_ball(i);
    for(int i = 1; i <= n; i++)
        if(!processed[i])
            ans++;
    

    cout << ans << endl;
    return 0;
}