// C++ program for the implementation of Bubble sort
/*Start by comparing the first two elements.If they are in the wrong order, swap them.
Continue this process for all elements moving from left to right.After the first pass, the largest element will be at the end.
In the next pass, skip the last element since it’s already sortedand repeat the above steps.The second - largest element will move to the second - last position.
Repeat the steps until the entire array is sorted.*/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

int main() {
    vector<int> v = { 10, 9, 4, 1, 2 };
    bubbleSort(v);
    for (auto i : v)
        cout << i << " ";
    return 0;
}
