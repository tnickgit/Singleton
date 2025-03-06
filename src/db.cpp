//db.cpp

#include "db.h"

Database* Database::instance = nullptr;



void Database::connect()
{
    isConnected = true;
}

void Database::disconnect()
{
    isConnected = false;
}

bool Database::connectionStatus()
{
    return isConnected;
}

void* Database::operator new(size_t size)
{
    std::cout << "overloaded new ";
    void* ptr = malloc(size);
    if (!ptr) { throw std::bad_alloc(); }
    return ptr;
}

void Database::operator delete(void* ptr)
{
    std::cout << "overloaded delete ";
    free(ptr);
}

string Database::get_username() const
{
    return username;
}

void Database::set_username(string newUN)
{
    this->username = newUN;
}

string Database::get_password() const
{
    return password;
}

void Database::set_password(string newUN)
{
    this->password = newUN;
}

void Database::resetInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}