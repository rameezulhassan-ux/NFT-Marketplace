#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "NFT.h"
using namespace std;

class User {
private:
    string username;
    string password;
    int walletBalance;
    vector<NFT*> ownedNFTs;

public:
    User(string name, string pass);
    ~User();

    bool login(string name, string pass);

    string getUsername();
    string getPassword();
    int getBalance();
    void setBalance(int b);

    void deductBalance(int amount);
    void addNFT(NFT* nft);
    void deposit(int amount);  // NEW: deposit money

    void showOwnedNFTs();
    void showWalletBalance();

    void saveNFTs();
    void loadNFTs();
};

#endif
