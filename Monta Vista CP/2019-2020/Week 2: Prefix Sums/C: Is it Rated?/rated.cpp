#include <bits/stdc++.h>
using namespace std;
#define MAXN 155000
typedef pair<int,int> pii;

int n,same_counter,uns_start[MAXN],uns_end[MAXN];
pii start_ratings[MAXN], end_ratings[MAXN];

string solve()
{
    for(int i = 0; i < n; i++) //Count number of IDs that have changed.
        if(uns_start[i] != uns_end[i])
            return "rated";

    for(int i = 0; i < n; i++)
        if(uns_start[i] != start_ratings[i].first)
            return "unrated";
    return "maybe";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> start_ratings[i].first >> end_ratings[i].first;
        uns_start[i] = start_ratings[i].first;
        uns_end[i] = end_ratings[i].first;
        start_ratings[i].second = end_ratings[i].second = i;
    }

    sort(start_ratings, start_ratings + n,greater<pii>()); //Sort by rating
    sort(end_ratings, end_ratings + n,greater<pii>());

    cout << solve() << endl;
    return 0;
}