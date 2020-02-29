#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,ans;
bool diff [MAXN];
string a,b;
int main()
{
    setIO("breedflip");
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        diff[i] = (a[i] != b[i]);
    ans = diff[0];
    for(int i = 1; i < n; i++)
        if(diff[i] && !diff[i - 1])
            ans++;
    cout << ans << endl;
    return 0;
}