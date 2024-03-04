#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include <vector>
#include <cmath>

#include "Figure.h"

class Octagon : public Figure
{
public:
    Octagon() {}
    Octagon(const std::vector<std::pair<double, double>>& vertices) : vertices_(vertices) {}

    std::pair<double, double> center() const override
    {
        double sumX = 0, sumY = 0;
        for (const auto& vertex : vertices_)
        {
            sumX += vertex.first;
            sumY += vertex.second;
        }
        return {sumX / vertices_.size(), sumY / vertices_.size()};
    }

    double area() const override
    {
        double area = 0;
        for (size_t i = 0; i < vertices_.size(); ++i)
        {
            const auto& p1 = vertices_[i];
            const auto& p2 = vertices_[(i + 1) % vertices_.size()];
            area += p1.first * p2.second - p2.first * p1.second;
        }
        return std::abs(area) / 2;
    }

    void printVertices(std::ostream& os) const override
    {
        for (const auto& vertex : vertices_)
        {
            os << "(" << vertex.first << ", " << vertex.second << ") ";
        }
    }

    void read(std::istream& is) override
    {
        vertices_.clear();
        double x, y;
        for (int i = 0; i < 8; ++i)
        {
            is >> x >> y;
            vertices_.emplace_back(x, y);
        }
    }

private:
    std::vector<std::pair<double, double>> vertices_;
};

#endif // OCTAGON_H