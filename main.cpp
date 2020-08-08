//
//  P2.cpp
//  Hotel Management System
//
//  Created by Sukrit Bagaria on 08/08/20.
//  Copyright © 2020 Sukrit Bagaria. All rights reserved.
//


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Customer{
    public:
    char firstname[20];
    char lastname[20];
    char address[100];
    char phone[10];
    float advance_payment;
};


class Room{
    public:
    int rno;
    char roomtype;
    char comfort;
    char capacity;
    int status;
    int rent_per_day;
    
    Customer cust;
    Room addRoom(int);
    void searchRoom(int);
    void modifyRoom();
    void displayRoom(Room);
    void displayNewRoom(Room);
};

class Hm: protected Room{
    public:
    void checkIn();
    void checkOut(int);
    void guestSummaryReport();
    void getAvailableRooms();
    void searchCustomer(char *, char *);
};

vector <Room> rooms;
void mainMenu();
void manageRooms();
 
Room Room::addRoom(int roomnumber){
    Room room;
    room.rno=roomnumber;
    cout << "\n***************************";
    cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidntial Suite->P)\n";
    cout << "***************************";
    cout << "\nEnter the code for room type:";
    cin >> room.roomtype;
    // while(room.roomtype != 'd' || 'D' || 'n' || 'N' || 'P' || 'p'){
    //     cout << "Invalide Code!" << endl << "Enter the code again:";
    //     cin >> room.roomtype;
    // }
    cout << "\n***************************";
    cout << "\n(AC->A)\n(Non-AC->N)";
    cout << "\n***************************";
    cout << "\nEnter the code for room comfort:";
    cin >> room.comfort;
    // while(room.comfort != 'a' || 'A' || 'n' || 'N'){
    //     cout << "\nInvalide Code!" << endl << "Enter the code again:";
    //     cin >> room.comfort;
    // }
    cout << "\n***************************";
    cout << "\n(Single->S)\n(Double->D)";
    cout << "\n***************************";
    cout << "\nEnter the code for room capacity:";
    cin >> room.capacity;
    // while(room.capacity != 's' || 'S' || 'd' || 'D'){
    //     cout << "\nInvalide Code!" << endl << "Enter the code again:";
    //     cin >> room.capacity;
    // }
    // cout << "\n(Vacant->V)\n(Occupied->O)\n";
    // cout << "\nEnter the code for room status";
    // cin >> room.roomstatus;
    // while(room.roomtype != 'V' || 'v' || 'O' || 'o'){
    //     cout << "\nInvalide Code!" << endl << "Enter the code again:";
    //     cin >> room.roomstatus;
    // }
    room.status=0;
    cout << "\nEnter the rent per day:";
    cin >> room.rent_per_day;
    cout << "\n Room added successfully!";
    displayRoom(room);
    return room;
}
 
 
void Room::displayRoom(Room tempRoom){
    cout << "\n***************************";
     cout<<"\nRoom Number:"<<tempRoom.rno;
     cout<<"\nRoom Type: DeluxeSuite/Non-deluxeSuite/PresidentialSuite (D/N/P): "<<tempRoom.roomtype;
     cout<<"\nRoom Comfort AC/Non-AC (A/N): "<<tempRoom.comfort;
     cout<<"\nRoom Size Single/Double(S/D): "<<tempRoom.capacity;
     cout<<"\nRent per day: "<<tempRoom.rent_per_day;
     cout << "\n***************************";
}
 
void Room::modifyRoom(){
    int opt;
    do{
        cout << "\n***************************";
        cout << "\nWhat would you want to modify?";
        cout << "\nRoom Type - Press 1\nRoom Comfort - Press 2\nRoom capacity - Press 3\nRent per day - Press 4\nFinish Press 5\n";
        cout << "***************************";
        cin >> opt;
        switch(opt){
           case 1:
           char new_type;
           cout << "\n***************************";
           cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidntial Suite->P)\n";
           cout << "***************************";
           cout << "\nEnter the code for new room type:";
           cin >> new_type;
           roomtype = new_type;
           break;
           case 2:
           char new_comfort;
           cout << "\n***************************";
           cout << "\n(AC->A)\n(Non-AC->N)";
           cout << "***************************";
           cout << "\nEnter the code for new room comfort:";
           cin >> new_comfort;
           comfort = new_comfort;
           break;
           case 3:
           char new_capacity;
           cout << "n***************************";
           cout << "\n(Single->S)\n(Double->D)";
           cout << "***************************";
           cout << "\nEnter the code for new  room capacity:";
           cin >> new_capacity;
           capacity = new_capacity;
           break;
           case 4:
           int new_rent;
           cout << "\nEnter new rent per day: ";
           cin >> new_rent;
           rent_per_day = new_rent;
           break;
           case 5:
           cout << "Room details modified!\n";
           cout << "***************************";
           cout << "\nNew Room details are:";
           break;
           default:
           cout << "\n***************************";
           cout << "\nInvalid Input";
           cout << "***************************";
           cout << "\nEnter correct option:";
        
        }
    }while(opt!=5);
}
 
void Room::displayNewRoom(Room tempRoom){
     cout<<"\nRoom Number:"<<tempRoom.rno;
     cout<<"\nRoom Type: DeluxeSuite/Non-deluxeSuite/PresidentialSuite (D/N/P): "<<tempRoom.roomtype;
     cout<<"\nRoom Comfort AC/Non-AC (A/N): "<<tempRoom.comfort;
     cout<<"\nRoom Size Single/Double(S/D): "<<tempRoom.capacity;
     cout<<"\nRent per day: "<<tempRoom.rent_per_day;
     cout << "\n***************************";
     cout << "\nPress any key to go back to main menu:";
     cin.ignore();
     cin.get();
     manageRooms();
}
 
void Room::searchRoom(int roomnumber){
     int i, found=0;
     for(i=0;i < rooms.size();i++){
         if(rooms[i].rno==roomnumber){
             found=1;
             break;
         }
     }
     if(found==1){
         rooms[i].displayRoom(rooms[i]);
         rooms[i].modifyRoom();
         displayNewRoom(rooms[i]);
     }
     else{
         cout << "\n***************************";
         cout << "\nRoom not found";
         cout << "***************************";
         cout << "\nPress any key to continue.\n";
         cin.ignore();
         cin.get();
         manageRooms();
     }
}
 
int count = 0;
void manageRooms(){
    Room room;
    int menu,roomnumber,found = 0;
    
        do{
        // system("cls");
        cout << "\n***************************";
        cout<<"\n### Manage Rooms ###";
        cout<<"\n1.Add Room\n2.Modify Room\n3.Back to main menu: ";
        cout << "\n***************************";
        cout << "\n\nEnter Option: ";
        cin >> menu;
        if(menu == 1){
                cout << "\nEnter Room Number:";
            cin >> roomnumber;
            for(int i=0;i < rooms.size();i++){
                if(rooms[i].rno == roomnumber){
                    found = 1;
                }
            }
            
            if(found==1){
                cout << "***************************";
                cout << "\nRoom is already present.\n";
                cout << "***************************";
                cout << "\nPress any key to continue.";
                found=0;
                cin.ignore();
                cin.get();
            }
            else{
                rooms.push_back(room.addRoom(roomnumber));
                
                cout << "\nPress any key to go back to Main Menu: ";
                cin.ignore();
                cin.get();
                manageRooms();
            }
            }
        }while(menu == 1);
        if(menu==2){
            cout << "\nEnter Room Number:";
            cin >> roomnumber;
            room.searchRoom(roomnumber);
        }
        if(menu==3){
            mainMenu();
        }
        else if(menu!=2 || menu!=3 || menu!=1 ){
            cout << "***************************";
            cout << "\nInvalid input!";
            cout << "***************************";
            cout << "\nEnter the correct option:";
        }
}

void Hm::checkIn(){
  int roomnumber,found=0,again,i;
  cout << "Enter Room Number: ";
  cin >> roomnumber;
  for(i=0;i<rooms.size();i++){
      if(rooms[i].rno==roomnumber){
          found=1;
          break;
      }
  }
  if(found==1){
      if(rooms[i].status==1){
          cout << "\nRoom is already booked.";
          cout << "\nPress any key to continue:";
          cin.ignore();
          cin.get();
          cout << "\nPress 1 to go back to main menu\nPress 2 to enter another room no.";
          cin >> again;
          if(again==1){
              mainMenu();
          }
          if(again==2){
              checkIn();
          }
          if(again!=1 || again!=2){
              cout << "\nInvalid input!";
              cout << "\nPress any key to continue:";
              cin.ignore();
              cin.get();
              mainMenu();
          }
      }else{
  cout<<"\nEnter Customer Name (First Name): ";
  cin>>rooms[i].cust.firstname;
  cout<<"\nEnter Customer Name (Last Name): ";
  cin>>rooms[i].cust.lastname;
  cout<<"\nEnter Address (only city): ";
  cin>>rooms[i].cust.address;
  cout<<"\nEnter Phone Number: ";
  cin >> rooms[i].cust.phone;
  cout<<"\nEnter Advance Payment: ";
  cin>>rooms[i].cust.advance_payment;
  
  rooms[i].status=1;
  cout << "\nCustomer checked-in successfully.";
  cout << "\nPress any key to continue:";
  cin.ignore();
  cin.get();
  mainMenu();
  }
  } else {
      cout << "Room not found.\nPress any key to continue\n";
      cin.ignore();
      cin.get();
      mainMenu();
  }

}

void Hm::checkOut(int roomnumber){
    int i,found=0,days;
    float bill=0;
    for(i=0;i<rooms.size();i++){
        if(rooms[i].status==1 && rooms[i].rno==roomnumber){
            found=1;
            break;
        }
    }
    if(found==1){
        cout << "\nEnter no. of days:";
        cin >> days;
        bill=days*rooms[i].rent_per_day;
        cout<<"\nCheckOut Details are:";
        cout<<"\nCustomer Name : "<<rooms[i].cust.firstname << " " << rooms[i].cust.lastname;
        cout<<"\nRoom Number : "<<rooms[i].rno;
        cout<<"\nAddress : "<<rooms[i].cust.address;
        cout<<"\nPhone : "<<rooms[i].cust.phone;
        cout<<"\nTotal Amount Due : "<<bill<<" /-";
        cout<<"\nAdvance Paid: "<<rooms[i].cust.advance_payment<<" /-";
        cout<<"\n*** Total Payable: "<<bill-rooms[i].cust.advance_payment<<"/ only";

        rooms[i].status=0;
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        mainMenu();
    } else{
        cout << "No guest is present in room number " << roomnumber << "\n" << "Press any key to continue\n";
        cin.ignore();
        cin.get();
        mainMenu();
    }
}

void Hm::guestSummaryReport(){
    if(rooms.size()==0){
        cout<<"\n No Guest in Hotel !!";
    }
    for(int i=0;i<rooms.size();i++){
        if(rooms[i].status==1){
            cout<<"\n Customer Name : "<<rooms[i].cust.firstname << " " << rooms[i].cust.lastname;
            cout<<"\n Room Number : "<<rooms[i].rno;
            cout<<"\n Address (only city) : "<<rooms[i].cust.address;
            cout<<"\n Phone : "<<rooms[i].cust.phone;
        }
    }
    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    mainMenu();
}

void Hm::getAvailableRooms(){
    int i,found=0;
    for(i=0;i<rooms.size();i++){
       if(rooms[i].status==0){
           displayRoom(rooms[i]);
           cout<<"\n\nPress enter";
           found=1;
           cin.ignore();
           cin.get();
        }
    }
    if(found==0){
        cout<<"\nAll rooms are reserved";
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
    }
}

void Hm::searchCustomer(char *fname,char *lname){
    int i,found=0;
    for(i=0;i<rooms.size();i++){
        if(rooms[i].status==1 && strcmp(rooms[i].cust.firstname,fname)==0 && strcmp(rooms[i].cust.lastname,lname)==0){
           cout<<"\nCustomer Name: "<<rooms[i].cust.firstname << " " << rooms[i].cust.lastname;
           cout<<"\nRoom Number: "<<rooms[i].rno;
           cout<<"\nAddress : "<<rooms[i].cust.address;
           cout<<"\nPhone : "<<rooms[i].cust.phone;
           cout << "\nPress 1 for room record.";
            int k;
            cin >> k;
           rooms[i].displayRoom(rooms[i]);
           cout<<"\n\nPress enter to return to main menu";
           found=1;
           cin.ignore();
           cin.get();
        }
    }
    if(found==0){
        cout<<"\nPerson not found.";
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        mainMenu();
    } else{
        mainMenu();
    }
}

void mainMenu(){
    Hm hm;
    cout << "Welcome to Bachelor's Paradise\n" << endl;
    int menu,roomnumber,input;
    char fname[20];
    char lname[20];
    cout << "***************************";
    cout << "\n1.Manage Rooms"<< endl << "2.Check-In Room" << endl << "3.Check-out Room" << endl << "4.Search Customer" << endl << "5.Guest Summary Report" << endl << "6.Available Rooms" << endl << "7.Exit";
    cout << "***************************";
    cout << "\nEnter the corresponding no. to go the menu:";
    cin >> menu;
    switch(menu){
        case 1:
           manageRooms();
           break;
         case 2:
            if(rooms.size()==0){
                cout << "\nNo Room is available.Please add rooms first";
                cout << "\nPress any key to continue:";
                mainMenu();
            }
            else{
                hm.checkIn();
            }
            break;
         case 3:
             if(rooms.size()==0){
                cout << "\nRoom is not available.Please add the rooms first";
                cout << "\nPress any key to continue:";
                mainMenu();
            }
            else{
                cout << "\nEnter room number:";
                cin >> roomnumber;
                hm.checkOut(roomnumber);
            }
            break;
        case 4:
            if(rooms.size()==0){
                cout<<"\nRooms are not available.\nPlease add the rooms first.";
                cout << "\nPress 1 to add rooms";
                cout << "\nPress 2 to go back to main menu:";
                cin >> input;
                if(input==1){
                    manageRooms();
                }
                if(input==2){
                    mainMenu();
                }
            }
            else{
                cout<<"Enter customer's first name: ";
                cin>>fname;
                cout<<"Enter customer's last name: ";
                cin>>lname;
                hm.searchCustomer(fname,lname);
            }
            break;
        case 5:
            hm.guestSummaryReport();
            break;
        case 6:
            if(rooms.size()==0){
                cout<<"\nRooms data is not available.\nPlease add the rooms first.";
                cout << "\nPress any key to continue:";
                cin.ignore();
                cin.get();
                manageRooms();
            }
            else{
                hm.getAvailableRooms();
            }
            break;
        case 7:
            cout<<"\nTHANK YOU! FOR USING SOFTWARE";
            break;
        default:
            cout << "\nInvalid input.";
            cout << "\nEnter the correct option:";
    }
}
int main(){
    mainMenu();
  return 0;
}
