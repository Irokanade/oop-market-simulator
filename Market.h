#ifndef MARKET_H
#define MARKET_H

#include <memory>
#include <string_view>
#include <vector>

#include "Asset.h"
#include "User.h"

// Traditional Market class with runtime polymorphism
class Market {
  private:
    std::vector<std::unique_ptr<Asset>> marketAssets;
    std::vector<std::unique_ptr<User>> marketUsers;

  public:
    void addAsset(std::unique_ptr<Asset> asset);
    void addUser(std::unique_ptr<User> user);

    Asset* findAsset(std::string_view symbol);
    User* findUser(std::string_view name);

    void listAssets() const;
};

#endif
