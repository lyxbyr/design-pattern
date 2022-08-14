class EmployeeDAO {
 public:
  vector<EmployeeDAO> GetEmpolyees() {
    SqlConnection* connection = new SqlConnection();
    connection->ConnectionString = "...";

    SqlCommand* command = new SqlCommand();
    command->CommandText = "...";
    command->SetConnection(connection);

    SelfDataReader* reader = command->ExecuteReader();
    while (reader->Read()) {
    }
  }
};