#include <algorithm>
#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int n;
vector<int> subset;
void search(int k)
{
    if (k == n)
    {
        // Subset processed
        cout << "Subset: ";
        if (subset.empty())
        {
            cout << "Null ";
        }
        for (int sub : subset)
        {
            cout << sub << " " ;
        }
        cout << endl;
    }
    else
    {
        search(k + 1);       // Don't add to subset and recurse
        subset.push_back(k); // Add to subset
        search(k + 1);       // Recurse
        subset.pop_back();   // Backtrack

    }
}
int main()
{
    cin >> n;
    search(0);
}
