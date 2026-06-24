#include <iostream>

#include "Asset.h"
#include "Market.h"
#include "User.h"


int main() {
    std::cout << "=== OOP Market Simulator - Runtime Polymorphism ===" << '\n';
    Market market;

    // Add assets using runtime polymorphism (inheritance + virtual functions)
    market.addAsset(new Stock("AAPL", 150.0, "Technology"));
    market.addAsset(new Stock("GOOG", 2800.0, "Technology"));
    market.addAsset(new Future("TXO23000A6", 23000, "2026/01/21"));

    market.listAssets();

    std::cout << "--------------------" << '\n';

    // Add users with different fee models using runtime polymorphism
    market.addUser(new VipUser("Alice", 10000.0));
    market.addUser(new NormalUser("Bob", 5000.0));

    std::cout << "--------------------" << '\n';

    // Locate users and assets
    User* alice = market.findUser("Alice");
    User* bob = market.findUser("Bob");
    Asset* apple = market.findAsset("AAPL");
    Asset* google = market.findAsset("GOOG");

    if (alice && apple) {
        alice->buyAsset(*apple, 10);
    }

    if (bob && google) {
        bob->buyAsset(*google, 2);
    }

    if (alice && apple) {
        alice->sellAsset(*apple, 5);
    }

    if (alice) {
        std::cout << "User Type: " << alice->getUserType() << '\n';
        alice->printTransactions();
    }

    if (bob) {
        std::cout << "User Type: " << bob->getUserType() << '\n';
        bob->printTransactions();
    }

    return 0;
}