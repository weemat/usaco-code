#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> aMap;
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        aMap[a]++;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int count = 0;
    for (int j = 0; j < n; j++)
    {
        count += aMap[b[c[j]]];
    }

    cout << count << endl;
    return 0;
}
