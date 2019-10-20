#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000


int n,stacks = -1,leftP;
vector <int> elsie_stack,bessie_stack[MAXN];

int get_index(int l, int r, int key)
{   
    cout << "(" << l << "," << r << ")" << endl;
    if(l == r)
        return l;

    if(r - l == 1)
    {
        if(bessie_stack[l][0] > key)
            return l;
        return r;
    }

    int mid = (l + r) / 2;
    
    if(bessie_stack[mid][0] < key)
        return get_index(l, mid,key);
    return get_index(mid,r,key);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin("dishes.in");
//    ofstream cout("dishes.out");

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        cout << "\n\n";

        if(stacks == -1 || d > bessie_stack[stacks][0]) //Creating a new stack 
        {
            bessie_stack[++stacks].push_back(d);
            cout << "Created new Stack. Current Size: " << stacks << endl;

            continue;
        }

        cout << "Value: " << d << " doens't need a new stack " << endl;
        int appropriate_stack = get_index(leftP,stacks,d); //Finds the lowest base > d
//        cout << "BINARY SEARCH RETURNS STACK # " << appropriate_stack << " for value " << d << endl;

        cout << "Checking if back: " << bessie_stack[appropriate_stack].back() <<  " is greater than " << d << endl;
        if(bessie_stack[appropriate_stack].back() > d) // Top > d ? Add it to the stack
        {
            cout << "New Top for Stack " << appropriate_stack << " - " << d << endl;
            bessie_stack[appropriate_stack].push_back(d);
        }
        else
        {
            cout << "\n";
            while(bessie_stack[appropriate_stack].back() < d && !bessie_stack[appropriate_stack].empty())
            {
               cout << "Removing Top: " << bessie_stack[appropriate_stack].back() << " to insert: " << d << endl;
                elsie_stack.push_back(bessie_stack[appropriate_stack].back());
                bessie_stack[appropriate_stack].pop_back();
            }
            if(!bessie_stack[appropriate_stack].empty())
                bessie_stack[appropriate_stack].push_back(d);
            else 
            {
                leftP++;
                elsie_stack.push_back(d);
            }
        }

    }

    cout << "\n\n\n";
    for(int i = 0; i <= stacks; i++)
        while(!bessie_stack[i].empty())
        {
            cout << "Finally inserting: " << bessie_stack[i].back() << endl;

            elsie_stack.push_back(bessie_stack[i].back());
            bessie_stack[i].pop_back();
        }    
    for(int x : elsie_stack)
        cout << x << " ";
    cout << endl;

    int ans = 1;
    for(int i = 1; i < elsie_stack.size(); i++)
    {
        if(elsie_stack[i] < elsie_stack[i - 1])
        {
            cout << elsie_stack[i] << " isn't greater than " << elsie_stack[i - 1] << endl;
            break;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}