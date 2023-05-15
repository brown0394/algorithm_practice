#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

class coord{
private:
    int _x;
    int _y;

public:
    coord(int p_x, int p_y): _x(p_x), _y(p_y){}
    bool operator < (coord& other);
    friend std::ostream& operator << (std::ostream &out, const coord& crd);
};

bool coord::operator<(coord& other) {
    if (this->_x == other._x) {
        return this->_y < other._y;
    }
    return this->_x < other._x;
}

std::ostream& operator << (std::ostream &out, const coord& crd) {
    return out << crd._x << ' ' << crd._y;
}

int main() {
    int num, xIn, yIn;
    std::vector <coord> arr;

    scanf("%d", &num);

    for (int i = 0; i < num; ++i) {
        scanf("%d %d", &xIn, &yIn);
        arr.push_back(coord(xIn, yIn));
    }
    std::sort(arr.begin(), arr.end());
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<coord>(std::cout, "\n"));
}