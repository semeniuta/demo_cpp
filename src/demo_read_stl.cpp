// char[80] – Header
// char[4]  – Number of triangles (unsigned long)

// foreach triangle
//     char[12] – Normal vector (float[3])
//     char[12] – Vertex 1 (float[3])
//     char[12] – Vertex 2 (float[3])
//     char[12] – Vertex 3 (float[3])
//     char[2]  – Attribute byte count (short)
// end 

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cassert>
#include <cstdio>
#include <vector>

namespace {

struct Facet
{
    float normal[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

std::ifstream open_binary_file(const char* filename)
{
    return std::ifstream{filename, std::ifstream::in | std::ifstream::binary};
}

template <typename T>
char* as_char_ptr(T* pointer)
{
    return reinterpret_cast<char*>(pointer);
}

template <typename T>
void read_binary_value(std::ifstream& in, T* dst)
{
    in.read(as_char_ptr(dst), sizeof(T));
}

template <typename T>
void read_binary_array(std::ifstream& in, T* dst, size_t array_length)
{
    size_t n_bytes = array_length * sizeof(T);
    in.read(as_char_ptr(dst), n_bytes);
}

void print_point(const char* prefix, const float x[3])
{
    printf("%s[%.1f, %.1f, %.1f]", prefix, x[0], x[1], x[2]);
}

void print_facet(const Facet& f, size_t index)
{
    printf("facet %zu: ", index);
    print_point("normal = ", f.normal);
    printf(", ");
    print_point("v1 = ", f.v1);
    printf(", ");
    print_point("v2 = ", f.v2);
    printf(", ");
    print_point("v3 = ", f.v3);
    printf("\n");
}

}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage demo_read_stl mesh_model.stl\n";
        return -1;
    }

    auto filename = argv[1];

    if (!std::filesystem::exists(filename)) {
        std::cerr << "File " << filename << " does not exist\n";
        return -2;
    }

    std::cout << "Sizes of data types:\n";
    std::cout << "float: " << sizeof(float) << "\n";
    std::cout << "unsigned int: " << sizeof(unsigned int) << "\n";
    std::cout << "unsigned long: " << sizeof(unsigned long) << "\n";
    std::cout << "short: " << sizeof(short) << "\n";

    assert(sizeof(short) == 2);
    assert(sizeof(float) == 4);
    assert(sizeof(unsigned int) == 4);

    auto in = open_binary_file(filename);

    char header[81];
    unsigned int n_facets;

    read_binary_array<char>(in, header, 80);
    header[80] = '\0';

    read_binary_value<unsigned int>(in, &n_facets);

    std::cout << "Header: " << header << "\n";
    std::cout << "Number of facets: " << n_facets << "\n";

    std::vector<Facet> facets;
    facets.reserve(n_facets);

    for (size_t i = 0; i < n_facets; ++i) {
        Facet f{};
        read_binary_array<float>(in, f.normal, 3);
        read_binary_array<float>(in, f.v1, 3);
        read_binary_array<float>(in, f.v2, 3);
        read_binary_array<float>(in, f.v3, 3);

        print_facet(f, i);

        facets.emplace_back(f);
    }

    return 0;
}