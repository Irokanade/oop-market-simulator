#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Asset.h"
#include "Transaction.h"


// Runtime polymorphism User base class
class User {
  protected:
    std::string userName;
    double userBalance;
    std::vector<Transaction> transactions;

  public:
    User(std::string name, double balance)
        : userName(std::move(name)), userBalance(balance) {}

    const std::string& getName() const;
    double getBalance() const;

    // pure virtual function
    virtual double getFeeRate() const = 0;

    // virtual function
    virtual ~User() = default;
    virtual std::string getUserType() const;
    virtual std::string onTrade(const Transaction&) {
        return "Trading";
    }

    bool buyAsset(Asset& asset, int quantity);
    bool sellAsset(Asset& asset, int quantity);

    void printTransactions() const;
};

// Runtime polymorphism VipUser with lower fees
class VipUser : public User {
  public:
    VipUser(std::string name, double balance)
        : User(std::move(name), balance) {}

    double getFeeRate() const override;
    std::string getUserType() const override;

    std::string onTrade(const Transaction&) override;
};

// Runtime polymorphism NormalUser with higher fees
class NormalUser : public User {
  public:
    NormalUser(std::string name, double balance)
        : User(std::move(name), balance) {}

    double getFeeRate() const override;
    std::string getUserType() const override;
};

#endif