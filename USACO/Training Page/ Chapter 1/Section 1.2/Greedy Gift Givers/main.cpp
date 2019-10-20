/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: gift1
**/
#include <bits/stdc++.h> //Library that is useful for Competitive Programming
using namespace std;

string nameOfPerson[11]; //Stores all of the people
int balanceOfPerson[11]; //Stores the amount that each person has
int numberOfPeople;

void giveGift(string giver, string receiver, int moneyGiven) //Removes the money from the donor, and adds the split amount to the recipient
{
    for(int index = 0; index < numberOfPeople; index++) //Sequential search to locate both the donor and recipient
    {
        if(giver == nameOfPerson[index])
            balanceOfPerson[index] -= moneyGiven;

        if(receiver == nameOfPerson[index])
            balanceOfPerson[index] += moneyGiven;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); //This is another way to do I/O, syncing the standard I/O to file makes it very convenient
    freopen("gift1.in","r",stdin); //Opening the input file
    freopen("gift1.out","w",stdout); //Opening the output file

    cin >> numberOfPeople; //Takes in the number of people

    int moneyGiven = 0, numberOfPeopleGivenTo = 0;
    string askedName, receiverNames;

    for(int i = 0; i < numberOfPeople; i++) //Reads in the name of each person, filling in our list of people
        cin >> nameOfPerson[i];
    for(int i = 0; i < numberOfPeople; i++) //This handles each "gift" given by a donor
    {
        cin >> askedName;  //Reading in the input
        cin >> moneyGiven >> numberOfPeopleGivenTo;
        if(moneyGiven == 0 && numberOfPeopleGivenTo == 0) continue;
        moneyGiven /= numberOfPeopleGivenTo; //Splitting the money

        for(int j = 0; j < numberOfPeopleGivenTo; j++) //Donated the money to recipient
        {
            cin >> receiverNames;
            giveGift(askedName,receiverNames,moneyGiven);
        }

    }

    for(int i = 0; i < numberOfPeople; i++) //Finally, outputting each person along with his final balance
        cout << nameOfPerson[i] << " " << balanceOfPerson[i] << endl;

    fclose(stdin); //Closing the input / output streams
    fclose(stdout);
    return 0;
}
