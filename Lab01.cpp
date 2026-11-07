// ============================================================
// CIT-AI - Object Oriented Programming 2026-2027
// LAB-01 : All Tasks in one file
// Run one task at a time from the menu in main()
// ============================================================

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================
// Task 01: Resize Array (array of user-defined size, then expand it)
// ============================================================

// Returns a new array of double size:
// first half = original elements, second half = 2 x original elements
int* resizeArray(int inArray[], const int size)
{
    int* newArray = new int[size * 2];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = inArray[i];          // first half: original values
        newArray[i + size] = inArray[i] * 2; // second half: double values
    }
    return newArray;
}

void task01()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int* resized = resizeArray(arr, size);

    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++)
    {
        cout << resized[i];
        if (i < size * 2 - 1) cout << ", ";
    }
    cout << endl;

    // free memory (avoid memory leaks)
    delete[] arr;
    delete[] resized;
}

// ============================================================
// Task 02: Diagonal Matrix (square matrix, check if diagonal)
// ============================================================

bool isDiagonal(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && matrix[i][j] != 0) // outside main diagonal must be zero
                return false;
    return true;
}

void task02()
{
    int n;
    cout << "Enter size of the square matrix: ";
    cin >> n;

    // create 2-D dynamic array
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    cout << "Enter the matrix values:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    if (isDiagonal(matrix, n))
        cout << "The matrix is a diagonal matrix." << endl;
    else
        cout << "The matrix is NOT a diagonal matrix." << endl;

    // free memory
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

// ============================================================
// Task 03: Substring from left (char array of size 30)
// ============================================================

void task03()
{
    char text[30];
    int count;

    cin.ignore(); // clear leftover newline
    cout << "Enter a string (max 29 characters): ";
    cin.getline(text, 30);

    cout << "Enter count of letters: ";
    cin >> count;

    int length = strlen(text);

    if (count < 0 || count > length)
    {
        cout << "Error: count is out of range (string length is "
             << length << ")." << endl;
    }
    else
    {
        cout << "Substring: ";
        for (int i = 0; i < count; i++)
            cout << text[i];
        cout << endl;
    }
}

// ============================================================
// main
// ============================================================
int main()
{
    int choice;
    cout << "LAB-01\n1) Task 01\n2) Task 02\n3) Task 03\nChoose a task: ";
    cin >> choice;

    switch (choice)
    {
    case 1: task01(); break;
    case 2: task02(); break;
    case 3: task03(); break;
    default: cout << "Invalid choice." << endl;
    }
    return 0;
}
