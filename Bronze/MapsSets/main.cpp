#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n;
    cin >> n;

    unordered_map<string, vector<string>> m;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        string city, state;
        cin >> city >> state;

        string cityState = city.substr(0,2);

        if (m.find(cityState) != m.end())
        {
            vector<string> vec = m[cityState];
            for (string str : vec)
            {
                if (str.substr(0, 2) == state && state != cityState)
                {
                    count ++;
                }

            }
        }
        m[state].push_back(city);
    }

    cout << count << endl;
    return 0;


}