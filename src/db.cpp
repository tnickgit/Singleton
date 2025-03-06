//db.cpp

#include "db.h"

Database* Database::instance = nullptr;



void Database::connect()
{
    connected = true;
}

void Database::disconnect()
{
    connected = false;
}

bool Database::connectionStatus()
{
    return connected;
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

string Database::getUsername() const
{
    return username;
}

void Database::setUsername(string newUN)
{
    this->username = newUN;
}

string Database::getPassword() const
{
    return password;
}

void Database::setPassword(string newUN)
{
    this->password = newUN;
}

void Database::resetInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}