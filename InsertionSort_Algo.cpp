#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int arrayOfNumbers[150],arraySize,number,index;
    cout << "Enter the size of list of numbers to be sorted:" << endl;
    cin >> arraySize; //inputs the size of Array that to be sorted!
    cout << "Now enter the list of numbers to be sorted separated by space:" << endl;
    for(int i=0;i<arraySize;i++){ //loop to populate the Array to be sorted!
        cin >> number;
        arrayOfNumbers[i]=number;
    }
    int key;
    for(int j=1;j<arraySize;j++){
        key = arrayOfNumbers[j];
        index = j-1;
        while(index > -1 && arrayOfNumbers[index]>key){
            arrayOfNumbers[index + 1]=arrayOfNumbers[index];
            index=index-1;
        }
        arrayOfNumbers[index+1]= key;

    }
     cout<<"The sorted List of Numbers after applying insertion sort is:"<<endl;
    for(int k=0;k<arraySize;k++){ //Loop to display the Sorted List.
        cout << arrayOfNumbers[k] << setw(3);
    }
    return 0;
}

