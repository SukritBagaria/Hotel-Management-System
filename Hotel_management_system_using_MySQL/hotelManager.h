#ifndef HOTELMANAGER_H_INCLUDED
#define HOTELMANAGER_H_INCLUDED

#include "Room.h"

using namespace std;

class hotelManager: protected Room{
    public:
    void checkIn();
    void checkOut(int);
    void getAvailableRooms();
    void searchCustomer();
    void mainMenu();
    void manageRooms();
};

#endif // HOTELMANAGER_H_INCLUDED
