#include <iostream>

#include "Market.h"

void Market::addAsset(Asset* asset) {
    cout << "Added asset: " << asset->getSymbol() << endl;
    marketAssets.push_back(asset);
}

void Market::addUser(User* user) {
    cout << "Added user: " << user->getName() << " (" << user->getUserType() << ")" << endl;
    marketUsers.push_back(user);
}

Asset* Market::findAsset(std::string_view symbol) {
    for (auto* asset : marketAssets) {
        if (asset->getSymbol() == symbol)
            return asset;
    }
    cout << "Asset " << symbol << " not found" << endl;
    return nullptr;
}

User* Market::findUser(std::string_view name) {
    for (auto* user : marketUsers) {
        if (user->getName() == name)
            return user;
    }
    cout << "User " << name << " not found" << endl;
    return nullptr;
}

// polymorphic
void Market::listAssets() const {
    cout << "Market assets:" << endl;
    for (const auto* asset : marketAssets) {
        asset->printInfo();
    }
}

// destructor
Market::~Market() {
    for (auto* asset : marketAssets) {
        delete asset;
    }
    for (auto* user : marketUsers) {
        delete user;
    }
}