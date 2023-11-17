/*
    Problem Statement: Write a program to solve a 0/1 Knapsack problem using dynamic programming or branch and bound strategy.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    0/1 Knapsack using Dynamic Programming Approach

    Recursion :-
        Time Complexity: O(2^n)
        Space Complexity: O(1) + Recursive call stack (implicit stack) space
        Strategy: Include / Exclude current item. (Take / Not_Take)

    Memoization :-
        Time Complexity: O(n * knapsackWeight)
        Space Complexity: O(n * knapsackWeight)
        Strategy: Include / Exclude current item. (Take / Not_Take)

        Thus, number of states are (n * knapsackWeight) and transitions is O(1)
*/
vector<vector<double>> memo; // Memoization (Cached data)

double knapsack(int index, double capacity, vector<pair<double, double>> &items, int &n)
{
    // Base Case
    if (index >= n)
        return 0;

    // Cache Check
    if (memo[index][capacity] != -1.0)
        return memo[index][capacity];

    // Recurisve Calls
    double exclude = 0 + knapsack(index + 1, capacity, items, n); // Excluding (Not Taking) the current item

    double include = 0;
    if (items[index].second <= capacity)
        include = items[index].first + knapsack(index + 1, capacity - items[index].second, items, n); // Including (Taking) the current item

    return memo[index][capacity] = max(exclude, include);
}

int main()
{
    try
    {
        int n;
        cout << "Enter the number of items : ";
        while (!(cin >> n))
        {
            cout << "Invalid input. Please enter a positive number" << endl;

            cout << "Enter the number of items : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<pair<double, double>> items(n); // { profit,weight }
        double profit, weight;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the item's Profit and Weight: ";
            cin >> profit >> weight;
            items[i] = {profit, weight};
        }

        double knapsackWeight;
        cout << "Enter the knapsack weight : ";
        while (!(cin >> knapsackWeight))
        {
            cout << "Invalid input. Please enter a positive number" << endl;

            cout << "Enter the knapsack weight : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        memo.resize(n + 1, vector<double>(knapsackWeight + 1, -1.0));
        cout << "The Maximum Profit we can have within the given items and knapsack weight is: " << knapsack(0, knapsackWeight, items, n) << endl;
    }
    catch (string errorMessage)
    {
        cout << errorMessage << endl;
    }

    return 0;
}