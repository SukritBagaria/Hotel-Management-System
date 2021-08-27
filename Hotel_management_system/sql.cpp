#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "hotelManager.h"
#include "Room.h"
#include "Customer.h"
#include "sql.h"

using namespace std;

bool sql::query_check(stringstream &ss, sql sql) {
    int qstate = 0;
    string query = ss.str();
    const char *q = query.c_str();
    qstate = mysql_query(sql.conn, q);
    if(qstate == 0) return true;
    else return false;
}


