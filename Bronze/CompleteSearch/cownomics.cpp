#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> spottyGenes(n, vector<char>(m));
    vector<vector<char>> normalGenes(n, vector<char>(m));

    // Take in input for spotty genes
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> spottyGenes[i][j];
        }
    }

    // Take in input for normal genes
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> normalGenes[i][j];
        }
    }

    int count = m;
    // Store the spotty genes at position j in a vector
    for (int j = 0; j < m; j++)
    {
        vector<char> genesAtPosition(n);
        for (int i = 0; i < n; i++)
        {
            genesAtPosition.push_back(spottyGenes[i][j]);
        }

        for (int i = 0; i < n; i++) // Iterate through normal genes at position j
        {
            char gene = normalGenes[i][j];
            auto it = find(genesAtPosition.begin(), genesAtPosition.end(), gene);

            if (it != genesAtPosition.end())
            {
                count --;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;

}
