#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <vector>
#include <cmath>

#include "Figure.h"

class Square : public Figure
{
public:
    Square() {}
    Square(const std::vector<std::pair<double, double>>& vertices) : vertices_(vertices) {}

    std::pair<double, double> center() const override
    {
        double sumX = 0, sumY = 0;
        for (const auto& vertex : vertices_) {
            sumX += vertex.first;
            sumY += vertex.second;
        }
        return {sumX / vertices_.size(), sumY / vertices_.size()};
    }

    double area() const override
    {
        double side = std::sqrt(std::pow(vertices_[1].first - vertices_[0].first, 2) +
                                std::pow(vertices_[1].second - vertices_[0].second, 2));
        return side * side;
    }

    void printVertices(std::ostream& os) const override
    {
        for (const auto& vertex : vertices_) {
            os << "(" << vertex.first << ", " << vertex.second << ") ";
        }
    }

    void read(std::istream& is) override
    {
        vertices_.clear();
        double x, y;
        for (int i = 0; i < 4; ++i) {
            is >> x >> y;
            vertices_.emplace_back(x, y);
        }
    }

private:
    std::vector<std::pair<double, double>> vertices_;
};

#endif // SQUARE_H