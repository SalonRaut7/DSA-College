#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int element)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
void Bubblesort(int arr[],int n){
    int temp; 
    for(int i=0;i<n-1;i++){  //for number of passes
        for(int j=0;j<n-1-i;j++) {  //FOR NUMBER OF COMPARISIONS IN EACH PASS
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        } 
    }
}
void check(int arr[], int val)
{
    if (val == -1)
    {
        cout << "There is no such element in the array." << endl;
    }
    else
    {
        cout << "The element was found at index " << val << " which is: " << arr[val] << endl;
    }
}
int main()
{
    int choice, element, n, index;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "4.LinearSearch" << endl;
    cout << "5.BinarySearch" << endl;
    cout << "6.Exit" << endl;
    while (1)
    {
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 4:
            cout << "Enter data to be searched: ";
            cin >> element;
            index = linearSearch(a, n, element);
            check(a, index);
            break;
        case 5:
            cout << "Enter data to be searched: ";
            cin >> element;
            Bubblesort(a,n);
            index = binarySearch(a, n, element);
            check(a, index);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice.Please try again.." << endl;
        }
    }
    return 0;
}
