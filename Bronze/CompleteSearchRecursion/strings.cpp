#include <algorithm>
#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<char> permutation;
vector<bool> used;
vector<string> totPerms;
void recurse(string s)
{
    if (permutation.size() == s.size()) // permutation generated, store it and increase counter
    {
        totPerms.emplace_back(permutation.begin(), permutation.end());
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (used[i]) continue;

        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        permutation.emplace_back(s[i]);
        recurse(s);
        used[i] = false;
        permutation.pop_back();
    }
}

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    used.assign(s.size(), false);

    recurse(s);
    cout << totPerms.size() << endl;

    for (const string &perm : totPerms)
    {
        cout << perm << endl;
    }

    return 0;
}
