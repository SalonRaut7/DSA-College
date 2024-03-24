#include<iostream>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
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
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selectionsort(int arr[],int n){
    int temp; 
    for(int i=0;i<n-1;i++){  
        for(int j=i+1;j<n;j++) {  
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        } 
    }
}
int linearSearch(int arr[], int n, int element){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
 
int binarySearch(int arr[], int n, int element){
    int low, mid, high;
    low = 0;
    high =n-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}
void check(int arr[],int val){
    if(val==-1){
        cout<<"There is no such element in the array."<<endl;
    }
    else{
        cout<<"The element was found at index "<<val<<" which is: "<<arr[val]<<endl;
    }
}
int main(){
    int choice,element,n,index;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"1.Bubblesort"<<endl;
    cout<<"2.Selectionsort"<<endl;
    cout<<"3.Insertionsort"<<endl;
    cout<<"4.LinearSearch"<<endl;
    cout<<"5.BinarySearch"<<endl;
    cout<<"6.Exit"<<endl;
    while(1){
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                Bubblesort(a,n);
                cout<<"The sorted elements are: "<<endl;
                display(a,n);
                break;
            case 2:
                selectionsort(a,n);
                cout<<"The sorted elements are: "<<endl;
                display(a,n);
                break;
            case 3:
                insertionSort(a,n);
                cout<<"The sorted elements are: "<<endl;
                display(a,n);
                break;
            case 4:
                cout<<"Enter data to be searched: ";
                cin>>element;
                index=linearSearch(a,n,element);
                check(a,index);
                break;
            case 5:
                cout<<"Enter data to be searched: ";
                cin>>element;
                index=binarySearch(a,n,element);
                check(a,index);
                break;
            case 6:
                exit(0);
            default:
                cout<<"Invalid choice.Please try again.."<<endl;
        }
    }
    return 0;
}