/**
 * Algo: Pick the first K pancakes out of order (if their position is not equal to the lexicographically optimal position)
 * and rearrange them.
 */
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
using namespace std;
typedef pair<int,int> pii;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,k,a[MAXN],usedk,pos_added = 1;
priority_queue <pii> pq; 
int main()
{
	setIO();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {   
        //If we have an element out of order which we CAN reorder
        if(i - pq.size() != a[i] && usedk < k)
        {
            usedk++;
            pq.push(pii(-a[i], pos_added));
        }
        else
        {
            //Print out any elements that are just going to be ordered
            while(!pq.empty() && -pq.top().first < a[i])
            {
                cout << -pq.top().first << " ";

                //If the pancake will be placed at the same position as original, we haven't swapped it
                if(pq.top().second == pos_added)
                    usedk--;
                pos_added++;
                pq.pop();
            }
            cout << a[i] << " ";
            pos_added++;
        }
    }

    //Any remaining pancakes? Out they go!
    while(!pq.empty())  
    {
        cout << "REM" <<  endl;
        cout << -pq.top().first << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}

/*
Degenerate TCs:
6 2
2 3 4 5 6 1

Should be: 2 3 4 1 5 6
*/