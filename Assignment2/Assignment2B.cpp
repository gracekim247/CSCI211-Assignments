#include <iostream>
using namespace std;

class Rectangle{
	private:
		double length;
		double width;

	public: 
		//Constructor
		Rectangle(double l, double w){
			length = l;
			width = w;
		}
		
		//Method calculates and returns the area
		double calculateArea(){
			double area = length*width;
			return area;
		}
};


int main(){
	Rectangle rect = Rectangle(5.0, 3.0);

	//Print the area of the rectangle
	cout<<"The area of a rectangle that is 5x3 is: "<<rect.calculateArea()<<endl;

	return 0;
}
