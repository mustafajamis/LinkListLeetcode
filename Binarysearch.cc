// bianry search looking for the specific value. example targer = 10
//        0  1  2  3   4   5  6    # 
// array [2, 3, 4, 6 , 8, 10, 12 ] # Formula M = L + (R-L / 2)
//       L<-------|M|----------->R #
// since is 6 > 4 we looking to second portion of the array
// Binary Search is O (log n)

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // the key to do binary search is the data should be in order otherwise we're not able to do binary search
    int numbers[] = {2,4,5,11,13,20,23,36,45,55,59,66,70,75,90};
    int first = 0;
    int last = 14;
    int mid = 0;
    int key = 0; 
    bool found = false;

    cout<< "Enter the value you would like to search for: ";
    cin>> key;
    while (first <= last && !found) {
    //    mid = (first + last) / 2; 
        mid = first + (last - first / 2);
        if ( key > numbers[mid]) {
            first = mid + 1;
        } else if ( key < numbers[mid]) {
            last = mid - 1;
        } else {
            cout<<"The value "<<key<<" was found in postion "<<mid<<endl;
            found = true;
        }
    }
    if(!found) {
        cout<< "The value "<<key<<" was not found\n";
    }
}
