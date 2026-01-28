#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <vector>
#include "NFT.h"
#include "User.h"
using namespace std;

class Marketplace {
public:  
    vector<NFT*> listings;

    void addNFT(NFT* nft);
    void showNFTs();
    void buyNFT(int index, User& user);
};

#endif
