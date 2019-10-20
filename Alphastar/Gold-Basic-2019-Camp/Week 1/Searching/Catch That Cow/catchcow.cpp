#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

/*
In this question, note that the farthest one can go is
2 * K, since you can multiply K twice. If N > 2 * K, then the rightbound 
becomes N. 

The left bound is 0. BFS in between all the values, trying all possible states.


*/

int n,k,ans = 1000000,right_bound;
typedef pair<int,int> pii;
bool visited [MAXN];
void bfs() //Applying a BFS to try all possible states 
{
    queue <pii> enque;
    enque.push(pii(n,0));

    while(!enque.empty())
    {
        pii top = enque.front();
        enque.pop();

        if(top.first == k)
            ans = min(ans,top.second);

        if(visited[top.first] || top.first < 0 || top.first > right_bound)
            continue;

        visited[top.first] = true;

        int change [] = {top.first, -1, 1};
        for(int i = 0; i < 3; i++)
        {
            int c_x = change[i] + top.first;
            if(c_x < 0 || c_x > right_bound || visited[c_x])
                continue;
            //cout << "Pushing: " << c_x << " at time: " << top.second + 1 << endl;
            enque.push(pii(c_x,top.second + 1));
        }
    }

}


int main()
{
    cin >> n >> k;
    right_bound = max(2 * k, n);
    bfs();

    cout << ans << endl;
    return 0;
}
