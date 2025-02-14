class ProductOfNumbers {
    vector<pair<int, int>> products;
    vector<int> zeros;
    int idx;
    bool zero;
public:
    ProductOfNumbers() :idx(0), zero(true) {
        zeros.push_back(-1);
    }

    void add(int num) {
        if (num == 0)
        {
            zero = true;
            zeros.push_back(idx++);
            return;
        }
        int mult = 1;
        if (zero == true)
            zero = false;
        else
            mult = products.back().first;
        products.push_back({ num * mult, idx++ });
    }

    int getProduct(int k) {
        int size = products.size();
        if (k > size || products[size - k].second <= zeros.back())
            return 0;
        if (zeros.back() == idx - k - 1)
            return products.back().first;
        return products.back().first / products[size - k - 1].first;
    }
};
