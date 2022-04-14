#include <iostream>
#define size 10
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() { next = NULL; }
};

int hash_func(int num)
{
    int val = num % size;
    return val;
}

void hash_table(Node *arr[], int index, int val)
{
    Node *temp = arr[index];
    if (temp->data == 0)
    {
        temp->data = val;
    }
    // Collision resolution
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *new_node = new Node();
        new_node->data = val;
        temp->next = new_node;
    }
}

// Taking input from the user
void set_data(Node *arr[])
{
    int no, num, index;

    cout << "How many elements you want to insert in Hash Table of Size " << size << " : ";
    cin >> no;

    for (int i = 0; i < no; i++)
    {
        cout << "Enter the number : ";
        cin >> num;
        index = hash_func(num);
        hash_table(arr, index, num);
    }
}

void print_hash(Node *arr[])
{
    cout << "Hash Table : \n";
    for (int i = 0; i < size; i++)
    {
        if (arr[i]->data == 0)
        {
            cout << arr[i]->data;
        }

        else if (arr[i]->data != 0)
        {
            cout << arr[i]->data;
            while (arr[i]->next != NULL)
            {
                arr[i] = arr[i]->next;
                cout << "->" << arr[i]->data;
            }
        }

        cout << endl;
    }
    cout << endl;
}

int main()
{
    Node *arr[size]; // initializing a hash table

    for (int i = 0; i < size; i++)
    {
        arr[i] = new Node();
        arr[i]->data = 0;
    }

    print_hash(arr); // to print the default Hash Table
    set_data(arr);
    print_hash(arr); // to print the hashed table

    cout << endl;
    return 0;
}
