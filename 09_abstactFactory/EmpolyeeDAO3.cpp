#include <vector>
using namespace std;

//支持数据库访问有关的基类
class IDBConnection {};
class IDBCommand {};
class IDataReader {};

class IDBFactory {
 public:
  virtual IDBConnection* CreateDBConnection() = 0;
  virtual IDBCommand* CreateDBCommand() = 0;
  virtual IDataReader* createDataReader() = 0;
};

//支持sql server
class SqlConnection : public IDBConnection {};

class SqlCommand : public IDBCommand {};

class SqlDataReader : public IDataReader {};

class SqlDBFactory : public IDBFactory {
 public:
  virtual IDBConnection* CreateDBConnection() = 0;
  virtual IDBCommand* CreateDBCommand() = 0;
  virtual IDataReader* createDataReader() = 0;
};

//支持Oracle server
class OracleConnection : public IDBConnection {};

class OracleCommand : public IDBCommand {};

class OracleDataReader : public IDataReader {};

class OracleDBFactory : public IDBFactory {
 public:
  virtual IDBConnection* CreateDBConnection() = 0;
  virtual IDBCommand* CreateDBCommand() = 0;
  virtual IDataReader* createDataReader() = 0;
};

class EmployeeDAO {
 public:
  vector<EmployeeDAO> GetEmpolyees() {
    IDBConnection* connection = dbFactory->CreateDBConnection();
    connection->ConnectionString("...");

    IDBCommand* command = dbFactory->CreateDBCommand();
    command->CommandText("...");
    command->SetConnection(connection);  //这里是有关联性的

    IDataReader* reader = command->ExecuteReader();  //关联性
    while (reader->Read()) {
    }
  }

 private:
  IDBFactory* dbFactory;
};