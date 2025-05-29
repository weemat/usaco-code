#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

struct Interaction {
    int t, x, y;
};

int N, T;
string final_state;
vector<Interaction> interactions;

bool simulate(int patient_zero, int K) {
    vector<bool> infected(N + 1, false);
    vector<int> transmission_count(N + 1, 0);

    infected[patient_zero] = true;

    // Sort interactions by time
    vector<Interaction> sorted = interactions;
    sort(sorted.begin(), sorted.end(), [](const Interaction &a, const Interaction &b) {
        return a.t < b.t;
    });

    for (auto &inter : sorted) {
        int x = inter.x;
        int y = inter.y;

        bool x_infects_y = infected[x] && transmission_count[x] < K;
        bool y_infects_x = infected[y] && transmission_count[y] < K;

        if (x_infects_y) {
            if (!infected[y]) {
                infected[y] = true;
            }
            transmission_count[x]++;
        }

        if (y_infects_x) {
            if (!infected[x]) {
                infected[x] = true;
            }
            transmission_count[y]++;
        }
    }

    // Compare result with final state
    for (int i = 1; i <= N; ++i) {
        if ((infected[i] ? '1' : '0') != final_state[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    cin >> N >> T;
    cin >> final_state;

    interactions.resize(T);
    for (int i = 0; i < T; ++i) {
        cin >> interactions[i].t >> interactions[i].x >> interactions[i].y;
    }

    set<int> possible_zeros;
    int min_K = INT_MAX;
    int max_K = -1;
    bool infinite_K = false;

    for (int i = 1; i <= N; ++i) {
        for (int K = 0; K <= 251; ++K) {
            if (simulate(i, K)) {
                possible_zeros.insert(i);
                min_K = min(min_K, K);
                if (K == 251) {
                    infinite_K = true;
                }
                max_K = max(max_K, K);
            }
        }
    }

    cout << possible_zeros.size() << " " << min_K << " ";
    if (infinite_K) {
        cout << "Infinity" << endl;
    } else {
        cout << max_K << endl;
    }

    return 0;
}
