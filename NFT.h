#ifndef NFT_H
#define NFT_H

#include <string>
using namespace std;

class NFT {
protected:
    string name;
    int price;
    string rarity;
    string category;

public:
    NFT(string n, int p, string r, string c);
    virtual void displayInfo();
    virtual ~NFT() {}

    string getName();
    int getPrice();
    string getRarity();
    string getCategory();
};

#endif
