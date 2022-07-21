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

namespace {

struct Facet
{
    float normal[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

std::ifstream open_binary_file(char* filename)
{
    return std::ifstream{filename, std::ifstream::in | std::ifstream::binary};
}

void read_binary_uint(std::ifstream& in, unsigned int* dst)
{
    auto bytes_ptr = reinterpret_cast<char*>(dst);
    in.read(bytes_ptr, sizeof(unsigned int));
}

void read_binary_chars(std::ifstream& in, char* dst, size_t length)
{
    in.read(dst, length);
}

void read_binary_floats(std::ifstream& in, float* dst, size_t length)
{
    auto bytes_ptr = reinterpret_cast<char*>(dst);
    size_t n_bytes = length * sizeof(float);
    in.read(bytes_ptr, n_bytes);
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

    read_binary_chars(in, header, 80);
    header[80] = '\0';

    read_binary_uint(in, &n_facets);

    std::cout << "Header: " << header << "\n";
    std::cout << "Number of facets: " << n_facets << "\n";

    for (size_t i = 0; i < n_facets; ++i) {
        Facet f;
        read_binary_floats(in, f.normal, 3);
        read_binary_floats(in, f.v1, 3);
        read_binary_floats(in, f.v2, 3);
        read_binary_floats(in, f.v3, 3);
        std::cout << f.normal[1] << std::endl;
    }

    return 0;
}