#include <gtest/gtest.h>
#include "Figure.h"
#include "Octagon.h"
#include "Triangle.h"
#include "Square.h"

TEST(FigureTest, OctagonArea)
{
    Octagon octagon({{0, 0}, {1, 1}, {2, 0}, {3, 1}, {4, 0}, {3, -1}, {2, 0}, {1, -1}});
    ASSERT_DOUBLE_EQ(octagon.area(), 10.0);
}

TEST(FigureTest, TriangleArea)
{
    Triangle triangle({{0, 0}, {3, 0}, {0, 4}});
    ASSERT_DOUBLE_EQ(triangle.area(), 6.0);
}

TEST(FigureTest, SquareArea)
{
    Square square({{0, 0}, {0, 3}, {3, 3}, {3, 0}});
    ASSERT_DOUBLE_EQ(square.area(), 9.0);
}

TEST(FigureTest, OctagonCenter)
{
    Octagon octagon({{0, 0}, {1, 1}, {2, 0}, {3, 1}, {4, 0}, {3, -1}, {2, 0}, {1, -1}});
    auto center = octagon.center();
    ASSERT_DOUBLE_EQ(center.first, 2.0);
    ASSERT_DOUBLE_EQ(center.second, 0.0);
}

TEST(FigureTest, TriangleCenter)
{
    Triangle triangle({{0, 0}, {3, 0}, {0, 4}});
    auto center = triangle.center();
    ASSERT_DOUBLE_EQ(center.first, 1.0);
    ASSERT_DOUBLE_EQ(center.second, 1.3333333333333333);
}

TEST(FigureTest, SquareCenter)
{
    Square square({{0, 0}, {0, 3}, {3, 3}, {3, 0}});
    auto center = square.center();
    ASSERT_DOUBLE_EQ(center.first, 1.5);
    ASSERT_DOUBLE_EQ(center.second, 1.5);
}

TEST(FigureTest, OctagonVertices)
{
    Octagon octagon({{0, 0}, {1, 1}, {2, 0}, {3, 1}, {4, 0}, {3, -1}, {2, 0}, {1, -1}});
    std::ostringstream oss;
    octagon.printVertices(oss);
    ASSERT_EQ(oss.str(), "(0, 0) (1, 1) (2, 0) (3, 1) (4, 0) (3, -1) (2, 0) (1, -1) ");
}

TEST(FigureTest, TriangleVertices)
{
    Triangle triangle({{0, 0}, {3, 0}, {0, 4}});
    std::ostringstream oss;
    triangle.printVertices(oss);
    ASSERT_EQ(oss.str(), "(0, 0) (3, 0) (0, 4) ");
}

TEST(FigureTest, SquareVertices)
{
    Square square({{0, 0}, {0, 3}, {3, 3}, {3, 0}});
    std::ostringstream oss;
    square.printVertices(oss);
    ASSERT_EQ(oss.str(), "(0, 0) (0, 3) (3, 3) (3, 0) ");
}
