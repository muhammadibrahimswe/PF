#include <iostream>


using namespace std;



int main() {
 cout << "=== Question 18: Health Club Membership ===\n\n";

      int membershipChoice, months;
      cout << "  1. Standard Adult  - Rs. 40.00/month\n";
      cout << "  2. Child           - Rs. 20.00/month\n";
      cout << "  3. Senior Citizen  - Rs. 30.00/month\n";
      cout << "  4. Quit\n";
      cout << "  Enter your choice: ";
      cin >> membershipChoice;

      if (membershipChoice >= 1 && membershipChoice <= 3) {
        cout << "  Enter number of months: ";
        cin >> months;
        
        if(months !=0){
		
        // Determine rate based on membership type
        double rate = (membershipChoice == 1)   ? 40.0
                      : (membershipChoice == 2) ? 20.0
                                                : 30.0;

        cout << "  Total amount to pay: Rs. " << rate * months << "\n";}
        else 
        cout << " Process Terminated!  Choose atleast one month for the Process to Continue" << endl;
      } else if (membershipChoice == 4) {
        cout << "  Thank you for using the program.\n";
      } else {
        cout << "  [!] Invalid choice.\n";
    return 0;
}
}

