/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: friday
**/
#include <bits/stdc++.h>
using namespace std;

map <int,int> occurences;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("friday.in","r",stdin);
    freopen("friday.out", "w",stdout);

//                 Null Jan, Feb,Mar,Apr,May,Jun,Jul, Aug,Sep, Oct,Nov,Dec
    int months[] = {0 ,31, 28, 31, 30, 31, 30, 31,  31, 30,  31, 30, 31 };
    string days[] = {" ","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}; ///Debugging
    int n; cin >> n;

    int lastYear = 1900 + n, lastDay = 0; // 1 -> Monday Sunday -> 7
    for(int currentYear = 1900; currentYear < lastYear; currentYear++)
    {
        if(currentYear % 100 == 0 && currentYear % 400 == 0)   //If the year is a century year and it is divisible by 400, set it to leap year
                months[2] = 29;

        else if(currentYear % 4 == 0 && currentYear % 100 != 0)  //If the year is divisible by 4 and is not a century year, set it to leap year
                months[2] = 29;

        for(int currentMonth = 1; currentMonth <= 12; currentMonth++) //Checking every month, and day
        {
            for(int currentDay = 1; currentDay <= months[currentMonth]; currentDay++)
            {
                if(lastDay == 7) lastDay = 0;
                lastDay++;
                if(currentDay == 13)
                    occurences[lastDay]++;
            }
        }
    if(months[2] == 29) months[2] = 28;

    }
    cout << occurences[6] << " " << occurences[7]; ///Saturday, Sunday
    for(int i = 1; i <= 5; i++) ///Monday -> Friday
        cout << " "  << occurences[i];
    cout << endl;

    fclose(stdout);
    fclose(stdin);
    return 0;
}
