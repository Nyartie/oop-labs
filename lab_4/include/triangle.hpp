#include "figure.hpp"
#include "point.hpp"

template <class T>
class Triangle : public Figure<T> {
private:
    std::vector<Point<T>> vertices;

public:
    Triangle() : vertices(3) {}

    void setVertices(const std::vector<Point<T>>& points) {
        vertices = points;
    }

    std::pair<double, double> center() const override {
        double sum_x = 0, sum_y = 0;
        for (const auto& vertex : vertices) {
            sum_x += vertex.x;
            sum_y += vertex.y;
        }
        return {sum_x / 3, sum_y / 3};
    }

    double area() const override {
        const auto& A = vertices[0];
        const auto& B = vertices[1];
        const auto& C = vertices[2];
        double a = std::hypot(B.x - C.x, B.y - C.y);
        double b = std::hypot(C.x - A.x, C.y - A.y);
        double c = std::hypot(A.x - B.x, A.y - B.y);
        double p = (a + b + c) / 2.0;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
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

    Triangle& operator=(const Triangle& other) = default;

    Triangle& operator=(Triangle&& other) noexcept = default;
};