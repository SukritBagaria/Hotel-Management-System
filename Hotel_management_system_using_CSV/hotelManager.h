#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H

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

#endif // HOTELMANAGER_H
