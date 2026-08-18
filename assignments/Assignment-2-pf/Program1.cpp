#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


double unitSlabRate[8] = {12.21, 14.53, 31.51, 38.41, 41.62, 43.04, 44.18, 49.10};
double unitFixedCharges[6] = {0, 200, 400, 600, 800, 1000};



struct Customer {

string name;
long long ID;
char type;
char installedMeter;

};

Customer customer;

void registration();
void displayMenu();
double calculateBill();
double newConnectionCharges();
void viewDetails();
void meterInstallationType();




int main() {
cout<<"LESCO Bill Management\n\n\n"<<endl;

registration();
displayMenu();
    return 0;
}




void registration (){


cout<<"1. User Registration\n"<<endl;

cout<<"\nEnter Customer Name : ";
getline(cin,customer.name);
cout<<"\n\nEnter Customer ID : ";
cin>> customer.ID;
cout<<"\n\nType of customer is? \n\t 1. HouseHold \n\t 2. Commercial"<<endl;
cin>> customer.type;

switch(customer.type){
	case '1':
		cout<<"\nType of Customer is : HouseHold."<<endl;
		break;
		
	case '2':
		cout<<"\nType of customeer is : Commercial."<<endl;
		break;
		default:
			cout<<"\nInvalid option selected kindly press 1 or 2."<<endl;
			
}

cout<<"\nNumebr of Meters already installed are : \n\t 1. No Meter. \n\t 2. Second Meter."<<endl;
cin>> customer.installedMeter;

meterInstallationType();

cout<< "\n\t\tConnection Registered! "<<endl;
}





void meterInstallationType (){
	switch(customer.installedMeter){
	case '1':
	cout<<"\nConnection selected as : First Meter Connection "<<endl;
	break;
	case '2':
	cout<<"\nConnection selected as : Second Meter connection"<<endl;
	break;
	default:
		cout<<"\nInvalid option selected kindly press 1 or 2."<<endl;
}
}





void displayMenu(){
	int choice;
	do{
	cout << "\n=== MAIN MENU ===\n";
        cout << "1. Calculate Monthly Electricity Bill\n";
        cout << "2. Apply for New Electricity Connection\n";
        cout << "3. View Customer Details\n";
        cout << "4. Exit Program\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: calculateBill(); break;
            case 2: newConnectionCharges(); break;
            case 3: viewDetails(); break;
            case 4: cout << "Exiting program... Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
}
} while(choice !=4);
	
}




double newConnectionCharges(){
	cout<<"\n\n\tConnection charges are : "<<endl;
	double meterCost = 15000;
	double meterCableCost = 10000;
	double securityCost = 5000;
	double additionalCharges = 0;
	
cout<<"\n\nType of customer is? \n\t 1. HouseHold \n\t 2. Commercial"<<endl;
customer.type = getch();

	switch(customer.type){
	case '1':
		cout<<"\nType HouseHold selected.\n";
		cout<<"\nNumebr of Meters already installed are : \n\t 1. First Meter Connection. \n\t 2. Second Meter."<<endl;
	    customer.installedMeter = getch();
				switch(customer.installedMeter){
			case'1': additionalCharges = 2500; cout<<"First Meter Connection\n";break;
			case'2': additionalCharges = 5000; cout<<"Second Meter Connection\n";break;
            default: cout << "Invalid meter option.\n"; break;		}
		break;
		
	case '2':
		cout<<"\nType Commercial selected.\n";
		cout<<"\nNumebr of Meters already installed are : \n\t 1. No Meter. \n\t 2. Second Meter."<<endl;
		customer.installedMeter = getch();
				switch(customer.installedMeter){
			case'1': additionalCharges = 35000; cout<<"First Meter Connection\n";break;
			case'2': additionalCharges = 70000; cout<<"Second Meter Connection\n";break;
			default: cout << "Invalid meter option.\n"; break;	
			}

		
		break;
		default:
			cout<<"\nInvalid option selected kindly press 1 or 2."<<endl;
		}


double newConnectionCost = 250000;
double totalConnectionCost = newConnectionCost + meterCost + meterCableCost + securityCost + additionalCharges;

cout << "Meter Cost: " << meterCost << endl;
cout << "Cable Cost: " << meterCableCost << endl;
cout << "Security Cost:" << securityCost << endl;
cout<<"New Connection Charges : "<< newConnectionCost<<endl;
cout<<"Additional Charges are : "<< additionalCharges<<endl;
cout<<"Total Connection Cost : "<<totalConnectionCost<<endl;
	
}




void viewDetails() {
    cout << "\n=== Customer Details ===\n";
    cout << "Name: " << customer.name << endl;
    cout << "ID: " << customer.ID << endl;
    cout << "Type: " << (customer.type == '1' ? "Household" : "Commercial") << endl;
    cout << "Meter: " << (customer.installedMeter == '1' ? "First Meter" : "Second Meter") << endl;
}



//slab rate
double calculateConsumptionCharges(int units) {
     double rate = (units <= 100) ? unitSlabRate[0] :
           (units <= 200) ? unitSlabRate[1] :
           (units <= 300) ? unitSlabRate[2] :
           (units <= 400) ? unitSlabRate[3] :
           (units <= 500) ? unitSlabRate[4] :
           (units <= 600) ? unitSlabRate[5] :
           (units <= 700) ? unitSlabRate[6] :
                            unitSlabRate[7];
                            
        return units * rate;
}


//calculate fixed charges
double calculateFixedCharges(int units) {
    return (units <= 300) ? unitFixedCharges[0] :
           (units <= 400) ? unitFixedCharges[1] :
           (units <= 500) ? unitFixedCharges[2] :
           (units <= 600) ? unitFixedCharges[3] :
           (units <= 700) ? unitFixedCharges[4] :
                            unitFixedCharges[5];
}

//electricity duty (1.5% of consumption charges)
double calculateElectricityDuty(double consumptionCharges) {
    return 0.015 * consumptionCharges;
}

//GST (18% of subtotal)
double calculateGST(double subtotal) {
    return 0.18 * subtotal;
}

//income tax (10% household, 15% commercial)
double calculateIncomeTax(double subtotal) {
    return (customer.type == '1') ? 0.10 * subtotal : 0.15 * subtotal;
}

//display final bill
void displayFinalBill(int units, double consumptionCharges, double fixedCharges,
                      double electricityDuty, double GST, double incomeTax, double totalBill) {
    double meterRent = 250;
    double tvFee = 35;

    cout << "\n========== LESCO ELECTRICITY BILL ==========\n";
    cout << "Customer Name: " << customer.name << endl;
    cout << "Customer ID: " << customer.ID << endl;
    cout << "Customer Type: " << (customer.type == '1' ? "Household" : "Commercial") << endl;
    cout << "Units Consumed: " << units << endl;

    cout << "\nElectricity Consumption Charges: Rs. " << consumptionCharges;
    cout << "\nElectricity Duty: Rs. " << electricityDuty;
    cout << "\nFixed Charges: Rs. " << fixedCharges;
    cout << "\nMeter Rent: Rs. " << meterRent;
    cout << "\nTV Fee: Rs. " << tvFee;
    cout << "\nGST: Rs. " << GST;
    cout << "\nIncome Tax: Rs. " << incomeTax;

    cout << "\n\nTotal Payable Bill: Rs. " << totalBill << endl;
    cout << "============================================\n";
}

// Main function: calculate bill
double calculateBill() {
    int units;
    cout << "\nEnter units consumed: ";
    cin >> units;

    if (units < 0) {
        cout << "Invalid input: units cannot be negative.\n";
        return 0;
    }

    double meterRent = 250;
    double tvFee = 35;

    double consumptionCharges = calculateConsumptionCharges(units);
    double fixedCharges = calculateFixedCharges(units);
    double electricityDuty = calculateElectricityDuty(consumptionCharges);

    double subtotal = consumptionCharges + fixedCharges + meterRent + tvFee + electricityDuty;
    double GST = calculateGST(subtotal);
    double incomeTax = calculateIncomeTax(subtotal);

    double totalBill = subtotal + GST + incomeTax;

    displayFinalBill(units, consumptionCharges, fixedCharges, electricityDuty, GST, incomeTax, totalBill);

    return totalBill;
}

