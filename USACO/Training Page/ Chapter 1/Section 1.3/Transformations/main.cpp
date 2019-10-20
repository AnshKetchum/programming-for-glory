/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: transform
**/
#include <bits/stdc++.h>
using namespace std;

int n;
char originalPicture [11][11], newPicture [11][11];

void printgrid() //Debugger method
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << originalPicture[i][j];
        cout << endl;
    }
}

bool rotate90() //checks if there is rotation of 90 degrees
{
   // printgrid();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           if(originalPicture[i][j] != newPicture[j][n - i - 1])
            {
                return false;
            }
        }
    }
    return true;
}

bool rotate180() //checks if there is rotation of 180 degrees
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           if(originalPicture[i][j] != newPicture[n - i - 1][n - j - 1])
                return false;
        }
    }
    return true;
}

bool rotate270() //Checks if there is a rotation of 270 degrees
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
        //   cout << originalPicture[i][j] << " " << newPicture[n - j - 1][i] << endl;
           if(originalPicture[i][j] != newPicture[n - j - 1][i])
                return false;
        }
    }
    return true;
}

bool reflect() //Checks for reflection
{
    bool isTrue = true;
    int middleLine = n / 2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < middleLine; j++)
        {
            swap(originalPicture[i][j],originalPicture[i][n - j - 1]);
            if(originalPicture[i][j] != newPicture[i][j] && isTrue)
                isTrue = false;
        }
    }
    for(int i = middleLine; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(originalPicture[j][i] != newPicture[j][i])
                isTrue = false;
        }
    }
    //printgrid();
    return isTrue;
}


int main()
{
    ifstream cin ("transform.in");
    ofstream cout ("transform.out");

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> originalPicture[i][j];
    }

    bool alreadySame = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> newPicture[i][j];
            if(newPicture[i][j] != originalPicture[i][j]) alreadySame = false;
        }
    }

    int ans = 999999;
    if(rotate90()) ans = min(ans,1); //Checks for all transformations
    else if(rotate180()) ans = min(ans,2);
    else if(rotate270()) ans = min(ans,3);

    bool x = reflect();

    if(x) ans = min(ans,4);
    else if(rotate90() || rotate180() || rotate270()) ans = min(ans,5);
    else if(alreadySame) ans = min(ans,6);
    else ans = min(ans,7);

    cout << ans << endl;
    return 0;
}
