/*

Dependency Inversion Principle

Entities must depend on abstractions not on concretions.
It states that the high level module must not depend on the low level module,
but they should depend on abstractions.

classes should depend on abstraction but not on concretion

*/
#include <iostream>

class MySQLConnection;

class PasswordValidator
{
private:
	// IDataBaseConnection dbConnection;
	MySQLConnection *dbConnection;

public:
	// what if we change the DB engine
	PasswordValidator(MySQLConnection *_db)
	{
		this->dbConnection = _db;
	}

	/* The right way
	PasswordValidator(IDataBaseConnection* _db) {
		this->dbConnection = _db;
	}
	*/
};

/*
class IDataBaseConnection {
public:
	virtual void connect() = 0;
};

class MySQLConnection : public IDataBaseConnection {
public:
	void connect() {
		std::cout << "Database connection!\n";
	}
};
*/