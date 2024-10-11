#include <gflags/gflags.h>
#include <glog/logging.h>
#include <numbers>
#include <variant>

namespace inheritance {

class Shape {
 public:
  virtual double Area() const = 0;
  virtual void Draw() const { LOG(INFO) << "Drawing a " << name_; }
  virtual ~Shape() = default;
  std::string name_;
};

class Circle : public Shape {
 public:
  Circle(double r) : radius_(r) { name_ = "Circle"; }
  double Area() const override { return std::numbers::pi * radius_ * radius_; }

 private:
  double radius_;
};

class Square : public Shape {
 public:
  Square(double s) : side_(s) { name_ = "Square"; }
  double Area() const override { return side_ * side_; }

 private:
  double side_;
};
}  // namespace inheritance

namespace composition {

class IShape {
 public:
  virtual double Area() const = 0;
  virtual void Draw() const = 0;
  virtual ~IShape() = default;
};

// This class handles common shape properties like name and drawing
class ShapeAttributes {
 public:
  ShapeAttributes(const std::string& name) : name_(name) {}
  void Draw() const { LOG(INFO) << "Drawing a " << name_; }

 private:
  std::string name_;
};

// Circle is an IShape but uses composition.
class Circle : public IShape {
 public:
  Circle(double r) : radius_(r), attributes_("Circle") {}
  double Area() const override { return std::numbers::pi * radius_ * radius_; }
  void Draw() const override {
    attributes_.Draw();
  }  // Delegating the Draw call to ShapeAttributes

 private:
  double radius_;
  ShapeAttributes attributes_;  // Composition instead of inheritance
};

// Square is an IShape but uses composition.
class Square : public IShape {
 public:
  explicit Square(double s) : side_(s), attributes_("Square") {}
  double Area() const override { return side_ * side_; }
  void Draw() const override { attributes_.Draw(); }

 private:
  double side_;
  ShapeAttributes attributes_;
};

}  // namespace composition

namespace variant_composition {

// This class handles common shape properties like name and drawing
class ShapeAttributes {
 public:
  ShapeAttributes(const std::string& name) : name_(name) {}
  void Draw() const { LOG(INFO) << "Drawing a " << name_; }

 private:
  std::string name_;
};

// Circle uses composition, no inheritance.
class Circle {
 public:
  Circle(double r) : radius_(r), attributes_("Circle") {}
  double Area() const { return std::numbers::pi * radius_ * radius_; }
  void Draw() const {
    attributes_.Draw();
  }  // Delegating the Draw call to ShapeAttributes

 private:
  double radius_;
  ShapeAttributes attributes_;  // Composition instead of inheritance
};

// Square uses composition, no inheritance.
class Square {
 public:
  explicit Square(double s) : side_(s), attributes_("Square") {}
  double Area() const { return side_ * side_; }
  void Draw() const { attributes_.Draw(); }

 private:
  double side_;
  ShapeAttributes attributes_;
};
}  // namespace variant_composition

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  LOG(INFO) << "Inheritance";
  std::vector<std::unique_ptr<inheritance::Shape>> shapes;
  shapes.push_back(std::make_unique<inheritance::Circle>(5));
  shapes.push_back(std::make_unique<inheritance::Square>(4));
  for (const auto& shape : shapes) {
    LOG(INFO) << shape->name_ << " area: " << shape->Area();
    shape->Draw();
  }

  LOG(INFO) << "Composition";
  std::vector<std::unique_ptr<composition::IShape>> shapes_composition;
  shapes_composition.push_back(std::make_unique<composition::Circle>(5));
  shapes_composition.push_back(std::make_unique<composition::Square>(4));

  for (const auto& shape : shapes_composition) {
    LOG(INFO) << "Shape area: " << shape->Area();
    shape->Draw();  // Calls the Draw() function via the interface
  }

  // This is the best approach
  LOG(INFO) << "Composition with variant";
  using ShapeVariant =
      std::variant<variant_composition::Circle, variant_composition::Square>;
  std::vector<ShapeVariant> shapes_variant;
  shapes_variant.emplace_back(variant_composition::Circle(5));
  shapes_variant.emplace_back(variant_composition::Square(4));
  for (const auto& shape : shapes_variant) {
    std::visit(
        [](const auto& s) {
          LOG(INFO) << "Shape area: " << s.Area();
          s.Draw();
        },
        shape);
  }
}