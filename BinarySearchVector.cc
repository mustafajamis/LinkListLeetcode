#include <iostream>
#include <vector> // Include the vector library
using namespace std;

int BinarySearch(vector<int>& vec, int first, int last, int key){ // Change the parameter to a vector reference
    while (first <= last){
        int mid = first + (last - first) / 2;
        if(vec[mid] == key){
            return mid;
        } else if (vec[mid] < key){
                    first = mid + 1;
                } else {
                    last = mid -1;
                    } 
        }
    return -1;
} 

int main() {

    vector<int> numbers = {2,4,5,11,13,20,23,36,45,55,59,66,70,75,90}; // Use a vector instead of an array
    int key = 0; 

    cout<< "Enter the value you would like to search for: ";
    cin>> key;

    int result = BinarySearch(numbers, 0, 14, key); // Pass the vector by reference

    if (result != -1) {
        cout<<"The value "<<key<<" was found in position "<<result<<endl;
    } else {
        cout<<  "The value "<<key<<" was not found\n";
    }

}
