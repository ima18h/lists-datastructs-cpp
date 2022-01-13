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
    cout << "\nArray list - get \n";
    ofstream ofs{"array_list_get.txt"};
    if (!ofs) {
        throw runtime_error("Unable to open file");
    }
    // Number of times we want to get the element
    int runs = 1000;
    for (int N = 100; N < 1E6; N *= 10) {

        // Append N elements
        ArrayList ll{};
        for (int i = 0; i < N; i++) {
            ll.append(i);
        }

        // Start the clock
        auto start = high_resolution_clock::now();
        // Get value in the middle
        for (int run = 0; run < runs; run++) {
            auto value = ll[N / 2];
        }

        // Stop the clock
        auto stop = high_resolution_clock::now();
        // Compute the time difference in microseconds
        auto duration = duration_cast<microseconds>(stop - start);
        // Print the results in the console
        cout << N << " " << duration.count() / (double) runs << "\n";
        // Save the result to a file
        ofs << N << " " << duration.count() / (double) runs << "\n";
    }
    return 0;
}
