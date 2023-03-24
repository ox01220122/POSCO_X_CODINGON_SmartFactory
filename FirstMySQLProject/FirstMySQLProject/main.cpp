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
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
    cout << "Finished creating table" << endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "apple");
    pstmt->setInt(2, 100);
    pstmt->execute();
    cout << "One row inserted." << endl;

    // MySQL Connector/C++ ���� 
    delete pstmt;
    delete con;
    system("pause");






    return 0;
}