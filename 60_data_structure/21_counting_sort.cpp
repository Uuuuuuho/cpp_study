#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return; // already sorted or empty array
    
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }

    vector<int> counts(max_val+1, 0);
    vector<int> output(n);
    
    // Count the number of occurrences of each element
    for (int i = 0; i < n; i++) {
        counts[arr[i]]++;
    }
    
    // Update the counts to show the cumulative frequency
    for (int i = 1; i <= max_val; i++) {
        counts[i] += counts[i-1];
    }
    
    // Build the output array
    for (int i = n-1; i >= 0; i--) {
        output[counts[arr[i]]-1] = arr[i];
        counts[arr[i]]--;
    }
    
    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 5, 2, 3, 5};
    countingSort(arr);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
