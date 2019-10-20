/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: milk3
**/
#include <bits/stdc++.h>
using namespace std;

struct bucket //Each type stores the bucket capacity as well as the amount it is currently holding
{
    int maxMilk,currentMilkAmount;
};

bucket a,b,c; //The problem demands 3 buckets, respectively named A, B, C
priority_queue<int, vector<int>, greater<int>>answers;
bool visitedState[50][50][50][50],addedToAnswer[50]; // Both are arrays that will ensure that any duplicate numbers do not enter our

int fillBucket(bucket donor, bucket receiver) //Fills a bucket
{
    int possibleDonorSpace = (receiver.maxMilk - receiver.currentMilkAmount);
    int transferAmount = min(donor.currentMilkAmount,possibleDonorSpace);
    return transferAmount;
}

void resetBuckets(bucket &donator, bucket &receiver, int transfer) //Resets a transfer
{
    donator.currentMilkAmount += transfer;
    receiver.currentMilkAmount -= transfer;
}

void makeTransfer(bucket &donator, bucket &receiver, int transfer) //Makes a transfer
{
    donator.currentMilkAmount -= transfer;
    receiver.currentMilkAmount += transfer;
}

void solve(bool usedAValue) //Recursive combination method to try all possibilities
{
    if(visitedState[a.currentMilkAmount][b.currentMilkAmount][c.currentMilkAmount][(int)usedAValue])
        return;
    visitedState[a.currentMilkAmount][b.currentMilkAmount][c.currentMilkAmount][(int)usedAValue] = true;

    if(usedAValue && a.currentMilkAmount == 0)
    {
        int answer = c.currentMilkAmount;
        if(!addedToAnswer[answer]){
            answers.push(answer);
            addedToAnswer[answer] = true;
        }
    }

    if(a.currentMilkAmount > 0) {
        int transfer = fillBucket(a,b);
        if(transfer){
            makeTransfer(a,b,transfer);
            solve(usedAValue);
            resetBuckets(a,b,transfer);
        }

        transfer = fillBucket(a,c);
        if(transfer){
            makeTransfer(a,c,transfer);
            solve(usedAValue);
            resetBuckets(a,c,transfer);
        }
    }

    if(b.currentMilkAmount > 0) {
        int transfer = fillBucket(b,a);
        if(transfer){
            usedAValue = true;
            makeTransfer(b,a,transfer);
            solve(usedAValue);
            resetBuckets(b,a,transfer);
        }

        transfer = fillBucket(b,c);
        if(transfer){
            makeTransfer(b,c,transfer);
            solve(usedAValue);
            resetBuckets(b,c,transfer);
        }
    }

    if(c.currentMilkAmount > 0) {
        int transfer = fillBucket(c,a);
        if(transfer){
            usedAValue = true;
            makeTransfer(c,a,transfer);
            solve(usedAValue);
            resetBuckets(c,a,transfer);
        }

        transfer = fillBucket(c,b);
        if(transfer){
            makeTransfer(c,b,transfer);
            solve(usedAValue);
            resetBuckets(c,b,transfer);
        }
    }
}

int main()
{
    ifstream cin ("milk3.in");
    cin >> a.maxMilk >> b.maxMilk >> c.maxMilk;
    c.currentMilkAmount = c.maxMilk;

    solve(false);
    ofstream cout ("milk3.out");
    while(answers.size() != 0)
    {
        cout << answers.top();
        if(answers.size() != 1) cout << " ";
        answers.pop();
    }
    cout << endl;

    return 0;
}
