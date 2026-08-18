#include<iostream> 
#include<string> 
using namespace std; 
 
string usernames[5]; 
string passwords[5]; 
int userCount=0; 
 
string titles[20]; 
string contents[20]; 
int entryCount=0; 
 
bool login(); 
void registerUser(); 
void mainMenu(); 
void createEntry(); 
void viewAllEntries(); 
void readEntry(); 
void editEntry(); 
void deleteEntry(); 
void deleteAllEntries(); 
 
int main(){ 
int choice; 
cout<<"===== student diary =====\n"; 
cout << "1. Login\n"; 
cout<<"2. Register\n"; 
cout<<"Enter choice: "; 
cin>>choice; 
if(choice==1){ 
if(login()){ 
mainMenu(); 
}else{ 
cout<<"login failed!\n"; 
} 
}else if(choice==2){ 
registerUser(); 
cout<<"Now Login to continue...\n"; 
if(login()){ 
mainMenu(); 
} 
}else{ 
cout << "invalid choice!\n"; 
} 
return 0; 
} 
 
bool login(){ 
string u,p; 
cout<<"\nusername: "; 
cin>>u; 
cout<<"Password: "; 
cin>>p; 
for(int i=0;i<userCount;i++){ 
if(usernames[i]==u && passwords[i]==p){ 
cout<<"Login Successful!\n"; 
return true; 
} 
} 
return false; 
} 
 
void registerUser(){ 
if(userCount>=5){ 
cout<<"User limit reached!\n"; 
return; 
} 
cout<<"\nchoose a Username: "; 
cin>>usernames[userCount]; 
cout<<"choose a password: "; 
cin>>passwords[userCount]; 
userCount++; 
cout<<"registration Successful!\n"; 
} 
 
void mainMenu(){ 
int choice; 
do{ 
cout<<"\n===== MAIN menu =====\n"; 
cout<<"1. Create new diary entry\n"; 
cout<<"2. view all Entries\n"; 
cout<<"3. Read full entry\n"; 
cout<<"4. Edit an entry\n"; 
cout<<"5. delete one entry\n"; 
cout<<"6. Delete All entries\n"; 
cout<<"7. Exit\n"; 
cout<<"Enter choice: "; 
cin>>choice; 
switch(choice){ 
case 1: createEntry(); break; 
case 2: viewAllEntries(); break; 
case 3: readEntry(); break; 
case 4: editEntry(); break; 
case 5: deleteEntry(); break; 
case 6: deleteAllEntries(); break; 
case 7: cout<<"GoodBye!\n"; break; 
default: cout<<"invalid Choice!\n"; 
} 
}while(choice!=7); 
} 
 
void createEntry(){ 
if(entryCount>=20){ 
cout<<"Diary full! cannot add more entries.\n"; 
return; 
} 
cin.ignore(); 
cout<<"\nEnter Title: "; 
getline(cin,titles[entryCount]); 
if(titles[entryCount].empty()){ 
cout<<"title cannot be Empty!\n"; 
return; 
} 
cout<<"Enter content: "; 
getline(cin,contents[entryCount]); 
entryCount++; 
cout<<"entry Added successfully!\n"; 
} 
 
void viewAllEntries(){ 
if(entryCount==0){ 
cout<<"no entries found.\n"; 
return; 
} 
cout<<"\n===== all Entries =====\n"; 
for(int i=0;i<entryCount;i++){ 
cout<<i+1<<". "<<titles[i]<<endl; 
} 
} 
 
void readEntry(){ 
int n; 
cout<<"Enter entry number: "; 
cin>>n; 
if(n<1 || n>entryCount){ 
cout<<"invalid entry number!\n"; 
return; 
} 
cout<<"\nTitle: "<<titles[n-1]<<endl; 
cout<<"content: "<<contents[n-1]<<endl; 
} 
 
void editEntry(){ 
int n; 
cout<<"Enter entry number to edit: "; 
cin>>n; 
if(n<1 || n>entryCount){ 
cout<<"Invalid entry number!\n"; 
return; 
} 
cin.ignore(); 
cout<<"new Title: "; 
getline(cin,titles[n-1]); 
cout<<"new content: "; 
getline(cin,contents[n-1]); 
cout<<"Entry updated!\n"; 
} 
 
void deleteEntry(){ 
int n; 
cout<<"Enter entry number to delete: "; 
cin>>n; 
if(n<1 || n>entryCount){ 
cout<<"invalid entry number!\n"; 
return; 
} 
for(int i=n-1;i<entryCount-1;i++){ 
titles[i]=titles[i+1]; 
contents[i]=contents[i+1]; 
} 
entryCount--; 
cout<<"entry deleted!\n"; 
} 
 
void deleteAllEntries(){ 
entryCount=0; 
cout<<"All Entries Deleted!\n"; 
} 
