/*
    Problem Statement:
    Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.

    Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, .....
*/

#include <bits/stdc++.h>
using namespace std;

void Display_Sequence(vector<int> &fibonacci_sequence)
{
    cout << "Fibonacci Sequence is :- " << endl;
    for (int &term : fibonacci_sequence)
        cout << term << " ";
    cout << endl;
}

/*
    Function to calculate Fibonacci numbers Non-Recursively

    Time Complexity: O(N)
    Space Complexity: O(N)
*/
void Fibonacci_Sequence_NonRecursive(int n)
{
    vector<int> fibonacci_sequence(n + 1);
    fibonacci_sequence[0] = 0;
    fibonacci_sequence[1] = 1;

    for (int i = 2; i <= n; i++)
        fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];

    Display_Sequence(fibonacci_sequence);
}

int fibonacci(int n)
{
    // Base Case
    if (n <= 1)
        return n;

    // Recursive Calls
    return fibonacci(n - 1) + fibonacci(n - 2);
}
/*
    Function to calculate Fibonacci numbers Recursively

    Time Complexity: O(2^n)
    Space Complexity: O(1) + Recursive call stack (implicit stack) space

    We are calling the fibonacci function for 'n' numbers so total: Time complexity is O(n*2^n)
*/
void Fibonacci_Sequence_Recursive(int n)
{
    vector<int> fibonacci_sequence(n + 1);
    for (int i = 0; i <= n; i++)
        fibonacci_sequence[i] = fibonacci(i);

    Display_Sequence(fibonacci_sequence);
}

int main()
{
    try
    {
        int option;
        int n;

        do
        {
            cout << " ---------------------- MENU ---------------------- " << endl;
            cout << " 1. Fibonacci Sequence Non-Recursive" << endl;
            cout << " 2. Fibonacci Sequence Recursive" << endl;
            cout << " 3. Exit" << endl;
            cout << "Enter the option : ";
            cin >> option;

            if (option == 1 || option == 2)
            {
                cout << "Enter the number of terms to be present in Fibonacci numbers : ";
                while (!(cin >> n))
                {
                    cout << "Invalid input. Please enter a positive number" << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            switch (option)
            {
            case 1:
                Fibonacci_Sequence_NonRecursive(n);
                break;

            case 2:
                Fibonacci_Sequence_Recursive(n);
                break;

            case 3:
                exit(0);

            default:
                cout << "Invalid Option" << endl;
                break;
            }
        } while (option >= 1 && option <= 3);
    }
    catch (string errorMessage)
    {
        cout << errorMessage << endl;
    }

    return 0;
}
