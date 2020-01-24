#include <fstream>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

static pair<int, int> medians(const int *Z, int N)
{
    int s[N];
    copy(Z, Z + N, s);
    nth_element(s, s + N / 2, s + N);
    if (N & 1) return make_pair(s[N / 2], s[N / 2]);
    else return make_pair(*max_element(s, s + N / 2), s[N / 2]);
}

static int cost_of(int x, int y, int *X, int *Y, int N)
{
    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(X[i] - x) + abs(Y[i] - y);
    return cost;
}

int main()
{
    int N;
    pair<int, int> xlh, ylh;
    int opts;
    int cost;
    ifstream in("newbarn.in");
    ofstream out("newbarn.out");
    in >> N;
    int X[N], Y[N];

    for (int i = 0; i < N; i++)
        in >> X[i] >> Y[i];
    xlh = medians(X, N);
    ylh = medians(Y, N);
    opts = (xlh.second - xlh.first + 1) * (ylh.second - ylh.first + 1);
    for (int i = 0; i < N; i++)
    {
        if (X[i] >= xlh.first && X[i] <= xlh.second
            && Y[i] >= ylh.first && Y[i] <= ylh.second)
            opts--;
    }
    cost = cost_of(xlh.first, ylh.first, X, Y, N);
    if (opts == 0)
    {
        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, -1, 0, 1};
        int costs[4];
        for (int d = 0; d < 4; d++)
            costs[d] = cost_of(xlh.first + dr[d], ylh.first + dc[d], X, Y, N);
        cost = *min_element(costs, costs + 4);
        opts = count(costs, costs + 4, cost);
    }
    out << cost << " " << opts << "\n";
    return 0;
}