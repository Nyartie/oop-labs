#include "figure.hpp"
#include "point.hpp"

template <Number T>
class Octagon : public Figure<T> {
private:
    std::vector<Point<T>> vertices;

public:
    Octagon() : vertices(8) {}

    std::pair<double, double> center() const{
        double sum_x = 0, sum_y = 0;
        for (const auto& vertex : vertices) {
            sum_x += vertex.x;
            sum_y += vertex.y;
        }
        return {sum_x / 8, sum_y / 8};
    }

    double area() const{
        // Реализация вычисления площади 8-угольника
        double area = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            size_t j = (i + 1) % vertices.size();
            area += (vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y);
        }
        return std::abs(area) / 2.0;
    }

    void printVertices(std::ostream& os) const {
        for (const auto& vertex : vertices) {
            os << "(" << vertex.x << ", " << vertex.y << ") ";
        }
    }

    void read(std::istream& is){
        for (auto& vertex : vertices) {
            is >> vertex.x >> vertex.y;
        }
    }

    Octagon& operator=(const Octagon& other) = default;

    Octagon& operator=(Octagon&& other) noexcept = default;

    bool operator==(const Octagon<T>& rhs) const {
        return vertices == rhs.vertices;
    }
};
