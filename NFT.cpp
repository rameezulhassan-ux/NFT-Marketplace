#include "NFT.h"
#include <iostream>
using namespace std;

NFT::NFT(string n, int p, string r, string c) {
    name = n;
    price = p;
    rarity = r;
    category = c;
}

void NFT::displayInfo() {
    cout << name << " | Price: " << price
         << " | Rarity: " << rarity
         << " | Category: " << category << endl;
}

string NFT::getName() { return name; }
int NFT::getPrice() { return price; }
string NFT::getRarity() { return rarity; }
string NFT::getCategory() { return category; }
