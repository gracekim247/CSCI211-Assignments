#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CoffeeDrink{
	private:
		string drinkName;
		string size;
		double price;
		bool hasMilk;
		bool hasSugar;
	
	public:
		//default constructor
		CoffeeDrink(){drinkName = "americano"; size = "Small"; price = 2.00; hasMilk = false; hasSugar = false;}
		//Parameterized constructor 1
		CoffeeDrink(string name){drinkName = name; size = "Medium"; price = 3.75; hasMilk = true; hasSugar = true;}
		//Parameterized constructor 2
		CoffeeDrink(string n, string si, double p, bool m, bool su){
			drinkName = n;
			size = si;
			price = p;
			hasMilk = m;
			hasSugar = su;
		}

		//set methods
		void setSize(string siz){
			if(siz=="S") size = "Small";
			if(siz=="M") size = "Medium";
			if(siz=="L") size = "Large";
		}
		void setMilk(bool mi){hasMilk = mi;}
		void setSugar(bool sug){hasSugar = sug;}

		//calculateTotal method
		void calculateTotal(){
			double total=0;
			
			//small drink is $2.00
			if(size=="Small") total+=2.00;
			//medium drink is $3.75
			else if (size=="Medium") total+=3.75;
			//large drink is $5.50
			else if (size=="Large") total+=5.50;

			//Milk is +$0.75
			if(hasMilk) total+=0.75;
			//Sugar is +$0.50
			if(hasSugar) total+=0.50;

			price=total;
		}

		//display method
		void display(){
			cout<<"Drink: "<<size<<" "<<drinkName<<" with ";
			if(!hasMilk) cout<<"no ";
			cout<<"milk, and ";
			if(!hasSugar) cout<<"no ";
			cout<<"sugar"<<endl;
			//fixed<<setprecision(2) sets number of decimal places to 2
		        cout<<"Price: $"<<fixed<<setprecision(2)<<price<<endl;
		}
};

int main(){
	//User chooses the type of order
	cout<<"Would you like to quick order (Q), order from the menu (M), or customize your order (C)? (Enter 'Q','M','C'.) ";
	string orderType;
	cin>>orderType;
	//when the user inputs an invalid input
	while(!(orderType=="Q" || orderType=="M" || orderType=="C")){
		cout<<"Invalid input. Please enter another input. ";
		cin>>orderType;
	}

	//To quick order
	if (orderType=="Q"){
		CoffeeDrink drink;
		drink.calculateTotal();
		drink.display();
	}

	//To order from menu
	else if (orderType=="M"){
		cout<<"What type of drink would you like? ";
		string name2;
		cin>>name2;

		//Create CoffeeDrink obj and call parameterized constructor 1
		CoffeeDrink drink2(name2);
		drink2.calculateTotal();
		drink2.display();
	}

	//To customize order
	else if (orderType=="C"){
		//keeps looping until user confirms the order
		while(true){
			//Ask drink name
			cout<<"What type of drink would you like? ";
			string name3;
			cin>>name3;
		
			//Ask drink size
			cout<<"Small-$2.00, Medium-$3.75, Large-$5.50."<<endl;
		        cout<<"What size drink? (Enter 'Small','Medium','Large') ";
			string drinkSize;
			cin>>drinkSize;
			//Keeps asking user for another input if input is invalid
			while(!(drinkSize=="Small" || drinkSize=="Medium" || drinkSize=="Large")){
				cout<<"Invalid input. Please enter again. ";
				cin>>drinkSize;
			}
		
			//Ask to add milk
			cout<<"Would you like to add milk for $0.75? (Enter 'Yes' or 'No') ";
			string milk;
			cin>>milk;
			//When input is invalid
                	while(!(milk=="Yes" || milk=="No")){
               		        cout<<"Invalid input, Please enter again. ";
                        	cin>>milk;
        	        }bool mil;
                	if (milk=="Yes") mil=true;
         	        else if (milk=="No") mil=false;
		
			//Ask to add sugar
			cout<<"Would you like to add sugar $0.50? (Enter 'Yes' or 'No') ";
			string sugar;
			cin>>sugar;
			//When input is invalid
			while(!(sugar=="Yes" || sugar=="No")){
				cout<<"Invalid input, Please enter again. ";
				cin>>sugar;
			}bool suga;
			if (sugar=="Yes") suga=true;
			else if (sugar=="No") suga=false;
		
			//If user wants to change their mind before confirming the drink order
			cout<<"Confirm order? ('Y' or 'N') ";
			string confirm;
			cin>>confirm;
			while(confirm!="Y" && confirm!="N"){
				cout<<"Invalid input, enter again. ";
				cin>>confirm;
			}
			//when user confirms order, create CoffeeDrink object using parameterized constructor 2 and calculate price and display drink details
			if(confirm=="Y"){
				CoffeeDrink drink3(name3, drinkSize, 0.00, mil, suga);	       
				drink3.calculateTotal();
				drink3.display();
				break;
			}
			cout<<"Restarting order."<<endl;
		}
	}
	cout<<endl;
	return 0;
}

