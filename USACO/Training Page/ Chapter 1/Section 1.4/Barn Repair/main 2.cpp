/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: barn1
**/
#include <bits/stdc++.h>
using namespace std;

int m,s,c,ct;
int stalls[300];
vector <pair <int,int>> covers; //This vector will store the first and last cow each board covers in 'interval' (first,last) format
int main()
{
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");

    cin >> m >> s >> c;
    for(int i = 0; i < c; i++)
        cin >> stalls[i];
    sort(stalls, stalls + c); //Sort the stalls by ascending order in order to traverse stalls

    if(m >= c){ //Is the amount of boards greater than the # of cow stalls? If so, the optimal answer is 'c' (Each cow receives their own board)
        cout << c << endl;
        exit(0);
    }

    /* During the next loop, I try to iterate over each cow, and compare the differences in distance with the previous and the next cow.
     * If the distance with the previous is smaller, it is optimal to cover the cow with the current board.
       We expand the our board to cover current stall
     * Otherwise, create a new board which covers the current stall only.
     * Since my code experiences bugs with the last case, I forced the last stall to be covered. (Temporarily)
     */
    covers.push_back(make_pair(stalls[0],stalls[0]));
    for(int i = 1; i < c; i++){
        int distanceFromPrev = stalls[i] - stalls[i - 1];
        int distanceFromNext = stalls[i + 1] - stalls[i];
        if(distanceFromPrev <= distanceFromNext) covers[ct].second = stalls[i];
       else if(i == c - 1) covers.push_back(make_pair(stalls[i], stalls[i]));
       else{
            ct++;
            covers.push_back(make_pair(stalls[i],stalls[i]));
        }
    }

    /* Currently, the amount of boards used may be greater than the requirement, and we will need to combine a couple.
     * As long as we have more boards than needed, we should combine the boards which are closest to each other.
     */

    while(covers.size() > m)
    {
        int minNum = 99999; //Stores the smallest difference of distance
        auto remPos = covers.begin(); //Pointer to the board that will be removed
        for(auto it = covers.begin() + 1; it < covers.end(); it++){
            int distBetween = (it)->first - (it - 1)->second;
            if(minNum > distBetween){ //If there is a smaller difference removable, we should remove it
                minNum = distBetween;
                remPos = it;
            }
        }
        (remPos - 1)->second = remPos -> second; //Since the minimum distance between two have found,
        covers.erase(remPos); //I am removing the board, but I must combine it with the previous one first
    }


    int totalCoverage = 0; //Stores the amount of stalls covered (Answer)
    for(int i = 0; i < covers.size(); i++){
        int difference = (covers[i].second - covers[i].first) + 1; //Since answer is inclusive of initial value, we add 1 to it.
        totalCoverage += difference;
    }

    cout << totalCoverage << endl;
    return 0;
}
