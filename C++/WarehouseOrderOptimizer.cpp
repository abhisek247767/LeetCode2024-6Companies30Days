#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Product {
    int weight, value;
};

class Warehouse {
    vector<Product> products;

public:
    Warehouse(const vector<Product>& p) : products(p) {}

    int fulfillOrder(int weightLimit, int numItems) {
        vector<int> dp(weightLimit + 1, 0);
        for (int i = 0; i < numItems; ++i) {
            for (int w = weightLimit; w >= products[i].weight; --w) {
                dp[w] = max(dp[w], dp[w - products[i].weight] + products[i].value);
            }
        }
        return dp[weightLimit];
    }
};

int main() {
    vector<Product> products = {{10, 60}, {20, 100}, {30, 120}, {40, 200}, {50, 250}};

    Warehouse warehouse(products);

    vector<pair<int, int>> orders = {{50, 3}, {70, 4}, {100, 5}};

    for (auto& order : orders) {
        cout << warehouse.fulfillOrder(order.first, order.second) << endl;
    }

    return 0;
}
