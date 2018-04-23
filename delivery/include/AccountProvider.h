#ifndef _ACCOUNT_PROVIDER_H_
#define _ACCOUNT_PROVIDER_H_

#include "Account.h"
#include "enumErrorOutputs.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

static string ACCOUNTSFOLDER = "";
static string ACCOUNT_FILE_TAG = "account_";

static string accountFile = "";

//Static class with helper methods to read/write accounts to the file system

class AccountProvider
{
public:
    // Helper to store an account
    static int storeAccount(Account account);

    // Helper to load an account - in the future will need an identifier to load the account by
    static Account loadAccount(string accountId);

private:
    // Disable creating an account provider object,
    // as it only provides helper methods
    AccountProvider() {}

    // Turns the account into a string
    static string serializeAccount(Account account);

    // Turns the string into an account
    static Account deserializeAccount(ifstream &inFile);
};

std::string getEnvironmentVariable(std::string const &);
#endif
