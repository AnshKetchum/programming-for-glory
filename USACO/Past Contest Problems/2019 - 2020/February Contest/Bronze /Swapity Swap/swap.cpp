#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;

void setIO(string name) 
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,k;
vi seq,ans;
pii ranges[MAXN];
vector <vi>  orderings;

bool good()
{
    for(int i = 0; i < seq.size(); i++)
        if(seq[i] != i)
            return false;
    return true;
}

void reverse_seq(int f, int t)
{
    int sz = 0;
    vi nums;
    for(int i = f; i <= t; i++)
        nums.pb(seq[i]);
    for(int i = 0; i < nums.size(); i++)
        seq[t - i] = nums[i];
}

int main()
{
    setIO("swap");
    cin >> n >> k >> a.first >> a.second >> b.first >> b.second;
    seq.pb(0);
    for(int i = 1; i <= n; i++)
        seq.pb(i);    

    orderings.pb(seq);
    for(int i = 1; i <= k; i++)
    {
        reverse_seq(a.first, a.second);
        reverse_seq(b.first,b.second);
        if(good())
        {
            ans = orderings[k % i];
            break;
        }
        orderings.pb(seq);
        ans = seq;
    }
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl; 
    return 0;
}