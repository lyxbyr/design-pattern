#include <vector>
using namespace std;

//支持数据库访问有关的基类
class IDBConnection {};

class IDBConnectionFactory {
 public:
  virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommand {};

class IDBCommandFactory {
 public:
  virtual IDBCommand* CreateDBCommand() = 0;
};

class IDataReader {};

class IDataReaderFactory {
 public:
  virtual IDataReader* createDataReader() = 0;
};

//支持sql server
class SqlConnection : public IDBConnection {};

class SqlConnectionFactory : public IDBConnectionFactory {};

class SqlCommand : public IDBCommand {};

class SqlCommadFactory : public IDBCommandFactory {};

class SqlDataReader : public IDataReader {};

class SqlDataRederFactory : public IDataReaderFactory {};

//支持Oracle server
class OracleConnection : public IDBConnection {};

class OracleCommand : public IDBCommand {};

class OracleDataReader : public IDataReader {};

class EmployeeDAO {
 public:
  vector<EmployeeDAO> GetEmpolyees() {
    IDBConnection* connection = dbConnectionFactory->CreateDBConnection();
    connection->ConnectionString("...");

    IDBCommand* command = dbCommandFactory->CreateDBCommand();
    command->CommandText("...");
    command->SetConnection(connection);//这里是有关联性的

    IDataReader* reader = command->ExecuteReader();//关联性
    while (reader->Read()) {
    }
  }

 private:
  IDBConnectionFactory* dbConnectionFactory;
  IDBCommandFactory* dbCommandFactory;
  IDataReaderFactory* dataReaderFactory;
};