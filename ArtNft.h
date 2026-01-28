#ifndef ARTNFT_H
#define ARTNFT_H

#include "NFT.h"

class ArtNFT : public NFT {
public:
    ArtNFT(string n, int p, string r, string c);
    void displayInfo() override;
};

#endif
