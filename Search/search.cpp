// This program utilizes a few search algorithms to find a value in an array
// The algorithms are: Linear Search, Binary Search, and Selection Sort
// The program will print the algorithms time complexity in big-o notation

#include <iostream>
using namespace std;
// Variables
const int SIZE = 20;

// Function headers
int linearSearch(int arr[SIZE], int target); // Function header for Linear Search
int binarySearch(int arr[SIZE], int target); // Function header for Binary Search
void selectionSort(int arr[SIZE]); // Function header for Selection Sort
void swap(int &a, int &b); // Function header for swap -> Selection Sort will use this later
void printList(int arr[SIZE]); // Function header to print my list

int main() {
    int array[SIZE] = {10,34,5,20,1,
                        2,16,101,32,22,
                       15,7,8,225,14,
                       84,63,53,23,77};
    int target = 225;
    printList(array);
    int num = linearSearch(array, target);
    if(num == -1) {
        cout << "The value " << target << " was not found in the array utilizing Linear Search" << endl;
    }
    else {
        cout << "Linear Search: The value " << target << " was found at position " << num << " in O(n) time and " << num << " iterations." << endl;
    }
    selectionSort(array);
    cout << "Sorted "; 
    printList(array);
    cout << "The list was sorted using Selection Sort in O(n^2) time." << endl;
    num = binarySearch(array, target);
    if(num == -1) {
        cout << "The value " << target << " was not found in the array utilizing Binary Search" << endl;
    }
    else {
        cout << "Binary Search: The value " << target << " was found in " << num << " iterations in O(log(n)) time." << endl;
    }
}
/*Linear Search searches for a target value sequentially by checking all of the values in the array
until it locates the target. Once the target is located, I am returning the position it was found.
If the value was not found in the array I am returning -1 as a value to indicate failure.*/ 
int linearSearch(int arr[SIZE], int target) {
    for (int i = 0; i <= SIZE; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    // Failsafe in case the value is not found
    return -1;
}
/*The binarySearch function takes an array, and a target value to search for. The low is initialized
to 0, and the high to SIZE so that these values don't need to be passed as parameters. The array
is then searched by checking if the value is greater than or less than the mid (or in the upper/lower
half of the data). Once this is determined, the array is cut in half and the process is repeated.
This is done in O(log(n)) time complexity in the worst case.*/
int binarySearch(int arr[SIZE], int target) {
    // Initialize variables
    int low = 0; 
    int high = SIZE;
    int mid = (low + high) / 2;
    // Loop to determine which half the value is in, and then cut the array accordingly
    for (int i = 0; i < SIZE; i++) {
        // Finds the value once it's equal to mid
        if (arr[mid] == target) {
            return i;
        }
        // Determines upper vs lower half
        else if (target > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid -1;
        }
    }
    // Failsafe in case the value is not found
}
/*This simple swap function takes two values (from our array) and swaps their positions
by reference*/
void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}
/*The selection sort function takes an array as a parameter and sorts it by
swapping lowest index values to the beginning of the list. It uses a double
for loop which gives it a time complexity of O(n^2)*/
void selectionSort(int arr[SIZE]) {
    int minIndex; // Declares an empty minimum index
    for (int i = 0; i < SIZE; i++) {
        minIndex = i; // Sets the minimum index to the value of i (0 in first iteration)
        for (int j = i + 1; j < SIZE; j++) { // Second loop to adjust the minimum index
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]); // Swaps the current value of i with the minimum index the 2nd
        // loop determined
    }
}
/*My printList function prints the list so I can repeat it multiple times in the main function*/
void printList(int arr[SIZE]) {
    cout << "List: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}