#include<iostream> 
#include<string> 
using namespace std; 
 
string cName, bName, bType, selectedPlatform; 
int days, platIndex =-1; 
 
string platform[3] = {"Instagram", "Facebook", "LinkedIn"}; 
int charges[3] = {15000, 12000, 20000}; 
 
string clientName(){ 
    string n; 
    cout<<"Client Name: "; 
    getline(cin,n); 
    return n; 
} 
 
string businessName(){ 
    string c; 
    cout<<"Business Name: "; 
    getline(cin,c); 
    return c; 
} 
 
string businessType(int choice){ 
    if(choice==1) return "Small Business"; 
    else if(choice==2) return "Medium Business"; 
    else if(choice==3) return "Corporate Business"; 
    else return "Invalid Choice"; 
} 
 
int campaignDuration(){ 
    int n; 
    cout<<"Campaign Duration (days): "; 
    cin>>n; 
    return n; 
} 
 
void displayPlatform(){ 
    cout<<" PLATFORMS "<<endl; 
    for(int i=0; i<3; i++){ 
        cout<<i+1<<". "<<platform[i]<<" - Rs. "<<charges[i]<<endl; 
    } 
} 
 
string selectPlatform(int choice){ 
    if(choice==1) 
 { platIndex=0;  
 return "Instagram"; } 
    else if(choice==2) 
 { platIndex=1;  
 return "Facebook"; } 
    else if(choice==3) 
 { platIndex=2;  
 return "LinkedIn"; } 
    else 
 { platIndex=-1; 
  return "Invalid"; } 
} 
 
int staticPost(){ 
    int s; 
    cout<<"Enter number of Static Posts: "; 
    cin>>s; 
    return s*1000; 
} 
 
int reelPost(){ 
    int r; 
    cout<<"Enter number of Reel Posts: "; 
    cin>>r; 
    return r*2500; 
} 
 
int carouselPost(){ 
    int c; 
    cout<<"Enter number of Carousel Posts: "; 
    cin>>c; 
    return c*1800; 
} 
 
int postDesignCost(){ 
    int totalcost = staticPost()+reelPost()+carouselPost(); 
    return totalcost; 
} 
 
int adBudget(){ 
    int budget; 
    cout<<"Enter Ad Budget: Rs. "; 
    cin>>budget; 
    return budget; 
} 
 
float adHandlingFee(int budget){ 
    if(budget<50000) 
        return budget*0.05; 
    else if(budget>=50000 && budget<=100000) 
        return budget*0.08; 
    else 
        return budget*0.10; 
} 
 
int extraDurationCharges(){ 
    if(days>30)  
 return (days-30)*500; 
    else return 0; 
 
} 
float calculateGST(float amount){ 
 return amount*0.16; 
} 
 
float calculateDiscount(float amount){ 
    if(bType=="Small Business") 
  return amount*0.05; 
    else if(bType=="Medium Business") 
  return amount*0.08; 
    else if(bType=="Corporate Business") 
  return amount*0.10; 
    else  
 return 0; 
} 
 
void displayBill(int postCost, int budget, float handling, int extraCharges){ 
    float totalBeforeGST = charges[platIndex]+postCost+budget+handling+extraCharges; 
    float gstAmount=calculateGST(totalBeforeGST); 
    float totalAfterGST = totalBeforeGST+gstAmount; 
    float discountAmount = calculateDiscount(totalAfterGST); 
    float finalCost = totalAfterGST-discountAmount; 
 
    cout<<" SOCIAL MEDIA CAMPAIGN BILL"<<endl; 
    cout<<"Client Name: "<<cName<<endl; 
    cout<<"Business Name: "<<bName<<endl; 
    cout<<"Business Type: "<<bType<<endl; 
    cout<<"Selected Platform: "<<selectedPlatform<<endl; 
    cout<<"Campaign Duration: "<<days<<" Days"<<endl; 
     
     
    cout<<"Platform Management Charges: Rs. "<<charges[platIndex]<<endl; 
    cout<<"Post Design Cost: Rs. "<<postCost<<endl; 
    cout<<"Ad Budget: Rs. "<<budget<<endl; 
    cout<<"Ad Handling Fee: Rs. "<<handling<<endl; 
    cout<<"Extra Duration Charges: Rs. "<<extraCharges<<endl; 
    cout<<"GST (16%): Rs. "<<gstAmount<<endl; 
    cout<<"Discount: Rs. "<<discountAmount<<endl; 
     
     
    cout<<"Final Campaign Cost: Rs. "<<finalCost<<endl; 
     
} 
 
void viewClientDetails(){ 
    cout<<" CLIENT DETAILS "<<endl; 
    cout<<"Client Name: "<<cName<<endl; 
    cout<<"Business Name: "<<bName<<endl; 
    cout<<"Business Type: "<<bType<<endl; 
    cout<<"Selected Platform: "<<selectedPlatform<<endl; 
    cout<<"Campaign Duration: "<<days<<" Days"<<endl; 
     
} 
 
int main(){ 
    cName = clientName(); 
    bName = businessName(); 
 
    int choice; 
    cout<<"Select Business Type:"<<endl; 
    cout<<"1. Small Business"<<endl; 
    cout<<"2. Medium Business"<<endl; 
    cout<<"3. Corporate Business"<<endl; 
    cout<<"Enter Choice: "; 
    cin>>choice; 
    bType = businessType(choice); 
    cout<<"Business Type: "<<bType<<endl; 
 
    days = campaignDuration(); 
 
    int menuChoice; 
    do{ 
        cout<<"\n===== MAIN MENU ====="<<endl; 
        cout<<"1. View Platforms"<<endl; 
        cout<<"2. Select Campaign Platform"<<endl; 
        cout<<"3. Calculate Campaign Cost"<<endl; 
        cout<<"4. View Client Details"<<endl; 
        cout<<"5. Exit"<<endl; 
        cout<<"Enter Choice: "; 
        cin>>menuChoice; 
 
        if(menuChoice==1){ 
            displayPlatform(); 
        } 
        else if(menuChoice==2){ 
            displayPlatform(); 
            cout<<"Select Platform (1-3): "; 
            cin>>choice; 
            selectedPlatform=selectPlatform(choice); 
            if(selectedPlatform =="Invalid"){ 
    
   cout<<"Invalid Platform Choice"<<endl;} 
   else{ 
            cout<<"Selected Platform: "<<selectedPlatform<<endl; 
        } 
    } 
        else if(menuChoice==3){ 
  if(platIndex==-1){ 
   cout<<"Select Platform First"<<endl; 
  } 
  else{ 
            int postCost = postDesignCost(); 
            int budget = adBudget(); 
            float handling = adHandlingFee(budget); 
            int extraCharges = extraDurationCharges(); 
            displayBill(postCost, budget, handling, extraCharges); 
        } 
        } 
        else if(menuChoice==4){ 
            viewClientDetails(); 
        } 
        else if(menuChoice==5){ 
            cout<<"Exit"<<endl; 
        } 
        else{ 
            cout<<"Invalid Choice!"<<endl; 
        } 
    }while(menuChoice!=5); 
 
    return 0; 
} 
