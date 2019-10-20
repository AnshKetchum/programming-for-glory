#include <bits/stdc++.h>
using namespace std;
#define MAX_GEARS 1500
#define INF 1000000000
#define STARTING_SPEED 10000

typedef pair<int,int> pii;
int n,from[MAX_GEARS], destInd;
double speed[MAX_GEARS],ans;
pii destination;

struct Gear
{
    pii coords;
    double radius;
};
Gear gears[MAX_GEARS];

double getDist(int i, int j)
{
    pii a = gears[i].coords, b =  gears[j].coords;
    return sqrt(((double)a.first - (double)b.first) * ((double)a.first - (double)b.first) + ((double)a.second - (double)b.second) * ((double)a.second - (double)b.second));
}

double getSpeed(double r1, double r2, double speed)
{
    return (double)speed * (double)r1 / (double)r2;
}

bool inRange(int i, int j)
{
    double radSum = (double)gears[i].radius + (double)gears[j].radius;
    return getDist(i,j) * getDist(i,j) == (radSum * radSum);
}


void dikjstra(int starting)
{
    bool visited[MAX_GEARS] = {false};
    queue <int> best_edges;
    best_edges.push(starting);

    while(!best_edges.empty())
    {
        int node = best_edges.front();
        best_edges.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        for(int i = 0; i < n; i++)
        {
            if(inRange(node,i) && !visited[i] && speed[i] == INF)
                {
                    from[i] = node;
                    speed[i] = getSpeed(gears[node].radius,gears[i].radius,speed[node]);
                    best_edges.push(i);
                }
        }
    }

    int v = destInd;
    while(v != -1)
    {
        ans += abs(speed[v]);
        v = from[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(speed, speed + MAX_GEARS - 5,INF);

    cin >> n >> destination.first >> destination.second;
    for(int i = 0; i < n; i++)
    {
        cin >> gears[i].coords.first >> gears[i].coords.second >> gears[i].radius;
        if(gears[i].coords == destination)
            destInd = i;
    }
    for(int i = 0; i < n; i++)
        if(gears[i].coords.first == 0 && gears[i].coords.second == 0)
        {
            from[i] = -1;
            speed[i] = STARTING_SPEED;
            dikjstra(i);
            break;
        }

    cout << (int)ans << endl;
    return 0;
}
