//db.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <new>

using namespace std;

class Database{
private:
	string db;
	string username;
	string password;
	bool connected = false;
	static Database* instance;

public:
	//constructor that helps creating instance of db(e.g. sales.db) accepts name of the database, username, password. 
	Database(string DB, string UN, string PW);

	//destructor that disconnects the connection if connected.
	~Database();

	//"getInstance" that creates and returns the instance of the database. 
	// If called first time it sets the username and password. 
	// However, subsequent time, it matches the database name, 
	// username and password and returns the previous instance 
	// if matched else it throws std::runtime_error("invalid database name, username or password"). 
	// We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
	//ToDo
	static Database* getInstance(string DB, string UN, string PW)
	{
		if (instance == nullptr)
		{
			instance = new Database(DB, UN, PW);
		}
		else if (instance->db == DB || instance->username == UN || instance->password == PW)
		{
			throw std::runtime_error("invalid database name, username or password");
		}

		return instance;
	}

	//"connect" that sets "connected" to true (return void)
	void connect();

	//"connect" that sets "connected" to true (return void)
	void disconnect();

	// retrun status of connected true/false (return bool)
	bool connectionStatus();

	//overload the new operator that allocates memory using malloc 
	// of given size and returns pointer of type void and prints " overloaded new " 
	// (cout is okay in this case). std::cout << "overloaded new ";
	//If the memory allocation fails it should throw std::bad_alloc()
	void* operator new(size_t size);

	//overload the delete operator that deallocates memory and prints 
	// "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
	void operator delete(void* ptr);

	//set_username and get_username for username
	string getUsername() const;
	void setUsername(string newUN);

	//set_password and get_password for password.
	string getPassword() const;
	void setPassword(string newPW);

	//The static "resetInstance" as defined below.
	static void resetInstance();
};