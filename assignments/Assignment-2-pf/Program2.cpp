#include <iostream> 
#include <string> 
using namespace std; 
 
string foodItems[8] = {"Chicken Burger", "Zinger Burger", "Pizza Small", "Pizza Large",  
"Chicken Biryani", "BBQ Platter", "Fries", "Cold Drink"}; 
int prices[8] = {450, 550, 900, 1800, 350, 1200, 250, 120}; 
struct Customer { 
    string name; 
    string contact; 
    string orderType; 
    int persons; 
} customer; 
int orderQuantities[8] = {0};  
 
void registerCustomer(); 
void displayMenu(); 
void placeOrder(); 
double calculateFoodBill(); 
double calculateServiceCharges(double foodBill); 
double calculateGST(double foodBill); 
double calculateDiscount(double foodBill); 
void displayFinalBill(); 
void displayCustomerDetails(); 
 
int main() { 
int choice; 
do { 
cout << "\n========== MAIN MENU ==========\n"; 
cout << "1.View food Menu\n"; 
cout << "2.Place Order\n"; 
cout << "3.Calculate Bill\n"; 
cout << "4.View customer Details\n"; 
cout << "5.Exit\n"; 
cout << "Enter your choice: "; 
cin >> choice; 
switch(choice) { 
    case 1:  
 displayMenu();  
 break; 
    case 2:  
 registerCustomer();  
 placeOrder();  
 break; 
   case 3:  
   displayFinalBill();  
    break; 
   case 4:  
   displayCustomerDetails();  
    break; 
   case 5: cout << "Exiting... Thank you!\n";   
           break; 
            default: cout << "Invalid choice. Try again.\n"; 
        } 
    } while(choice != 5); 
return 0;} 
 
void registerCustomer() { 
cout << "\nEnter Customer Name: "; 
cin.ignore(); 
getline(cin, customer.name); 
cout << "Enter contact Number: "; 
getline(cin, customer.contact); 
cout << "Order type ( Dine-in/Takeaway ): "; 
getline(cin, customer.orderType); 
cout << "Number of Persons: "; 
cin >> customer.persons; 
} 
 
void displayMenu() { 
cout << "\n======= FOOD MENU ==========\n"; 
    for(int i=0; i<8; i++) { 
    cout << i+1 << " . " << foodItems[i] << " - Rs . " << prices[i ] << endl; 
    } 
} 
 
void placeOrder() {  
int itemNo, qty; 
char more; 
 
    do { 
        displayMenu(); 
        cout << "\nEnter Item No to order  : "; 
        cin >> itemNo; 
        if(itemNo >=1 && itemNo <=8) { 
            cout << "Enter Quantity: "; 
            cin >> qty; 
            orderQuantities[itemNo-1] += qty; 
        } else { 
            cout << "Invalid item No .\n"; 
        } 
        cout << "Do you want to order more items? ( y/n ) : "; 
        cin >> more; 
    } while(more == 'y' || more == 'Y'); 
} 
 
 
double calculateFoodBill() { 
  
double total = 0; 
    for(int i=0; i<8; i++) { 
    total += orderQuantities[i] * prices[i]; 
} 
return total; 
} 
 
 
double calculateServiceCharges(double foodBill) { 
if(customer.orderType == "Dine-in" || customer.orderType == "dine-in") 
return foodBill * 0.10; 
else 
    return foodBill * 0.05; 
 
 
} 
 
 
 
double calculateGST(double foodBill) { 
return foodBill * 0.16; 
 
} 
 
 
 
double calculateDiscount(double foodBill) { 
 
if(foodBill >= 3000 && foodBill <= 5000) 
return foodBill * 0.05; 
else if(foodBill > 5000 && foodBill <= 10000) 
    return foodBill * 0.10; 
else if(foodBill > 10000) 
return foodBill * 0.15; 
else 
    return 0; 
 
} 
 
 
 
void displayFinalBill() { 
  
double foodBill = calculateFoodBill(); 
double serviceCharges = calculateServiceCharges(foodBill); 
 double gst = calculateGST(foodBill); 
double discount = calculateDiscount(foodBill); 
 
double total = foodBill + serviceCharges + gst - discount; 
 
    if(total > 5000) { 
        cout << "\nFree Delivery Applied!\n";} 
 
cout << "\n========= RESTAURANT BILL ==========\n"; 
cout<< "Customer Name: " << customer.name << endl; 
cout << "Order Type: " << customer.orderType << endl; 
cout<< "Number of persons: " << customer.persons << endl; 
cout << "\nfood Bill: Rs. " << foodBill; 
cout<< "\nService Charges: Rs. " << serviceCharges; 
cout<< "\nGST: Rs. " << gst; 
cout<< "\ndiscount: Rs. " << discount; 
cout<< "\n---------------------------------"; 
cout << "\nTotal Payable Amount: Rs. " << total << endl; 
cout<< "Enjoy your Meal :)" << endl; 
cout<< "=================================\n"; 
 
} 
 
void displayCustomerDetails() { 
  
cout << "\n======== CUSTOMER DETAILS ==========\n"; 
cout<< "Name: " << customer.name << endl; 
cout<< "Contact: " << customer.contact << endl; 
cout<< "Order type: " << customer.orderType << endl; 
cout<< "Number of Persons: " << customer.persons << endl; 
 
}
