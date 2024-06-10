#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr) {
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

void countSort(vector<int>& arr, int exp) {
    vector<int> counts(10, 0);
    vector<int> output(arr.size());

    // Count the number of occurrences of each digit
    for (int i = 0; i < arr.size(); i++) {
        int digit = (arr[i]/exp) % 10;
        counts[digit]++;
    }

    // Update the counts to show the cumulative frequency
    for (int i = 1; i < 10; i++) {
        counts[i] += counts[i-1];
    }

    // Build the output array
    for (int i = arr.size()-1; i >= 0; i--) {
        int digit = (arr[i]/exp) % 10;
        output[counts[digit]-1] = arr[i];
        counts[digit]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int max_val = getMax(arr);

    // Sort the array for each digit position
    for (int exp = 1; max_val/exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
