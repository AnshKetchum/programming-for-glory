#include <bits/stdc++.h> //Thanks, Bavarchi for the coding help
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 1500
#define INF 2000000000000
typedef long long ll;

void setIO(string name) //IO FROM MR QI
{
	FASTIO
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

ll n,k,x;

ll sum(ll d) 
{
    return ((d) * (d + 1)) / 2;
}

bool can_decelerate(ll speed, ll pos)
{
    ll dist = sum(speed) - sum(x);
    return (pos + dist) < k;
}

ll solve()
{
    ll cnt = 0, speed = 0, pos = 0;
    while(pos < k)
    {
        if(speed < x)
            speed++;
        else
        {
            if(can_decelerate(speed + 1,pos))
                speed++;
            else if(can_decelerate(speed,pos))
                speed = speed;
            else
                speed--;
        }

        pos += speed;
        cnt++;
    }   
    return cnt;
}


int main()
{
    setIO("race");
    cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        cout << solve() << endl;
    }
    return 0;
}