#ifndef ASSET_H
#define ASSET_H

#include <string>

// Traditional runtime polymorphism Asset base class
class Asset {
  protected:
    std::string assetSymbol;
    double assetPrice;

  public:
    Asset(std::string symbol, double price)
        : assetSymbol(std::move(symbol)), assetPrice(price) {}

    // virtual function
    virtual ~Asset() = default;
    virtual const std::string& getSymbol() const;
    virtual double getPrice() const;
    virtual void updatePrice(double newPrice);

    // pure virtual function
    virtual void printInfo() const = 0;
};

// Runtime polymorphism Stock (inheritance + polymorphism)
class Stock : public Asset {
  private:
    std::string industry;

  public:
    Stock(std::string symbol, double price, std::string industryType)
        : Asset(std::move(symbol), price), industry(std::move(industryType)) {}
    void printInfo() const override;
};

// Runtime polymorphism Future (inheritance + polymorphism)
class Future : public Asset {
  private:
    std::string endDate;

  public:
    Future(std::string symbol, double price, std::string expiryDate)
        : Asset(std::move(symbol), price), endDate(std::move(expiryDate)) {}
    void printInfo() const override;
};

#endif
