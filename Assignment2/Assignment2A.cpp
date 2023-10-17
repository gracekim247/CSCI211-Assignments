#include <iostream>
using namespace std;

int main(){
	int *arr = new int[5];
	
	//to fill the array with values 1 to 5
	for (int i = 1; i<=5; i++){
		arr[i-1] = i;
	}

	//to print the elements of the array
	cout<<"The array is: ";
	for(int x = 0; x<5; x++){
		cout<<*(arr + x)<<" ";
	}
	cout<<endl;

	delete [] arr;

	return 0;
}
