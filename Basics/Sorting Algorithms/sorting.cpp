#include <iostream>

// Function to swap values (simplify the code)
void swapValues(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

// Bubble Sort
// Algorithm that sorts an array from the lowest value to the highest value
// https://visualgo.net/en/sorting?create=4%2C20%2C35%2C26%2C23%2C25%2C13%2C4%2C9%2C25&mode=Bubble
void BubbleSort(int array[], int size) {
    for (int i=0; i<size; i++) { // Main loop
        for (int j=1; j<size; j++) { // Current
            if (array[j] < array[j-1]) { // If current is less than previous, swap the data
                swapValues(array[j], array[j-1]);
            }
        }
    }
}

// Selection Sort
// Algorithm that finds the lowest value in an array and moves it to the front of the array
// https://visualgo.net/en/sorting?create=38%2C8%2C36%2C42%2C4%2C25%2C50%2C10%2C38%2C27&mode=Selection
void SelectionSort(int array[], int size) {
    int smallest;

    for (int a=0; a<size; a++) { // Main loop (index)
        smallest = a; // Set smallest to index a
        for (int b=a+1; b<size; b++) { // Second loop for finding second smallest
            if (array[b] < array[smallest]) { // if found then set smallest to index b
                smallest = b;
            }
        }
        swapValues(array[a], array[smallest]);
    }
}

// Insertion Sort
// Algorithm  that uses one part of the array to hold the sorted values, and the other part of the array to hold values that are not sorted yet.
// It takes one value at a time from the unsorted part of the array and puts it into the right place in the sorted part of the array, until the array is sorted.
// https://visualgo.net/en/sorting?create=17%2C39%2C41%2C29%2C49%2C7%2C24%2C47%2C16%2C10&mode=Insertion
void InsertionSort(int array[], int size) {
    int temp;

    for (int i=1; i<size; i++) { // Main loop (data to be moved)
        temp = array[i];
        int j=i-1;

        // Loop through behind comparing previous (sorted) data
        while ((temp<array[j]) && (j>=0)) {
            array[j+1] = array [j];
            j--;
        }

        array[j+1] = temp; // After breaking the while loop, complete the swap

    }
}

// Merge Sort
// Divide-And-Conquer algorithm that sorts an array by first breaking it down into smaller arrays, and then building the array back together the correct way so that it is sorted.
// The Combiner
void Merge(int array [], int left, int mid, int right) {
    int leftSize = mid - left + 1; // Left side size
    int rightSize = right - mid; // Right side size
    int leftSide[leftSize], rightSide[rightSize]; // 2 temporary array, left side and right side of the array

    // Fills the temp arrays with datas
    for (int i = 0; i < leftSize; i++) {
        leftSide[i] = array[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightSide[j] = array[mid + 1 + j];
    }

    // Initialize the indexes for merging
    int i = 0, j = 0;
    int k = left; // Main index for combining all the sorted data

    while (i < leftSize && j < rightSize) { // While theres still data in split arrays
        if (leftSide[i] <= rightSide[j]) { // Comparing left's bigger or equal to right's first data, if it is, left move to main index and increments the side's index and vise versa
            array[k] = leftSide[i];
            i++;
        } else {
            array[k] = rightSide[j];
            j++;
        }
        k++; // increments the main index for next comparison
    }

    // Fills the leftovers data to main index if 
    while (i < leftSize) {
        array[k] = leftSide[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightSide[j];
        j++;
        k++;
    }
}

// The Divider (Starting Point)
void MergeSort(int array[], int left, int right) {
    if (left < right) { // Check if theres more than one item in the list
        int mid = left + (right - left) / 2; // Calculates the mid, for example a 6: mid = 0 + (5 - 0) / 2 which is 2(int divison is rounded out)

        // Recursive (called until theres only one item left)
        MergeSort(array, left, mid); // Split left
        MergeSort(array, mid+1, right); // Split right

        // Calls the main function to merge all the split data
        Merge(array, left, mid, right);
    }
}

// Main function
int main() {
    std::cout << "Hello" << std::endl;
    return 0;
}