#include "Marketplace.h"
#include <iostream>
using namespace std;

void Marketplace::addNFT(NFT* nft) {
    listings.push_back(nft);
}

void Marketplace::showNFTs() {
    cout << "\nMarketplace NFTs:\n";
    for (int i = 0; i < listings.size(); i++) {
        cout << i << ". ";
        listings[i]->displayInfo();
    }
}

void Marketplace::buyNFT(int index, User& user) {
    if (index < 0 || index >= listings.size()) {
        cout << "Invalid selection!\n";
        return;
    }

    NFT* nft = listings[index];

    if (user.getBalance() < nft->getPrice()) {
        cout << "Insufficient balance!\n";
        return;
    }

    user.deductBalance(nft->getPrice());
    user.addNFT(nft);
    listings.erase(listings.begin() + index);

    cout << "NFT purchased successfully!\n";
}
