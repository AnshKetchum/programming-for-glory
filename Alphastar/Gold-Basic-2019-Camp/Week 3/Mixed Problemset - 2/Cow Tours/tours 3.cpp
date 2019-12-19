#include <bits/stdc++.h>
using namespace std;
#define INF 100000000.0
#define MAXN 200

typedef pair<int,int> pii;
bool connections[MAXN][MAXN],visited[MAXN];
double distances[MAXN][MAXN],diameters[MAXN],fieldDiams[MAXN];
double ans = INF;
int n,groups[MAXN];
pii points [MAXN];

double getDist(int i, int j)
{
    pii a = points[i], b = points[j];
    double dx = (a.first - b.first) * (a.first - b.first);
    double dy = (a.second - b.second) * (a.second - b.second);
    return sqrt(dx + dy);
}

void floyd_warshall()
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
}

void flood(int i, int group)
{
    if(visited[i])
        return;

    visited[i] = true;
    groups[i] = group;

    for(int j = 0; j < n; j++)
        if(connections[i][j])
            flood(j,group);

}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < n; j++)
            connections[i][j] = (s[j] == '1');
    }



    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
            {
                if(connections[i][j])
                    distances[i][j] = getDist(i,j);
                else
                    distances[i][j] = INF;
            }

    floyd_warshall();

    int g = 0;
    for(int i = 0; i < n; i++)
        if(!visited[i])
            flood(i,++g);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(distances[i][j] != INF)
                diameters[i] = max(diameters[i],distances[i][j]);
        fieldDiams[groups[i]] = max(fieldDiams[groups[i]],diameters[i]);
    }

    double bestDiam;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(groups[i] != groups[j])
            {
                bestDiam = diameters[i] + diameters[j]+getDist(i, j);

                if(bestDiam < fieldDiams[groups[i]])
                    bestDiam = fieldDiams[groups[i]];
                if(bestDiam < fieldDiams[groups[j]])
                    bestDiam = fieldDiams[groups[j]];

                ans = min(ans,bestDiam);
            }

    cout << fixed << showpoint << setprecision(6) << ans << endl;
    return 0;
}
