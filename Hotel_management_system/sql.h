//
//  sql.h
//  Hotel_management_system
//
//  Created by Sukrit Bagaria on 18/07/21.
//

#ifndef sql_h
#define sql_h

#include <mysql.h>

using namespace std;

class sql {
    public:
    MYSQL *conn= mysql_real_connect(mysql_init(0), "localhost", "root", "MySql0810", "hotel_management_system", 3306, NULL, 0);
    MYSQL_ROW row;    //ye aur iske neech wala connectio time pe use krne ki zarurat nhi,
    MYSQL_RES *res;   //ye dono data rtrieve krne time include krna baad me
    
    bool query_check(stringstream &ss, sql sql);
    
};

#endif /* sql_h */
