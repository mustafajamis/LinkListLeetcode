// bianry search looking for the specific value. example targer = 10
//        0  1  2  3   4   5  6    # 
// array [2, 3, 4, 6 , 8, 10, 12 ] # Formula M = L + (R-L / 2)
//       L<-------|M|----------->R #
// since is 6 > 4 we looking to second portion of the array
// Binary Search is O (log n)

#include <iostream>
#include <cstdlib>
using namespace std;

int BinarySearch(int arr[], int first, int last, int key){
    while (first <= last){
        int mid = first + (last - first) / 2;
        if(arr[mid] == key){
            return mid;
        } else if (arr[mid] < key){
                    first = mid + 1;
                } else {
                    last = mid -1;
                    } 
        }
    return -1;
} 

int main() {

    int numbers[] = {2,4,5,11,13,20,23,36,45,55,59,66,70,75,90};
    int key = 0; 

    cout<< "Enter the value you would like to search for: ";
    cin>> key;

    int result = BinarySearch(numbers, 0, 14, key);

    if (result != -1) {
        cout<<"The value "<<key<<" was found in position "<<result<<endl;
    } else {
        cout<<  "The value "<<key<<" was not found\n";
    }

}