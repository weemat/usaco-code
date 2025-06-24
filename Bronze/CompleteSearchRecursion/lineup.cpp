#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> cows = {"Beatrice", "Belinda","Bella", "Bessie", "Betsy", "Blue","Buttercup", "Sue"};
vector<bool> seen(8, false);
vector<string> perm;
vector<pair<string, string>> rules;

bool found = false;

void recurse(int size)
{
    if (size == 8)
    {
        // Print
        for (int i = 0; i < size; i++)
        {
            cout << perm[i] << endl;
        }

        found = true;

        return;
    }

    for (int i = 0; i < cows.size(); i++)
    {
        if (found) return;
        if (seen[i]) continue;
        seen[i] = true;
        perm.push_back(cows[i]);

        // Can check here
        for (pair<string, string> rule : rules)
        {
            string first = rule.first;
            string second = rule.second;

            auto it = find(perm.begin(), perm.end(), first);
            auto it2 = find(perm.begin(), perm.end(), second);

            if (it != perm.end() && it2 != perm.end()) // Both exist, can check if condition holds. Otherwise, move on
            {
                int dist1 = distance(perm.begin(), it);
                int dist2 = distance(perm.begin(), it2);

                if (abs(dist1 - dist2) != 1)
                {
                    seen[i] = false;
                    perm.pop_back();

                    return; // Cancel this combination since condition not fulfilled
                }
            }

        }

        recurse(size + 1);
        seen[i] = false;
        perm.pop_back();
    }

}

int main()
{

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {

        string rule;
        getline(cin, rule);

        string first = rule.substr(0, rule.find(" "));
        string second = rule.substr(rule.rfind(" ") + 1);

        rules.push_back(make_pair(first, second));
    }

    recurse(0);
    return 0;
}
