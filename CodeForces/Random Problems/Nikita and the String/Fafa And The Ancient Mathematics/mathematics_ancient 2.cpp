#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_OPERATORS 1000
string str;
int p,q,dp[MAX_OPERATORS][MAX_OPERATORS],index,lastVal,opCount;
bool atFirst;

void calculateDP() //Derpity derp derp derp derp derp 
{

}

bool isCharacter(int index, char c) //Nice Helper Function
{
    return str[index] == c;
}
bool isNumber(int index) //Another convenient helper
{
    return !isCharacter(index,'(') && !isCharacter(index,')') && !isCharacter(index,'?'); //If the value isn't character
}                                                                                         //it must be a number

void solve() //Computes the best DP with the operators given
{
    for(int i = index; i >= 0; i--) //For each value in the string
    {
        if(isCharacter(i,'(')) //If we have solved the expression completely, don't continue
            break;
        //If the current character is ')' , recurse
        if(isCharacter(i,')'))
        {
            index = i - 1; //Updating the index of visited 
            solve();
            i = index;
        }



        //If the current character is a '?'
        if(isCharacter(i,'?'))
        {
            //Special Case: if the character is a ')', basically this: (A op B)?C, we must recurse again
            if(i > 0 && isCharacter(i - 1, ')'))
            {
                int beforeOpCount = opCount;
                solve();


            }
            else 
            {
                calculateDP();
            }

            opCount++;
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str >> p >> q;
    index = str.length() - 1; //Setting the current index

    for(int i = str.length() - 1; i >= 0; i--) //Setting up the base case 
        if(isNumber(i)) //If the value is a number
        {
            dp[0][0] = str[i] - '0'; 
            break;
        }

    solve();

    cout << dp[p][q] << endl; //Final Output of DP: total + & -
}