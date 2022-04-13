#include <iostream>
#define size 10
using namespace std;

int hash_func(int num)
{
    int val = num % size;
    return val;
}

void simpleHashTable(int arr[], int index, int val)
{
    int arr1 = *arr;
    if (arr[index] == 0)
    {
        arr[index] = val;
    }
    else
    {
        cout << "\nCollision Occurs !\nTry again.\n\nEnter a number : ";
        cin >> val;
        index = hash_func(val);
        simpleHashTable(arr, index, val);
    }
}

void set_data(int arr[])
{
    int no, num, index;

    cout << "How many nos you want to insert : ";
    cin >> no;
    for (int i = 0; i < no; i++)
    {
        cout << "Enter the number : ";
        cin >> num;
        index = hash_func(num);
        simpleHashTable(arr, index, num);
    }
}

void print_hash(int arr[])
{
    cout << "Hash Table : \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\n";
    }
}

int main()
{
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    set_data(arr);
    print_hash(arr);

    cout << endl;
    return 0;
}