//
//  main.cpp
//  Hotel_management_system
//
//  Created by Sukrit Bagaria on 18/07/21.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Room.h"
#include "hotelManager.h"
#include "sql.h"

using namespace std;

int main(){
    sql sql;
    if(sql.conn) {
        hotelManager hm;
        hm.mainMenu();
    }
    else cout << "Not Connected";
    return 0;
}
