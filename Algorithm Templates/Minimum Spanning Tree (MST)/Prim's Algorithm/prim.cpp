#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000 //Toggle this value to prevent array out of bounds
#define INF 1000000000000 //Make sure value is less than this representation of Infinity

typedef pair<int,int> pii;
int edges[MAXN][MAXN],n,cost[MAXN]; //N is number of nodes
bool visited[MAXN]; //Visited Array
vector <int> node_order; //Stores the order
priority_queue <pii> best_edge;


void printTreeOrder()
{
    for(int i = 0; i < node_order.size(); i++)
        cout << node_order[i] << " ";
    cout << endl;
}

int cnt = 0;
void build_mst(int start) // 0 INDEXED
{
    node_order.clear();
    for(int i = 0; i < n; i++)
        cost[i] = INF,visited[i] = false;

    //Set Starting Node to 0
    cost[start] = 0;
    best_edge.push(pii(0,start));

    while(node_order.size() < n && best_edge.size() > 0) //While we haven't seen all nodes
    {
        int closest = best_edge.top().second;
        best_edge.pop();

        if(visited[closest])
            continue;

        node_order.push_back(closest); //0 indexed
        visited[closest] = true;
        for(int i = 0; i < n && node_order.size() < n; i++)
        {
            if(!visited[i])
            {
                cost[i] = min(cost[i],edges[closest][i]);
                best_edge.push(pii(-edges[closest][i],i)); //Need to negate since priority queue sorts in greatest order, and we need in least order
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) //Gets all weights
        for(int j = 0; j < n; j++)
            cin >> edges[i][j];
    return 0;
}


