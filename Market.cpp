#include <iostream>

#include "Market.h"

void Market::addAsset(Asset* asset) {
    std::cout << "Added asset: " << asset->getSymbol() << '\n';
    marketAssets.push_back(asset);
}

void Market::addUser(User* user) {
    std::cout << "Added user: " << user->getName() << " (" << user->getUserType() << ")" << '\n';
    marketUsers.push_back(user);
}

Asset* Market::findAsset(std::string_view symbol) {
    for (auto* asset : marketAssets) {
        if (asset->getSymbol() == symbol)
            return asset;
    }
    std::cout << "Asset " << symbol << " not found" << '\n';
    return nullptr;
}

User* Market::findUser(std::string_view name) {
    for (auto* user : marketUsers) {
        if (user->getName() == name)
            return user;
    }
    std::cout << "User " << name << " not found" << '\n';
    return nullptr;
}

// polymorphic
void Market::listAssets() const {
    std::cout << "Market assets:" << '\n';
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