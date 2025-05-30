#include <algorithm>
#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int n;
vector<int> permutation;
vector<bool> used;
void search()
{
    if (permutation.size() == n)
    {
        cout << "Permutation: ";
        if (permutation.empty())
        {
            cout << "Null ";
        }
        for (int perm : permutation)
        {
            cout << perm << " " ;
        }
        cout << endl;
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            used[i] = true;
            permutation.push_back(i);
            search();
            used[i] = false;
            permutation.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    used.resize(n);
    for (int i = 0; i < used.size(); i++)
    {
        used[i] = false;
    }
    search();
}
