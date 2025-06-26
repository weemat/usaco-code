#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-6;
int bestResult;

// Check if a double is close to an integer
bool isInt(double x)
{
    return abs(x - round(x)) < EPS;
}

// Recursively try all combinations of numbers and operations
void solve(vector<double> nums)
{
    if (nums.size() == 1)
    {
        if (isInt(nums[0]) && nums[0] <= 24)
        {
            bestResult = max(bestResult, (int)(round(nums[0])));
        }
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (i == j) continue;

            vector<double> nextNums;
            for (int k = 0; k < nums.size(); ++k)
            {
                if (k != i && k != j) nextNums.push_back(nums[k]);
            }

            // Try all operations
            double a = nums[i], b = nums[j];

            // a + b
            nextNums.push_back(a + b);
            solve(nextNums);
            nextNums.pop_back();

            // a - b
            nextNums.push_back(a - b);
            solve(nextNums);
            nextNums.pop_back();

            // b - a
            nextNums.push_back(b - a);
            solve(nextNums);
            nextNums.pop_back();

            // a * b
            nextNums.push_back(a * b);
            solve(nextNums);
            nextNums.pop_back();

            // a / b
            if (abs(b) > EPS && isInt(a / b))
            {
                nextNums.push_back(a / b);
                solve(nextNums);
                nextNums.pop_back();
            }

            // b / a
            if (abs(a) > EPS && isInt(b / a))
            {
                nextNums.push_back(b / a);
                solve(nextNums);
                nextNums.pop_back();
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        vector<int> cards(4);
        for (int i = 0; i < 4; ++i) cin >> cards[i];

        bestResult = 0;
        sort(cards.begin(), cards.end());
        do
        {
            vector<double> nums(cards.begin(), cards.end());
            solve(nums);
        } while (next_permutation(cards.begin(), cards.end()));

        cout << bestResult << endl;
    }

    return 0;
}
