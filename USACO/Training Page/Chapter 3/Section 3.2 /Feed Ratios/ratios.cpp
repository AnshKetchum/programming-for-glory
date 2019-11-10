/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: ratios
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_RATIO 110
#define SUM(a,b,c) a + b + c
#define rl ratio_list
#define INF INT_MAX

struct Ratio
{
    int a,b,c;

    Ratio(){}

    Ratio(int a1,int a2,int a3)
    {
        a = a1; 
        b = a2;
        c = a3;
    }
};

int com_goal,sum = INF,temp_sum,temp_goal;
Ratio goal,ans,rl[3],mults; 

bool found_factor(int x, int y, int z)
{
    Ratio r4 = Ratio(SUM(rl[0].a * x,rl[1].a * y,rl[2].a * z),SUM(rl[0].b * x,rl[1].b * y,rl[2].b * z),SUM(rl[0].c * x,rl[1].c * y,rl[2].c * z));
    
    for(int i = 1; i <= MAX_RATIO; i++)
       if(goal.a * i == r4.a && goal.b * i == r4.b && goal.c * i == r4.c)
       {
           mults = Ratio(x,y,z);
           temp_sum = x + y + z;
           temp_goal = i;
           return true;
       }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("ratios.in");
    ofstream cout("ratios.out");
    cin >> goal.a >> goal.b >> goal.c;

    for(int i = 0; i < 3; i++)
        cin >> rl[i].a >> rl[i].b >> rl[i].c;

    
    for(int i = 0; i <= MAX_RATIO; i++)
        for(int j = 0; j <= MAX_RATIO; j++)
            for(int k = 0; k <= MAX_RATIO; k++)
                if(found_factor(i,j,k) && temp_sum < sum)
                {
                    ans = mults;
                    sum = temp_sum;
                    com_goal = temp_goal;
                } 
    if(sum == INF)
        cout << "NONE" << endl;
    
    else
        cout << ans.a << " " << ans.b << " " << ans.c << " " << com_goal << endl;
}