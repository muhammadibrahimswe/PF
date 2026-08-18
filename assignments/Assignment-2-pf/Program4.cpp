#include<iostream> 
#include<string> 
using namespace std; 
    string products[8] = {"T-Shirt","Jeans","Shoes","Watch","Handbag","Headphones","Mobile Cover","Perfume"}; 
    int prices[8] = {1200,3500,5000,2500,4200,3000,700,2800}; 
    int cartprices[10]; 
    string cart[10]; 
     int cartsize=0; 
     
  void addToCart(){ 
   int choice; 
   cout<<"Enter product number(1-8) :"; 
  cin>>choice; 
  if(choice >=1 && choice<=8) { 
  cart [cartsize] = products[choice-1];  
  cartprices [cartsize] =prices[choice-1]; 
    cartsize++; 
    cout<<"Product added to cart "<<endl; 
  } 
  if(cartsize >=10) 
   {cout<<"cart is full "<<endl; 
    return; 
  } 
  } 
 
int customerType(){  
     int c; 
    cout<<"Enter  Customer Type  "<<endl; 
    cout<<"Enter 1 for New and 2 for returning customer : "; 
    cin>>c; 
    if(c==1) 
   cout<<"New Customer"<<endl; 
    else if(c==2) 
     cout<<"Returning  Customer"<<endl; 
      else cout<<"Invalid choice"<<endl; 
   
      return c; 
} 
string userName(){ 
    string n; 
    cout<<"Enter User Name : "; 
    cin>>n; 
    return n; 
} 
string cityName(){ 
    string c; 
    cout<<"Enter City Name : "; 
    cin>>c; 
    return c; 
} 
void displayProducts(){ 
  cout<<"Products"<<" |  "<<"prices"<<endl; 
   for(int i=0;i<8;i++) 
 { 
  cout<<products[i]<<" : "<<prices[i]<<endl; 
 } 
} 
int calculateProductTotal(){ 
  int total=0; 
  for(int i=0;i<cartsize;i++){ 
  cout<<cart[i]<<" : "<<cartprices[i]<<endl; 
  total +=cartprices[i]; 
} 
cout<<"Products Total  :"<<total<<endl; 
return total; 
} 
 
float calculateGst(int total){ 
  return total*(17.0/100); 
 
} 
int deliveryCharges(string city){ 
     if(city=="Lahore" || city=="Karachi" || city=="Islamabad"){ 
     return 250; 
     } 
   else 
      { return 500; 
      } 
} 
float calculateCustomerDiscount(int total,int type){ 
  if(type ==1) 
   return total*5.0/100; 
   else  
    return total*10.0/100; 
 
} 
float orderValueDiscount(int total) { 
if(total >=5000 && total<=10000) 
 return total*5.0/100; 
 else if(total>10000) 
 return total*10.0/100; 
 return 0; 
 
} 
float calculateProcessingFee(float subtotal){ 
  int choice; 
  float fee; 
  cout<<"1. cash on delivery"<<endl; 
  cout<<"2. Credit/Debit card"<<endl; 
  cin>>choice; 
  if(choice==1){ 
  cout<<"Cash on delivery is selected "<<endl; 
  fee =0; 
  return fee; 
} 
  else if(choice==2){ 
  fee = subtotal*2.5/100; 
  return fee; 
  } 
  return 0; 
} 
  
  void checkOutBill(string city,int type){ 
    if(cartsize==0){ 
    cout<<"Cart is empty"<<endl; 
    return; 
} 
    int total=calculateProductTotal(); 
    float gst=  calculateGst(total); 
   cout<<"Gst (17%) :"<<gst<<endl; 
    int charges=deliveryCharges(city); 
    cout<<"delivery charges "<<charges<<endl; 
    float disc=calculateCustomerDiscount(total,type); 
    cout<<"Customer discount :"<<disc<<endl; 
    float orderdiscount = orderValueDiscount(total); 
    cout<<"Order Value Discount : "<<orderdiscount<<endl; 
    float subtotal=total+gst+charges-disc-orderdiscount; 
    cout<<" sub Total  : "<<subtotal<<endl; 
      float fee=calculateProcessingFee(subtotal); 
      cout<<"processing fee :"<<fee<<endl; 
      float finalbill=subtotal+fee; 
      cout<<"final payable amount : "<<finalbill<<endl; 
 
 
  } 
 
int main(){ 
   string user=userName(); 
   string city=cityName(); 
   int type =customerType(); 
    
   int choice; 
  do{ 
    cout<<"Main Menu Option "<<endl; 
    cout<<"1. view products  "<<endl; 
     cout<<"2. Add to cart "<<endl; 
    cout<<"3. checkout bill "<<endl; 
    cout<<"4. Exit   "<<endl; 
    cout<<"Enter your choice : "<<endl; 
    cin>>choice; 
     if(choice==1) 
     displayProducts(); 
     else if(choice==2) 
     addToCart(); 
     else if(choice==3) 
     checkOutBill(city,type); 
     else if(choice==4) 
     cout<<"Exiting... Thankyou"; 
 
  } 
  while(choice!=4); 
 
  return 0; 
} 
