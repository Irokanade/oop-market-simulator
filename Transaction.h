#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <type_traits>

// Transaction class with template support for compile-time polymorphism
class Transaction {
  private:
    std::string userName;
    std::string stockSymbol;
    std::string transactionType; // "BUY" or "SELL"
    double transactionPrice;
    int quantity;
    time_t timestamp;

  public:
    Transaction(std::string user, std::string symbol, std::string type, double price, int qty);

    // Template method for different price types
    template <typename PriceType>
    Transaction(std::string user, std::string symbol, std::string type, PriceType price, int qty)
        : userName(std::move(user)), stockSymbol(std::move(symbol)), transactionType(std::move(type)),
          transactionPrice(static_cast<double>(price)), quantity(qty), timestamp(time(nullptr)) {
        static_assert(std::is_arithmetic_v<PriceType>, "Price must be a numeric type");
    }

    void printTransaction() const;

    // Getters
    const std::string& getUserName() const {
        return userName;
    }
    const std::string& getStockSymbol() const {
        return stockSymbol;
    }
    const std::string& getTransactionType() const {
        return transactionType;
    }
    double getTransactionPrice() const {
        return transactionPrice;
    }
    int getQuantity() const {
        return quantity;
    }
    time_t getTimestamp() const {
        return timestamp;
    }
};

#endif
