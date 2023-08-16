#include <iostream>
#include "radix.h"
#include <vector>

using namespace std;

int main() {
    vector<int> unsorted;
    int max_len = 0;

    // Ask user for a number input
    for(;;) {
        int num;
        cout << "Enter a number to add to the array or enter anything else to start" << endl;
        cout << "> ";
        cin >> num;

        if (!cin) {
            // Clear the error flag
            cin.clear();
            break;
        }

        unsorted.push_back(num);

        // Getting the maximum number of digits an inputted number has
        // Used for calculating how many iterations to do
        int t_len = (int) to_string(num).length();
        if(t_len > max_len){
            max_len = t_len;
        }
    }

    // Initialise a vector for the sorted array
    vector<int> sorted;
    sorted.resize(unsorted.size());

    // Perform the radix sort over max_len iterations
    for (int i = 0; i <= max_len; i++) {
        sorted = radix(unsorted, i);
        unsorted.swap(sorted);
    }

    // Print sorted array
    for (int i : sorted){
        std::cout << i << " ";
    }

    return 0;
}
