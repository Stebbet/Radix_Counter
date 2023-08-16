#include <vector>

using namespace std;

int * prefix_sum (int *);

vector<int> radix( vector<int> unsorted, int iteration){

    // Each iteration get the next value along

    int * count_arr = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> sorted;
    sorted.resize(unsorted.size());

    // Get the count array
    for (int temp : unsorted){

        // Divide temp by 10 iteration number of times
        // The index is now temp % 10

        int t_iteration = iteration;
        while (t_iteration != 0){
            temp /= 10;
            t_iteration--;
        }

        int indices_number = temp % 10;
        count_arr[indices_number]++;
    }

    count_arr = prefix_sum(count_arr);


    for (auto i = unsorted.rbegin(); i != unsorted.rend(); ++i){
        int temp = *i;

        int t_iteration = iteration;
        while (t_iteration != 0){
            temp /= 10;
            t_iteration--;
        }

        int indices_number = temp % 10;
        int index = --count_arr[indices_number];
        sorted[index] = *i;
    }

    return sorted;
}


// Calculate prefix sum
int * prefix_sum(int *counter_arr){
    // [ 2, 5, 1, 4, 5 ] --> [ 2, 7, 8, 12, 17 ]
    for (int i = 1 ; i < 10; i++){
        counter_arr[i] += counter_arr[i - 1];
    }
    return counter_arr;
}