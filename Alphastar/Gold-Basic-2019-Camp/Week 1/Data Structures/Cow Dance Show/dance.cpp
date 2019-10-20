#include <bits/stdc++.h>
using namespace std;
#define MAX_COWS 15000
#define INF 1000000

int n,t_max,times[MAX_COWS];

bool possible(int k_val)
{
    priority_queue<int, vector<int>, std::greater<int> > onStage;

    for(int i = 0; i < n; i++)
    {
        if(onStage.size() < k_val)
            onStage.push(times[i]);

        else
        {
            int top = onStage.top();
            onStage.pop();
            top += times[i];
            onStage.push(top);
        }
    }

    while(onStage.size() > 1)
        onStage.pop();
    int totalTime = onStage.top();
    return totalTime <= t_max;
}

int binSearch(int l, int r)
{
    if(l == r)
        return l;
    int mid = (l + r) / 2;

    if(possible(mid))
        return binSearch(l,mid);
    else
        return binSearch(mid + 1,r);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t_max;
    for(int i = 0; i < n; i++)
        cin >> times[i];
    cout << binSearch(0,INF) << endl;
    return 0;
}
