// Insertion sort the first step is create temp storage the take the value of the index one and store it in temp 
// then exam the left element and compare it with temp if its larger than temp we swap the element now temo is empty
// we take second element (in array its 3) and assign it to temp then we compare it with left if its bigger than first 
// element we empty the temp and put the value back to its place and we keep the steps.
#include <iostream>

using namespace std;

void insertionSort(int a[], int length){
    for (int i = 1; i< length; i++){
        int key = a[i]; // to store the current value 
        int j = i- 1; // keep trucking postion
        while( j>= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j -1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = { 8, 2, 7, 4 ,5 ,1 , 9 ,3};
    int length = 8;
    insertionSort(a, length);
    for (int i =0; i < length; i++){
        cout<<"a["<< i <<"] =  "<<a[i]<<endl;
    }
}