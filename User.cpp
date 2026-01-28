#include "User.h"
#include "ArtNFT.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User(string name, string pass) {
    username = name;
    password = pass;
    walletBalance = 1000;
}

User::~User() {
    saveNFTs();
    for (NFT* nft : ownedNFTs)
        delete nft;
}

bool User::login(string name, string pass) {
    return username == name && password == pass;
}

string User::getUsername() { return username; }
string User::getPassword() { return password; }
int User::getBalance() { return walletBalance; }
void User::setBalance(int b) { walletBalance = b; }

void User::deductBalance(int amount) { walletBalance -= amount; }

void User::addNFT(NFT* nft) { ownedNFTs.push_back(nft); }

void User::deposit(int amount) {
    walletBalance += amount;
    cout << amount << " SOL deposited. New balance: " << walletBalance << " SOL\n";
}

void User::showOwnedNFTs() {
    cout << "\nYour NFTs:\n";
    if (ownedNFTs.empty()) { cout << "None\n"; return; }
    for (NFT* nft : ownedNFTs)
        nft->displayInfo();
}

void User::showWalletBalance() {
    cout << "Wallet Balance: " << walletBalance << " SOL\n";
}

void User::saveNFTs() {
    ofstream file("nfts_" + username + ".txt");
    for (NFT* nft : ownedNFTs) {
        file << nft->getName() << "|"
             << nft->getPrice() << "|"
             << nft->getRarity() << "|"
             << nft->getCategory() << endl;
    }
    file.close();
}

void User::loadNFTs() {
    ifstream file("nfts_" + username + ".txt");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        int p1 = line.find('|');
        int p2 = line.find('|', p1 + 1);
        int p3 = line.find('|', p2 + 1);

        string name = line.substr(0, p1);
        int price = stoi(line.substr(p1 + 1, p2 - p1 - 1));
        string rarity = line.substr(p2 + 1, p3 - p2 - 1);
        string category = line.substr(p3 + 1);

        ownedNFTs.push_back(new ArtNFT(name, price, rarity, category));
    }
    file.close();
}
