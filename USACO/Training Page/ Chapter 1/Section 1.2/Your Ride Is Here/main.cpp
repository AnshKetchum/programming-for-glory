/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: ride
**/
#include <bits/stdc++.h> //Useful Library for Competitive Programming, has most of the "essential" classes imported for you
using namespace std;

int getValueInMod(string message) //"Helper function" that returns the "value" of the String, as described in problem
{
    int modValue = 1; //This will be our running variable that stores the sum.
    for(int i = 0; i < message.length(); i++) //Computing
        modValue *= (message[i] - '@'); //@ is the character before the alphabets start.
                                // Subtracting by @ will give us the alphabet position of current character
    cout << modValue << endl;
    return modValue % 47; //Returning the sum
}

int main() //Main Method
{
    ifstream fin ("ride.in"); //This will read the data from the file using the fStream class
    ofstream fout("ride.out"); //This will write our data to the answer file using the fStream class.
                               //Note that USACO generally uses File Input / Output in order to send/receive data
    string cometName = "", groupName = ""; //We will store the input strings into these variables.
    fin >> cometName >> groupName; //Reading the input

    if(getValueInMod(cometName) == getValueInMod(groupName))   fout << "GO" << endl;
    else fout << "STAY" << endl;
    return 0;
}
