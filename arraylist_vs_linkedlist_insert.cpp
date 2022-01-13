#include <chrono>  // for high_resolution_clock
#include <fstream>  // for ofstream
#include <iostream>  // for cout
#include <stdexcept>  // for runtime_error
#include <vector>  // for vector (exercise 1f)

using namespace std;
using namespace std::chrono;

class ArrayList{
    // Your code here
};

int main(){
    cout << "Array list - insert front \n";
    ofstream ofs{"array_list_insert.txt"};
    if (!ofs) {
        throw runtime_error("Unable to open file");
    }
    for (int N = 100; N < 1E6; N *= 10) {
        auto start = high_resolution_clock::now();
        ArrayList ll{};
        for (int i = 0; i < N; i++) {
            ll.insert(i, 0);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << N << " " << duration.count() / (double) N << "\n";
        ofs << N << " " << duration.count() / (double) N << "\n";
    }
    return 0;
}
