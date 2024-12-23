#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <map>

enum OrderStatus {
    kFailed = -1,
    kCancelled,
    kReviewing,
    kSuccessful
};

class Order {
  public:
    Order();

    void update();

    std::vector<std::map<std::string, std::string>> order_map_;
};

#endif  //ORDER_H