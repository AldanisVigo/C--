#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
using namespace std;
using namespace sql;
int main(void){
	sql::Driver *driver;
 	sql::Connection *con;
 	sql::Statement *stmt;
	sql::ResultSet *res;

 	driver = get_driver_instance();
  	con = driver->connect("tcp://127.0.0.1:3306","root","pass");
	
	stmt = con->createStatement();
	stmt->execute("USE test");
	res = stmt->executeQuery("SELECT * FROM tbl1");
	while(res->next()){
		cout << "Your name is :" << res->getString("Name") << " " << res->getString("LastName") << endl;
	}
  return 0;
}
