#ifndef MARKET_H
#define MARKET_H

#include <string_view>
#include <vector>

#include "Asset.h"
#include "User.h"

// Traditional Market class with runtime polymorphism
class Market {
  private:
    std::vector<Asset*> marketAssets;
    std::vector<User*> marketUsers;

  public:
    void addAsset(Asset* asset);
    void addUser(User* user);

    Asset* findAsset(std::string_view symbol);
    User* findUser(std::string_view name);

    void listAssets() const;

    ~Market();
};

#endif