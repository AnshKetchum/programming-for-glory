#include <bits/stdc++.h>
using namespace std;
#define MAX_GROUPS 350000

int n,g;
set<int> groups [MAX_GROUPS];
set<int> ans;

void bfs()
{
    queue <int> enque;
    enque.push(1);

    while(!enque.empty())
    {
        int top = enque.front();
        enque.pop();

        ans.insert(top);
        //Erase all reference of current val
        for(int i = 0; i < g; i++)
        {
            if(groups[i].find(top) != groups[i].end())
            {
                groups[i].erase(top);
                if(groups[i].size() == 1)
                    enque.push(*(groups[i].begin()));
            }
        }

    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> g;
    for(int i = 0; i < g; i++)
    {
        int group_size; cin >> group_size;
        for(int j = 0; j < group_size; j++)
        {
            int a; cin >> a;
            groups[i].insert(a);
        }
    }

    bfs();
    bfs(); //Makes sure to add any missed nodes
    cout << ans.size() << endl;
    return 0;
}
