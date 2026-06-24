#include <iostream>

#include "Asset.h"
#include "Transaction.h"
#include "User.h"


// ---------- User base class ----------
const std::string& User::getName() const {
    return userName;
}

double User::getBalance() const {
    return userBalance;
}

std::string User::getUserType() const {
    return "User";
}

bool User::buyAsset(Asset& asset, int quantity) {
    if (quantity <= 0) {
        std::cout << userName << ": invalid quantity." << '\n';
        return false;
    }

    double price = asset.getPrice();
    double cost = price * quantity;
    double fee = cost * getFeeRate();
    double total = cost + fee;

    if (userBalance < total) {
        std::cout << userName << " does not have enough balance to buy " << quantity
             << " of " << asset.getSymbol() << " (need " << total
             << ", have " << userBalance << ")" << '\n';
        return false;
    }

    userBalance -= total;
    transactions.emplace_back(userName, asset.getSymbol(), "BUY", price, quantity);
    std::cout << userName << " (" << getUserType() << ") bought " << quantity << " of "
         << asset.getSymbol() << " at " << price << " (fee " << fee << ")" << '\n';
    onTrade(transactions.back());
    return true;
}

bool User::sellAsset(Asset& asset, int quantity) {
    if (quantity <= 0) {
        std::cout << userName << ": invalid quantity." << '\n';
        return false;
    }

    double price = asset.getPrice();
    double revenue = price * quantity;
    double fee = revenue * getFeeRate();
    double net = revenue - fee;

    userBalance += net;
    transactions.emplace_back(userName, asset.getSymbol(), "SELL", price, quantity);
    std::cout << userName << " (" << getUserType() << ") sold " << quantity << " of "
         << asset.getSymbol() << " at " << price << " (fee " << fee << ")" << '\n';
    onTrade(transactions.back());
    return true;
}

void User::printTransactions() const {
    std::cout << "Transactions of " << userName << ":" << '\n';
    for (const auto& t : transactions) {
        t.printTransaction();
    }
}

// ---------- VipUser with lower fees ----------
double VipUser::getFeeRate() const {
    return 0.0001;
}

std::string VipUser::getUserType() const {
    return "VIP";
}

std::string VipUser::onTrade(const Transaction&) {
    return "VIP Trading";
}

// ---------- NormalUser with higher fees ----------
double NormalUser::getFeeRate() const {
    return 0.002;
}

std::string NormalUser::getUserType() const {
    return "Normal";
}