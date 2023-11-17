/*
    Problem Statement: Write a program for analysis of quick sort by using deterministic and randomized variant.
*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &nums)
{
    cout << "Displaying the elements:- " << endl;
    for (int &num : nums)
        cout << num << " ";
    cout << endl;
}

/*
    Quicksort sorting algorithm using Deterministic variant

    Time Complexity:
        Best Case: O(nlogn)
        Average Case: O(nlogn)
        Worst Case: O(n^2)

    Space Complexity: O(1) + Call Stack (O(logn))
*/

// partition using the Lomuto partition scheme
int partition(vector<int> &nums, int start, int end)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = nums[end];

    // Elements less than or equal to the pivot will be pushed to the left of pIndex
    // Elements greater than the pivot will be pushed to the right of pIndex
    int pIndex = start;

    // Each time we find an element less than or equal to the pivot, pIndex and that element is swap such that, the element is placed before the pivot element. And then pIndex is incremented
    for (int i = start; i < end; i++)
    {
        if (nums[i] <= pivot)
        {
            swap(nums[pIndex], nums[i]);
            pIndex++;
        }
    }

    // swap pIndex with pivot
    swap(nums[pIndex], nums[end]);

    // return pIndex (index of the pivot element)
    return pIndex;
}
void quickSort_deterministic(vector<int> &nums, int start, int end)
{
    // Base Case
    if (start >= end)
        return;

    // Rearrange elements across pivot
    int pivot = partition(nums, start, end);

    // recur on subarray containing elements that are less than the pivot
    quickSort_deterministic(nums, start, pivot - 1);
    // recur on subarray containing elements that are greater than the pivot
    quickSort_deterministic(nums, pivot + 1, end);
}

/*
    Quicksort sorting algorithm using Randomized variant

    Time Complexity:
        Best Case: O(nlogn)
        Average Case: O(nlogn)
        Worst Case: O(nlogn)

    Space Complexity: O(1) + Call Stack (O(logn))
*/
// A randomized partition routine
int randomized_partition(vector<int> &nums, int start, int end)
{
    // choose a random index between `start` and `end`
    int pivotIndex = (rand() % (end - start + 1)) + start;

    // swap the end element with the element present at random index
    swap(nums[pivotIndex], nums[end]);

    // call partition procedure
    return partition(nums, start, end);
}
void quickSort_randomized(vector<int> &nums, int start, int end)
{
    // Base Case
    if (start >= end)
        return;

    // Rearrange elements across pivot
    int pivot = randomized_partition(nums, start, end);

    // recur on subarray containing elements that are less than the pivot
    quickSort_randomized(nums, start, pivot - 1);
    // recur on subarray containing elements that are greater than the pivot
    quickSort_randomized(nums, pivot + 1, end);
}

int main()
{
    try
    {
        int n;
        cout << "Enter the number of elements: ";
        while (!(cin >> n))
        {
            cout << "Invalid input. Please enter a positive number" << endl;

            cout << "Enter the number of elements: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the element: ";
            cin >> nums[i];
        }
        cout << endl;

        display(nums);
        cout << endl;

        int option;
        do
        {
            cout << " --------------------------------------- MENU --------------------------------------- " << endl;
            cout << " 1. Quicksort by using Deterministic variant" << endl;
            cout << " 2. Quicksort by using Randomized variant" << endl;
            cout << " 3. Exit" << endl;
            cout << "Enter the option: ";
            cin >> option;

            switch (option)
            {
            case 1:
                quickSort_deterministic(nums, 0, n - 1);
                display(nums);
                break;

            case 2:
                quickSort_randomized(nums, 0, n - 1);
                display(nums);
                break;

            case 3:
                exit(0);

            default:
                cout << "Invalid Option." << endl;
                break;
            }
            cout << endl;
        } while (option >= 1 && option <= 3);
    }
    catch (string errorMessage)
    {
        cout << errorMessage << endl;
    }
    return 0;
}