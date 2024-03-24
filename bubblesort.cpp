#include<iostream>
using namespace std;
void printarray(int* A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" "; 
    }
    cout<<endl;
}
void Bubblesort(int* A,int n){
    int temp;
    int isSorted=0;
    for(int i=0;i<n-1;i++){  //for number of passes
    cout<<"Working on pass number: "<<i+1<<endl;
    isSorted=1;
        for(int j=0;j<n-1-i;j++) {  //FOR NUMBER OF COMPARISIONS IN EACH PASS
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0;
            }
        } 
        if(isSorted){
            return;
        }
    }
}
int main(){
    int A[]={12,54,65,7,23,9};
    int n=6;
    printarray(A,n);  //printing array before sorting
    Bubblesort(A,n); //function to sort the array
    printarray(A,n);  //printing array after sorting
    return 0;
}