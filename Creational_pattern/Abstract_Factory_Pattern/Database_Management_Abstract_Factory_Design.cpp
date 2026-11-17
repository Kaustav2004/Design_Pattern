// Problem Statement:
// You are designing a database management system for an enterprise application.

// The application should support multiple databases:
// MySQL
// PostgreSQL
// MongoDB

// Each database should provide two related components:
// Database Connection: Responsible for establishing a connection with the database.
// Database Command: Responsible for executing database queries or commands.
// Each database has its own implementation of these components.

// Functional Requirements:
// The system should support MySQL, PostgreSQL and MongoDB.
// Each database should have its own Connection implementation.
// Each database should have its own Command implementation.
// The system should ensure that Connection and Command belong to the same database family.
// The client should interact with abstract interfaces rather than concrete classes.
// Object creation logic should be separated from client code.
// Adding a new database in the future should require minimal changes to existing code.

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Connection {
public:
    virtual void connect(const string& port) = 0;
    virtual ~Connection() = default;
};

class MySQLConnection : public Connection {
public:
    void connect(const string& port) override {
        cout << "Connecting to MySQL database on port: " << port << endl;
    }
};

class PostgreSQLConnection : public Connection {
public:
    void connect(const string& port) override {
        cout << "Connecting to PostgreSQL database on port: " << port << endl;
    }
};

class MongoDBConnection : public Connection {
public:
    void connect(const string& port) override {
        cout << "Connecting to MongoDB database on port: " << port << endl;
    }
};

class Command {
public:
    virtual void execute(const string& query) = 0;
    virtual ~Command() = default;
};

class MySQLCommand : public Command {
public:
    void execute(const string& query) override {
        cout << "Executing MySQL query: " << query << endl;
    }
};

class PostgreSQLCommand : public Command {
public:
    void execute(const string& query) override {
        cout << "Executing PostgreSQL query: " << query << endl;
    }
};

class MongoDBCommand : public Command {
public:
    void execute(const string& query) override {
        cout << "Executing MongoDB query: " << query << endl;
    }
};

class DatabaseFactory {
public:
    virtual unique_ptr<Connection> createConnection() = 0;
    virtual unique_ptr<Command> createCommand() = 0;
    
    virtual ~DatabaseFactory() = default;
};

class MySQLFactory : public DatabaseFactory {
public:
    unique_ptr<Connection> createConnection() override {
        return make_unique<MySQLConnection>();
    }
    
    unique_ptr<Command> createCommand() override {
        return make_unique<MySQLCommand>();
    }
};

class PostgreSQLFactory : public DatabaseFactory {
public:
    unique_ptr<Connection> createConnection() override {
        return make_unique<PostgreSQLConnection>();
    }
    
    unique_ptr<Command> createCommand() override {
        return make_unique<PostgreSQLCommand>();
    }
};

class MongoDBFactory : public DatabaseFactory {
public:
    unique_ptr<Connection> createConnection() override {
        return make_unique<MongoDBConnection>();
    }
    
    unique_ptr<Command> createCommand() override {
        return make_unique<MongoDBCommand>();
    }
};

void createConnection(DatabaseFactory& factory, const string& port) {
    auto obj = factory.createConnection();
    obj->connect(port);
}

void executeCommand(DatabaseFactory& factory, const string& query) {
    auto obj = factory.createCommand();
    obj->execute(query);
}

int main(){
    MySQLFactory mysqlFactory;
    PostgreSQLFactory postgreFactory;
    MongoDBFactory mongoFactory;
    
    createConnection(mysqlFactory, "3306");
    createConnection(postgreFactory, "5432");
    createConnection(mongoFactory, "27017");
    
    executeCommand(mysqlFactory, "SELECT * FROM users;");
    executeCommand(postgreFactory, "SELECT * FROM employees;");
    executeCommand(mongoFactory, "{ find: 'customers' }");
}