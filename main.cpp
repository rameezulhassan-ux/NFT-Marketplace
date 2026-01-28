#include <iostream>
#include <vector>
#include <fstream>
#include "Marketplace.h"
#include "ArtNFT.h"
#include "User.h"
using namespace std;

// File names directly in project folder
const string USERS_FILE = "all_users.txt";

// Save all users
void saveUsers(const vector<User*>& users) {
    ofstream file(USERS_FILE);
    if (!file) { 
        cout << "Error: Could not open file to save users!\n"; 
        return; 
    }

    for (User* u : users) {
        file << u->getUsername() << " "
             << u->getPassword() << " "
             << u->getBalance() << endl;
    }
    file.close();
}

// Load users
void loadUsers(vector<User*>& users) {
    ifstream file(USERS_FILE);
    if (!file) return; // No file yet

    string name, pass;
    int bal;
    while (file >> name >> pass >> bal) {
        User* u = new User(name, pass);
        u->setBalance(bal);
        users.push_back(u);
    }
    file.close();
}

int main() {
    Marketplace market;
    market.addNFT(new ArtNFT("Dragon Art", 300, "Rare", "Fantasy"));
    market.addNFT(new ArtNFT("Cyber Punk", 500, "Epic", "Sci-Fi"));

    vector<User*> users;
    loadUsers(users);

    User* currentUser = nullptr;
    int choice;

    while (true) {
        cout << "\n===== NFT Marketplace ====="
             << "\n1. Register\n2. Login\n3. View Marketplace NFTs\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) { // Register
            string u, p;
            cout << "Username: "; cin >> u;
            cout << "Password: "; cin >> p;
            users.push_back(new User(u, p));
            cout << "Registered successfully! Wallet credited with 1000 SOL.\n";
        }
        else if (choice == 2) { // Login
            string u, p;
            cout << "Username: "; cin >> u;
            cout << "Password: "; cin >> p;

            currentUser = nullptr;
            for (User* user : users) {
                if (user->login(u, p)) {
                    currentUser = user;
                    currentUser->loadNFTs(); // load user's NFTs from project folder
                    break;
                }
            }

            if (!currentUser) {
                cout << "Invalid login!\n";
                continue;
            }

            while (true) {
                cout << "\n1. Create NFT (800 SOL)"
                     << "\n2. View Market"
                     << "\n3. Buy NFT"
                     << "\n4. My NFTs"
                     << "\n5. Wallet Balance"
                     << "\n6. Logout\nChoice: ";
                cin >> choice;

                // Create NFT
                if (choice == 1) {
                    while (currentUser->getBalance() < 800) {
                        cout << "Insufficient balance to create NFT! Deposit? (Y/N): ";
                        char ans; cin >> ans;
                        if (ans == 'Y' || ans == 'y') {
                            int amt;
                            cout << "Enter deposit amount: "; cin >> amt;
                            currentUser->deposit(amt);
                        } else break;
                    }
                    if (currentUser->getBalance() >= 800) {
                        string n, r, c;
                        int p;
                        cin.ignore();
                        cout << "NFT Name: "; getline(cin, n);
                        cout << "Price: "; cin >> p; cin.ignore();
                        cout << "Rarity: "; getline(cin, r);
                        cout << "Category: "; getline(cin, c);

                        NFT* newNFT = new ArtNFT(n, p, r, c);
                        currentUser->deductBalance(800);
                        currentUser->addNFT(newNFT);
                        market.addNFT(newNFT); // Add NFT to marketplace
                        cout << "NFT created and added to Marketplace!\n";
                    }
                }

                // View marketplace
                else if (choice == 2) market.showNFTs();

                // Buy NFT
                else if (choice == 3) {
                    int idx;
                    cout << "Enter NFT index: "; cin >> idx;
                    if (idx < 0 || idx >= (int)market.listings.size()) {
                        cout << "Invalid index!\n";
                        continue;
                    }
                    while (currentUser->getBalance() < market.listings[idx]->getPrice()) {
                        cout << "Insufficient balance! Deposit? (Y/N): ";
                        char ans; cin >> ans;
                        if (ans == 'Y' || ans == 'y') {
                            int amt;
                            cout << "Enter deposit amount: "; cin >> amt;
                            currentUser->deposit(amt);
                        } else break;
                    }
                    if (currentUser->getBalance() >= market.listings[idx]->getPrice())
                        market.buyNFT(idx, *currentUser);
                }

                // My NFTs
                else if (choice == 4) currentUser->showOwnedNFTs();

                // Wallet
                else if (choice == 5) currentUser->showWalletBalance();

                // Logout
                else if (choice == 6) {
                    currentUser = nullptr;
                    break;
                }
            }
        }

        else if (choice == 3) market.showNFTs();
        else break;
    }

    saveUsers(users); // save all users
    for (User* u : users) delete u;

    return 0;
}
