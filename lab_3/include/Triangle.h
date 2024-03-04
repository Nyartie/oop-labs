#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <vector>
#include <cmath>

#include "Figure.h"

class Triangle : public Figure
{
public:
    Triangle() {}
    Triangle(const std::vector<std::pair<double, double>>& vertices) : vertices_(vertices) {}

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
        return std::abs((vertices_[0].first * (vertices_[1].second - vertices_[2].second) +
                         vertices_[1].first * (vertices_[2].second - vertices_[0].second) +
                         vertices_[2].first * (vertices_[0].second - vertices_[1].second)) /
                        2);
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
        for (int i = 0; i < 3; ++i)
        {
            is >> x >> y;
            vertices_.emplace_back(x, y);
        }
    }

private:
    std::vector<std::pair<double, double>> vertices_;
};

#endif // TRIANGLE_H