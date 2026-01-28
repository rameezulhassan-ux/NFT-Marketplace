#include "ArtNFT.h"
#include <iostream>
using namespace std;

ArtNFT::ArtNFT(string n, int p, string r, string c)
    : NFT(n, p, r, c) {}

void ArtNFT::displayInfo() {
    cout << "[Art NFT] ";
    NFT::displayInfo();
}
