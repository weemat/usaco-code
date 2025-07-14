#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int simulateExplosion(const vector<int>& sortedBales, int startIdx) {
    int n = sortedBales.size();
    vector<bool> exploded(n, false);
    vector<int> currentlyExploding;

    // Start with the initial bale
    exploded[startIdx] = true;
    currentlyExploding.push_back(startIdx);

    int blastRadius = 1;
    int totalExploded = 1;

    while (!currentlyExploding.empty()) {
        vector<int> nextExploding;

        // For each currently exploding bale
        for (int idx : currentlyExploding) {
            int pos = sortedBales[idx];

            // Find leftmost bale within blast radius
            int leftBound = pos - blastRadius;
            int leftIdx = lower_bound(sortedBales.begin(), sortedBales.end(), leftBound) - sortedBales.begin();

            // Find rightmost bale within blast radius
            int rightBound = pos + blastRadius;
            int rightIdx = upper_bound(sortedBales.begin(), sortedBales.end(), rightBound) - sortedBales.begin() - 1;

            // Mark all bales in range as exploding if they haven't already
            for (int i = leftIdx; i <= rightIdx; i++) {
                if (!exploded[i]) {
                    exploded[i] = true;
                    nextExploding.push_back(i);
                    totalExploded++;
                }
            }
        }

        currentlyExploding = nextExploding;
        blastRadius++;
    }

    return totalExploded;
}

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int N;
    fin >> N;

    vector<int> bales(N);
    for (int i = 0; i < N; i++) {
        fin >> bales[i];
    }

    // Sort the bales by position
    sort(bales.begin(), bales.end());

    int maxExplosions = 0;

    // Try starting from each hay bale position
    for (int i = 0; i < N; i++) {
        int explosions = simulateExplosion(bales, i);
        maxExplosions = max(maxExplosions, explosions);
    }

    fout << maxExplosions << endl;

    fin.close();
    fout.close();

    return 0;
}
