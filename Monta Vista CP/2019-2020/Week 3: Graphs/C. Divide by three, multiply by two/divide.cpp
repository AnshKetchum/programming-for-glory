#include <bits/stdc++.h>
using namespace std;
#define MAXN 150

typedef long long ll;
ll n,a[MAXN],ans[MAXN];
bool visited[MAXN],found_answer;

void dfs(ll index, ll cnt) 
{
    if(cnt >= n) //Found the end? Cool, print it out, and be done!
    {
        for(int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
        exit(0);
    }

    if(visited[index])
        return;
    for(int i = 1; i <= n; i++) //Find valid values from current to recurse to 
        if(i != index && ((double)a[i] / 2 == (double)a[index] || a[i] * 3 == a[index]) && !visited[i])
        {
            visited[index] = true;
            ans[cnt + 1] = a[i];

            dfs(i,cnt + 1);
            
            visited[index] = false;
        }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        ans[1] = a[i];
        dfs(i,1);
    }

   return 0;
}