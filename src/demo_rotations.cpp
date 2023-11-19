#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace {

Eigen::AngleAxisf rotate_x(float angle)
{
    return {angle, Eigen::Vector3f::UnitX()};
}

Eigen::AngleAxisf rotate_y(float angle)
{
    return {angle, Eigen::Vector3f::UnitY()};
}

Eigen::AngleAxisf rotate_z(float angle)
{
    return {angle, Eigen::Vector3f::UnitZ()};
}

void print_array(const auto& arr, const char* prefix)
{
    std::cout << prefix << ":\n" << arr << "\n\n";
}

} // namespace

int main()
{
    Eigen::Translation<float, 3> t{0.5f, 0.4f, 0.3f};

    const float angle_x = M_PI / 4;
    const float angle_y = M_PI / 3;
    const float angle_z = -M_PI / 8;
    const auto R = rotate_x(angle_x) * rotate_y(angle_y) * rotate_z(angle_z);

    const auto transform = t * R;

    print_array(t.vector(), "Translation");
    print_array(R.matrix(), "Rotation");
    print_array(transform.matrix(), "Transformation");
}