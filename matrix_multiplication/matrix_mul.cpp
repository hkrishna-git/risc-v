#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstring>

// Matrix size
const int N = 1024;
const int BLOCK_SIZE = 32;

using namespace std;
using namespace std::chrono;

// Initialize with random values
void fillRandDataInMatrix(vector<vector<float>> &mat) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

// Native matrix multiplication
void multiply(const vector<vector<float>> &A, const vector<vector<float>> &B, vector<vector<float>> &C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

#ifdef OPTIMIZE
#pragma GCC push_options
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
// matrix multiplication with loop tiling
void blockMultiply(const vector<vector<float>> &A, const vector<vector<float>> &B, vector<vector<float>> &C) {
    for (int i1 = 0; i1 < N; i1 += BLOCK_SIZE) {
        for (int j1 = 0; j1 < N; j1 += BLOCK_SIZE) {
            for (int k1 = 0; k1 < N; k1 += BLOCK_SIZE) {
                for (int i = i1; i < i1 + BLOCK_SIZE; ++i) {
                    for (int j = j1; j < j1 + BLOCK_SIZE; ++j) {
                        for (int k = k1; k < k1 + BLOCK_SIZE; ++k) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}
#pragma GCC pop_options
#endif

int main() {
    vector<vector<float>> A(N, vector<float>(N));
    vector<vector<float>> B(N, vector<float>(N));
    vector<vector<float>> C(N, vector<float>(N, 0));
    vector<vector<float>> C_blocked(N, vector<float>(N, 0));

    fillRandDataInMatrix(A);
    fillRandDataInMatrix(B);

    // Benchmark native
    auto start_native = high_resolution_clock::now();
    multiply(A, B, C);
    auto end_native = high_resolution_clock::now();
    duration<double> time_native = end_native - start_native;
    cout << "Native matrix multiplication time: " << time_native.count() << " seconds\n";

#ifdef OPTIMIZE
    // Benchmark blocked
    auto start_blocked = high_resolution_clock::now();
    blockMultiply(A, B, C_blocked);
    auto end_blocked = high_resolution_clock::now();
    duration<double> time_blocked = end_blocked - start_blocked;
    cout << "Block matrix multiplication time: " << time_blocked.count() << " seconds\n";
#endif

    return 0;
}
