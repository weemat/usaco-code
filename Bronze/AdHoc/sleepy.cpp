#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    unordered_map<int, int> map;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        map.insert({x, i}); // Map number to position
    }



}