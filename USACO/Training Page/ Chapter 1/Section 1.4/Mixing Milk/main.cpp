/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: milk
**/
#include <bits/stdc++.h>
using namespace std;

struct Farmer
{
int price,amount;
};
bool comp(Farmer a, Farmer b) //Comparator function for sorting the Farmer's offers
{
    if(a.price != b.price) return a.price < b.price;
    return a.amount > b.amount;
}

int main()
{
    ifstream cin ("milk.in");
    ofstream cout ("milk.out");

    int n,m,payment = 0;
    cin >> n >> m;
    Farmer farmers[m];

    for(int i = 0; i < m; i++)
        cin >> farmers[i].price >> farmers[i].amount;
    sort(farmers, farmers + m,comp);

    for(int i = 0; i < m && n != 0; i++) //Greedily processing each offer
    {
        //cout << farmers[i].price << " " << farmers[i].amount << endl;
        if(n >= farmers[i].amount)
        {
            payment += farmers[i].price * farmers[i].amount;
            n -= farmers[i].amount;
        }
        else
        {
            payment += farmers[i].price * n;
            n = 0;
        }
    }
    cout << payment << endl;
    return 0;
}
