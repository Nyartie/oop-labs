#include "figure.hpp"
#include "point.hpp"

template <class T>
class Square : public Figure<T> {
private:
    std::vector<Point<T>> vertices;

public:
    Square() : vertices(4) {}

    void setVertices(const std::vector<Point<T>>& points) {
        vertices = points;
    }

    std::pair<double, double> center() const override {
        double sum_x = 0, sum_y = 0;
        for (const auto& vertex : vertices) {
            sum_x += vertex.x;
            sum_y += vertex.y;
        }
        return {sum_x / 4, sum_y / 4};
    }

    double area() const override {
        const auto& A = vertices[0];
        const auto& B = vertices[1];
        const auto& C = vertices[2];
        const auto& D = vertices[3];
        double side_length = std::hypot(B.x - A.x, B.y - A.y);
        return side_length * side_length;
    }

    void printVertices(std::ostream& os) const override {
        for (const auto& vertex : vertices) {
            os << "(" << vertex.x << ", " << vertex.y << ") ";
        }
    }

    void read(std::istream& is) override {
        for (auto& vertex : vertices) {
            is >> vertex.x >> vertex.y;
        }
    }

    Square& operator=(const Square& other) = default;

    Square& operator=(Square&& other) noexcept = default;
};
