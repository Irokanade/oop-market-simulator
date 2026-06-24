#include <cassert>
#include <ctime>
#include <iostream>

#include "Transaction.h"

std::string transactionTypeToString(TransactionType type) {
    switch (type) {
        case TransactionType::BUY: return "BUY";
        case TransactionType::SELL: return "SELL";
    }

    assert(false && "invalid TransactionType");
    return "";
}

// constructor
Transaction::Transaction(std::string user, std::string symbol, TransactionType type, double price, int qty)
    : userName(std::move(user)),
      stockSymbol(std::move(symbol)),
      transactionType(type),
      transactionPrice(price),
      quantity(qty),
      timestamp(time(nullptr)) {}

// implement
void Transaction::printTransaction() const {
    std::cout << "User: " << userName
         << ", Action: " << transactionTypeToString(transactionType)
         << ", Asset: " << stockSymbol
         << ", Price: " << transactionPrice
         << ", Quantity: " << quantity
         << ", Time: " << ctime(&timestamp);
}
