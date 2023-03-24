#include <stdlib.h> 
#include <iostream> 

#include "mysql_connection.h" 
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/prepared_statement.h> 
using namespace std;

// for demonstration only. never save your password in the code! 
const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ� 
//tcp����� �̿��ؼ� ���(127.0.0.1�� �ڱ� ��ǻ�� �ּҸ� �ǹ�,�����ͺ��̽��� 3306����� )
const string username = "user"; // �����ͺ��̽� ����� 
const string password = "1234"; // �����ͺ��̽� ���� ��й�ȣ 

// mysql -u user -p , pasword =1234


//main���� CREATE���̺� ����, ���� 
//INSERT ������ �߰� 
//CRUD �ڵ� 
int main()
{
    // MySQL Connector/C++ �ʱ�ȭ 
    sql::Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ �� 
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    // please create database "cpp_db" ahead of time 
    con->setSchema("cpp_db");

    // �����ͺ��̽� ���� ���� 
    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory");
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE inventory (department_id serial PRIMARY KEY, department_name VARCHAR(50),manager_id INTEGER, location VARCHAR(50));");
    cout << "Finished creating table" << endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO inventory(department_id, department_name,manager_id,location) VALUES(?,?,?,?)");
    pstmt->setInt(1, 1);
    pstmt->setString(2,"Engineering");
    pstmt->setInt(3, 1);
    pstmt->setString(4, "New York");
  
    pstmt->execute();
    cout << "One row inserted." << endl;


    pstmt->setInt(1, 2);
    pstmt->setString(2, "Sales");
    pstmt->setInt(3, 5);
    pstmt->setString(4, "Los Angeles");
    pstmt->execute();
    cout << "One row inserted." << endl;



    pstmt->setInt(1, 3);
    pstmt->setString(2, "Marketing");
    pstmt->setInt(3, 7);
    pstmt->setString(4, "Chicago");
    pstmt->execute();
    cout << "One row inserted." << endl;


    pstmt->setInt(1, 4);
    pstmt->setString(2, "Accounting");
    pstmt->setInt(3, 8);
    pstmt->setString(4, "Houston");
    pstmt->execute();
    cout << "One row inserted." << endl;


    pstmt->setInt(1, 5);
    pstmt->setString(2, "IT");
    pstmt->setInt(3, 10);
    pstmt->setString(4, "San Francisco");
    pstmt->execute();
    cout << "One row inserted." << endl;

    // MySQL Connector/C++ ���� 
    delete pstmt;
    delete con;
    system("pause");

    return 0;
}