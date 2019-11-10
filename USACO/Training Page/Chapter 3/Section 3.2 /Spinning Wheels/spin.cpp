/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: spin
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_DEGREE 720 //Overkill to prevent out of bounds
#define ACTUAL_MAX_DEGREE 360
#define wdp wheel_list[i].dp
#define spd wheel_list[i].speed
#define wlist wheel_list[i].wheels
#define INF 100000000

typedef pair<int,int> pii;
struct Wheel
{
    int speed;
    vector <pii> wheels;
};

int ans = INF,dp[MAX_DEGREE];
Wheel wheel_list [5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("spin.in");
    ofstream cout("spin.out");

    for(int i = 0; i < 5; i++)
    {
        int n;
        cin >> spd >> n;
        for(int j = 0; j < n; j++)
        {
            int a,b; cin >> a >> b;
            wlist.push_back(pii(a,b));
        }
    }

    for(int i = 0; i < 361; i++) 
    {
        fill(dp, dp + MAX_DEGREE - 1, 0);
        for(int k = 0; k < 361; k++) 
        {
            for(int j = 0; j < 5; j++)
            {
                for (pii wedge : wheel_list[j].wheels)
                {
                    int start = (wedge.first + wheel_list[j].speed * i ) % 360;
                    if (k >= start && k - start <= wedge.second || k + 360 - start <= wedge.second) 
                    {
                        dp[k]++;
                        break;
                    }
                }
            }

            if (dp[k] == 5) 
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << "none" << endl;
}