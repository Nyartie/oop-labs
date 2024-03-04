#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>

class Figure{
public:
    virtual ~Figure() {}

    virtual std::pair<double, double> center() const = 0;
    virtual double area() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    operator double() const
    {
        return area();
    }
};

std::ostream& operator<<(std::ostream& os, const Figure& figure)
{
    figure.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure)
{
    figure.read(is);
    return is;
}

#endif // FIGURE_H