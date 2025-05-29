#include <algorithm>
#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    //freopen("tracing.in", "r", stdin);
    //freopen("tracing.out", "w", stdout);

    int n, t;
    cin >> n >> t;

    char cows[n];

    // Store current cows
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }

    vector<tuple<int, int, int>> interactions;

    // Take in interactions
    for (int i = 0; i < t; i++)
    {
        int time, cow1, cow2;
        cin >> time >> cow1 >> cow2;
        interactions.emplace_back(time, cow1, cow2);
    }

    sort(interactions.begin(), interactions.end(),[](const auto& a, const auto& b)
    {
        return get<0>(a) < get<0>(b);
    });

    int cow0Count = 0;
    int minK = 1e9;
    // Iterate through every possible cow 0
    for (int i = 0; i < n; ++i)
    {
        if (cows[i] == '1') // Possible cow 0
        {
            const int K = 251;
            vector<int> simulation(n); // Prepare simluation array
            simulation[i] = 1;

            for (int j = 0; j <= K; j++) // Check every possible k
            {
                for (const auto& interaction : interactions)
                {

                }
            }
        }
    }





    return 0;

}

