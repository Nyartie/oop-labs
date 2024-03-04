#include <iostream>
#include <vector>
#include <cmath>

#include "Figure.h"
#include "Octagon.h"
#include "Square.h"
#include "Triangle.h"

int main() {
    std::vector<Figure*> figures;

    char choice;
    do {
        std::cout << "Enter type of figure (O - Octagon, T - Triangle, S - Square): ";
        std::cin >> choice;

        Figure* figure;
        switch (choice)
        {
            case 'O':
                figure = new Octagon();
                break;
            case 'T':
                figure = new Triangle();
                break;
            case 'S':
                figure = new Square();
                break;
            default:
                continue;
        }

        std::cin >> *figure;
        figures.push_back(figure);

        std::cout << "Do you want to enter another figure? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    for (const auto& figure : figures)
    {
        std::cout << "Vertices: " << *figure << std::endl;
        std::cout << "Center: " << figure->center().first << ", " << figure->center().second << std::endl;
        std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
        std::cout << std::endl;
    }


    double totalArea = 0;
    for (const auto& figure : figures)
    {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total area of figures: " << totalArea << std::endl;

    size_t index;
    std::cout << "Enter index of figure to remove: ";
    std::cin >> index;
    if (index < figures.size())
    {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }

    for (const auto& figure : figures)
    {
        delete figure;
    }

    return 0;
}
