#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

bool simulate(int pos, vector<int> cows, vector<int> hierarchy, map<int, int> cowPos, int n, int m) {
    cows[pos] = 1; // Place cow 1 at the given position
    int hierarchyIndex = 1;

    for (int i = 1; i <= n; i ++){ // Iterate through cows
        if (cows[i] == 0){
            int nextCow = hierarchy[hierarchyIndex];
            if (cowPos.count(nextCow) == 0){
                cows[i] = nextCow; // Place the next cow in the hierarchy
                cowPos[nextCow] = i; // Update the position of the cow
            }
            else{ // If cow is already placed
                int currentPos = cowPos[nextCow];
                for (int j = hierarchyIndex; j >= 0; j --){
                    if (cowPos[hierarchy[j]] > currentPos){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){

    int n, m, k; cin >> n >> m >> k;

    vector<int> cows(n);
    vector<int> hierarchy(m + 1);
    map<int, int> cowPos;

    for (int i = 1; i <= m; i++){
        cin >> hierarchy[i];
    }

    for (int i = 0; i < k; i++){
        int cow, pos; cin >> cow >> pos;
        cowPos[cow] = pos;
        cows[pos] = cow; // Store the cow at the given position
    }

    for (int i = 1; i <= m; i++){
        if (simulate(i, cows, hierarchy, cowPos, n, m)) {
            cout << i << endl;
            return 0;
        }
    }
    return -1; // If no valid position found
}