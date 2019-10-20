#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

typedef pair<int,int> pii;
int n,paints[MAXN],most_overlap, ref_to_index[MAXN],running_best = 1;
set <int> distinct_paints;
vector <pii> intervals;

bool has_overlap(pii tot, pii b)
{
    if(tot.second >= b.first)
        return true;
    if(b.second >= tot.first && tot.first >= b.first)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> paints[i];
        
        if(distinct_paints.find(paints[i]) != distinct_paints.end())
            intervals[ref_to_index[paints[i]]].second = i;
        else
        {
            distinct_paints.insert(paints[i]);
            intervals.push_back(pii(i,i));
            ref_to_index[paints[i]] = intervals.size() - 1;
        }
    }
    sort(intervals.begin(),intervals.end());

    /*cout << "Distinct Elements: " << distinct_paints.size() << endl;
    for(int i = 0; i < intervals.size(); i++)
        cout << intervals[i].first << " " << intervals[i].second << endl; */

    pii total_interval = intervals[0];
    
    for(int i = 1; i < intervals.size(); i++)
    {   
       // cout << "Running Best: " << running_best << endl; 
        if(has_overlap(total_interval,intervals[i]))
        {
         //   cout << "Overlap Between [" << total_interval.first << "," << total_interval.second << "] and [" << intervals[i].first << "," << intervals[i].second <<"]" << endl;
            running_best++;
        }
        else 
        {
            most_overlap = max(most_overlap,running_best);
            running_best = 1;
        }
        total_interval.second = intervals[i].second;
        most_overlap = max(most_overlap,running_best);

    }
    most_overlap = max(most_overlap,running_best);


    int s = distinct_paints.size();
    //cout << "Most Overlap Found: " << most_overlap << endl;
    cout << min(most_overlap,s) << endl; 
    return 0;
}