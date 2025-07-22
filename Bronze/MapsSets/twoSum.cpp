#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;

    unordered_map<int, int> a;
    bool isFound = false;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (a.count(x - num)) // If complement exists you can end
        {
            cout << i + 1 << " " << a[x - num] + 1 << endl;
            isFound = true;
            break;
        }

        a[num] = i;
    }

    if (!isFound)
    {
        cout << "IMPOSSIBLE" << endl;
    }







}
