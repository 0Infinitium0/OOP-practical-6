#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

/**
 * Abstract Base Class: Shape
 *
 * Contains a pure virtual function `area() = 0` and a virtual destructor.
 * Because `Shape` has at least one pure virtual function, it is an abstract class
 * and cannot be instantiated directly (e.g., `Shape s;` causes a compile-time error).
 * However, `Shape*` pointers and `Shape&` references can point to concrete derived objects
 * and invoke the appropriate overridden `area()` method at runtime (dynamic dispatch).
 */
class Shape {
public:
    virtual double area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius_;
    static constexpr double PI = 3.141592;

public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override {
        return PI * radius_ * radius_;
    }

    void display() const override {
        std::cout << "----- CIRCLE -----\n";
        std::cout << "Radius: " << radius_ << "\n";
        std::cout << "Area of Circle: " << std::setprecision(6) << area() << "\n";
    }
};

class Rectangle : public Shape {
private:
    double length_;
    double breadth_;

public:
    Rectangle(double length, double breadth)
        : length_(length), breadth_(breadth) {}

    double area() const override {
        return length_ * breadth_;
    }

    void display() const override {
        std::cout << "----- RECTANGLE -----\n";
        std::cout << "Length: " << length_ << "\n";
        std::cout << "Breadth: " << breadth_ << "\n";
        std::cout << "Area of Rectangle: " << area() << "\n";
    }
};

class Triangle : public Shape {
private:
    double base_;
    double height_;

public:
    Triangle(double base, double height)
        : base_(base), height_(height) {}

    double area() const override {
        return 0.5 * base_ * height_;
    }

    void display() const override {
        std::cout << "----- TRIANGLE -----\n";
        std::cout << "Base: " << base_ << "\n";
        std::cout << "Height: " << height_ << "\n";
        std::cout << "Area of Triangle: " << area() << "\n";
    }
};

int main() {
    std::cout << "----- RUNTIME POLYMORPHISM -----\n";
    std::cout << "Student Name: Satinderpal Singh Chaney\n";
    std::cout << "Roll Number: E26B00S2034\n";

    // Note: Uncommenting the line below causes a compilation error because Shape is abstract:
    // Shape invalidShape; // error: cannot declare variable 'invalidShape' to be of abstract type 'Shape'

    // Store concrete derived objects via base-class smart pointers (Shape*)
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(10.0, 5.0));
    shapes.push_back(std::make_unique<Triangle>(8.0, 6.0));

    // Call overridden virtual functions through the Shape* base-class interface
    for (const auto& shapePtr : shapes) {
        shapePtr->display();
    }

    std::cout << "Runtime Polymorphism Demonstrated Successfully!\n";
    std::cout << "Program executed successfully.\n";

    return 0;
}
