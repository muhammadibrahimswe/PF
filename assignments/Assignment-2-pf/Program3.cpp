#include<iostream> 
#include<string> 
using namespace std; 
 
//Globe var 
string Name; 
int id; 
int cTypeChoice;    
int payChoice;      
 
string items[8] = {"Rice 1 KG", "Sugar 1 KG", "Cooking Oil 1 Litre", "Milk Pack", "Tea Pack", "Flour 5 KG", "Eggs Dozen", "Detergent"};
double prices[8] = {350.0, 180.0, 580.0, 220.0, 450.0, 950.0, 320.0, 600.0}; 
int cart[8] = {0};  
 
void registerCustomer(); 
void displayGroceryList(); 
void addItemsToCart(); 
double calcGrossBill(); 
double calcSalesTax(); 
double calcMembershipDiscount(double gross); 
double calcBillAmountDiscount(double gross); 
double calcCardCharges(double amountToPay); 
double calcLoyaltyPoints(double currentBill); 
void displayFinalBill(); 
void viewCustomerDetails(); 
 
int main() { 
    registerCustomer(); 
     
    int menuChoice; 
    do { 
        cout << "\n===== MAIN MENU =====" << endl; 
        cout << "1. View Grocery Items" << endl; 
        cout << "2. Add Items to Cart" << endl; 
        cout << "3. Calculate Bill" << endl; 
        cout << "4. View Customer Details" << endl; 
        cout << "5. Exit" << endl; 
        cout << "Enter Choice: "; 
        cin >> menuChoice; 
 
        if (menuChoice == 1) displayGroceryList(); 
        else if (menuChoice == 2)  
            addItemsToCart(); 
        else if (menuChoice == 3)  
            displayFinalBill(); 
        else if (menuChoice == 4)  
            viewCustomerDetails(); 
        else if (menuChoice == 5)  
            cout << "Exiting Program. Goodbye!" << endl; 
        else  
            cout << "Invalid Choice! Try again." << endl; 
         
    } while (menuChoice != 5); 
 
    return 0; 
} 
 
void registerCustomer() { 
    cout << "\n--- Customer Registration ---" << endl; 
    cout << "Enter Customer Name: "; 
    cin.ignore(); 
    getline(cin, Name); 
     
    cout << "Enter Customer ID: "; 
    cin >> id; 
     
    cout << "Select Customer Type (1.Regular, 2. Member): "; 
    cin >> cTypeChoice; 
     
    cout << "Select Payment Method (1.Cash, 2.Card): "; 
    cin >> payChoice; 
} 
 
void displayGroceryList() { 
    cout << "\n--- Grocery Items ---" << endl; 
    cout << "Item No.\tGrocery Item\t\tPrice" << endl; 
    for(int i = 0; i < 8; i++) { 
        cout << i + 1 << "\t" << items[i] << "\tRs. " << prices[i] << endl; 
    } 
} 
 
void addItemsToCart() { 
    int itemNo, qty; 
    cout << "\nEnter Item No to buy (1-8), or 0 to stop adding: "; 
    do { 
        cin >> itemNo; 
        if (itemNo >= 1 && itemNo <= 8) { 
            cout << "Enter quantity for " << items[itemNo - 1] << ": "; 
            cin >> qty; 
            cart[itemNo - 1] += qty;  
            cout << "Added! Enter next Item No (or 0 to stop): "; 
        } else if (itemNo != 0) { 
            cout << "Invalid Item No! Try again: "; 
        } 
    } while (itemNo != 0); 
} 
 
double calcGrossBill() { 
    double gross = 0.0; 
    for(int i = 0; i < 8; i++) { 
        gross += (cart[i] * prices[i]); 
    } 
    return gross; 
} 
 
double calcSalesTax() { 
    double tax = 0.0; 
    for(int i = 0; i < 7; i++) { 
        tax += (cart[i] * prices[i]) * 0.05; 
    } 
    tax += (cart[7] * prices[7]) * 0.10; 
     
    return tax; 
} 
 
double calcMembershipDiscount(double gross) { 
    if (cTypeChoice == 2) { 
        return gross * 0.07;  
    } 
    return 0.0; 
} 
 
double calcBillAmountDiscount(double gross) { 
    if (gross > 10000) return gross * 0.10; 
    else if (gross >= 5000) return gross * 0.05;  
    return 0.0; 
} 
 
double calcCardCharges(double amountToPay) { 
    if (payChoice == 2) { 
        return amountToPay * 0.05;  
    } else if (payChoice == 1) { 
        return amountToPay * 0.16; 
    } 
    return 0.0; 
} 
 
double calcLoyaltyPoints(double currentBill) { 
    return currentBill / 100.0; 
} 
 
void displayFinalBill() { 
    double gross = calcGrossBill(); 
    if (gross == 0) { 
        cout << "\nYour cart is empty! Add items first." << endl; 
        return; 
    } 
 
    double salesTax = calcSalesTax(); 
    double memDisc = calcMembershipDiscount(gross); 
    double billDisc = calcBillAmountDiscount(gross); 
     
    double subtotal = gross + salesTax - memDisc - billDisc; 
    double paymentCharges = calcCardCharges(subtotal); 
     
    double totalPayable = subtotal + paymentCharges; 
     
    string typeStr = (cTypeChoice == 2) ? "Member" : "Regular"; 
    string payStr = (payChoice == 2) ? "Card" : "Cash"; 
 
    cout << "\n========== GROCERY MART BILL ==========" << endl; 
    cout << "Customer Name: " << Name << endl; 
    cout << "Customer Type: " << typeStr << endl; 
    cout << "Payment Method: " << payStr << endl; 
    cout << "Gross Bill: Rs. " << gross << endl; 
    cout << "Sales Tax: Rs. " << salesTax << endl; 
    cout << "Membership Discount: Rs. " << memDisc << endl; 
    cout << "Bill Discount: Rs. " << billDisc << endl; 
     
    if (payChoice == 2) cout << "Card Charges (5%): Rs. " << paymentCharges << endl; 
    else cout << "Cash Tax (16%): Rs. " << paymentCharges << endl; 
     
    cout << "\n--- Loyalty Points Program ---" << endl; 
    int generatedPoints = calcLoyaltyPoints(totalPayable); 
    cout << "Generated Loyalty Points: " << generatedPoints << endl; 
     
    int existingPoints = 0; 
    cout << "Enter Your Existing Loyalty Points (0 for new user): "; 
    cin >> existingPoints; 
     
    int totalPoints = generatedPoints + existingPoints; 
    cout << "Loyalty Points after Purchase: " << totalPoints << endl; 
     
    int redeemChoice; 
    cout << "Press 1 to redeem your loyalty points, Press 2 to continue: "; 
    cin >> redeemChoice; 
     
    if (redeemChoice == 1) { 
        cout << "Redeemed " << totalPoints << " points for Rs. " << totalPoints << " discount!" << endl; 
        totalPayable -= totalPoints;  
        totalPoints = 0;  
    } 
     
    cout << "---------------------------------------" << endl; 
    cout << "Total Payable Amount: Rs. " << totalPayable << endl; 
    cout << "Thank You For Shopping :)" << endl; 
    cout << "=======================================" << endl; 
     
    for(int i = 0; i < 8; i++) cart[i] = 0;  
} 
 
void viewCustomerDetails() { 
    cout << "\n--- Customer Details ---" << endl; 
    cout << "Name: " << Name << endl; 
    cout << "ID: " << id << endl; 
    cout << "Type: " << ((cTypeChoice == 2) ? "Member" : "Regular Customer") << endl; 
    cout << "Payment Preference: " << ((payChoice == 2) ? "Card" : "Cash") << endl; 
} 
