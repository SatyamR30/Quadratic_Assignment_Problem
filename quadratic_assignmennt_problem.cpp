#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the size of the problem
const int N = 4;  // Number of facilities/locations

// Define the cost matrix and flow matrix (modify these according to your problem)
int cost[N][N] = {
    {0, 5, 8, 2},
    {5, 0, 6, 3},
    {8, 6, 0, 7},
    {2, 3, 7, 0}
};

int flow[N][N] = {
    {0, 2, 3, 1},
    {2, 0, 4, 3},
    {3, 4, 0, 5},
    {1, 3, 5, 0}
};

// Calculate the objective function value for a given permutation
int calculateObjective(const vector<int>& permutation) {
    int obj = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            obj += cost[i][j] * flow[permutation[i]][permutation[j]];
        }
    }
    return obj;
}

int main() {
    // Initialize a random permutation
    vector<int> permutation(N);
    for (int i = 0; i < N; ++i) {
        permutation[i] = i;
    }

    // Randomly shuffle the permutation
    random_shuffle(permutation.begin(), permutation.end());

    // Calculate the initial objective value
    int initialObjective = calculateObjective(permutation);
    cout << "Initial Objective Value: " << initialObjective << endl;

    // Perform local search (Hill Climbing) to improve the solution
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                swap(permutation[i], permutation[j]);
                int newObjective = calculateObjective(permutation);
                if (newObjective < initialObjective) {
                    initialObjective = newObjective;
                    improved = true;
                } else {
                    swap(permutation[i], permutation[j]);  // Revert the swap
                }
            }
        }
    }

    cout << "Improved Objective Value: " << initialObjective << endl;
    cout << "Optimal Permutation: ";
    for (int i = 0; i < N; ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    return 0;
} 