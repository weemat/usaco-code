#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define all(x) (x).begin(), (x).end()

int main ()
{

    int t, n, m;
    cin >> t;


    for (int ind = 0; ind < t; ind++) // Iterate through each test case
    {
        cin >> n >> m;
        int sum = 0;
        vector<vector<int> > cards(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cards[i][j]; // Input cards
            }
        }

        long long total = 0;

        for (int j = 0; j < m; j++) {

            vector<int> column_vals(n);

            for (int i = 0; i < n; i++) {
                column_vals[i] = cards[i][j];
            }

            sort(all(column_vals));

            long long subtotal = 0;
            for (int i = 0; i < n; i++) {
                long long coeff = 2LL * i - n + 1;
                subtotal += (long long)column_vals[i] * coeff;
            }

            total += subtotal;
        }

        cout << total << endl;
    }
    return 0;




}
