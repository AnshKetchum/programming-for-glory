/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: milk2
**/
#include <bits/stdc++.h>
using namespace std;

int n,maxMilkTime,maxLostTime;
pair <int,int> intervals[5002];

void mergeIntervals()
{
    pair <int,int> curInterval = intervals[0]; //Getting the first interval
    for(int i = 1; i < n; i++)
    {
        if(intervals[i].first > curInterval.second)
        {
            int timeInBetween = intervals[i].first - curInterval.second;
            maxLostTime = max(timeInBetween , maxLostTime); //Getting the max lost time

            int intervalMilkTime = curInterval.second - curInterval.first;
            maxMilkTime = max(intervalMilkTime , maxMilkTime); //Getting the max milked time
            curInterval = intervals[i]; //Expanding our interval
        }
        else
            curInterval.second = max(curInterval.second,intervals[i].second); //Expanding our interval
    }
    maxMilkTime = max(maxMilkTime,curInterval.second - curInterval.first); //Taking max of the last value that wasn't covered by the loop
}

int main()
{
    ifstream cin ("milk2.in");
    ofstream cout ("milk2.out");

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> intervals[i].first >> intervals[i].second;
    sort(intervals, intervals + n); //Sorts by pair.first
    mergeIntervals(); //Merging all of the intervals

    cout << maxMilkTime << " " << maxLostTime << endl;
    return 0;
}
