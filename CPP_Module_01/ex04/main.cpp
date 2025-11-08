#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    std::string file = argv[1];
    std::string string1 = argv[2];
    std::string string2 = argv[3];
    std::string line;

    if (argc != 4) {
        std::cout << "Usage: ./replace <file> <old word> <new word>" << std::endl;
        return (1);
    }
    std::ifstream in(file.c_str());
    if (!in) {
        std::cout << "Error: cannot open file: " << file << std::endl;
        return (1);
    }
    std::ofstream out((file + ".replace").c_str());
    if (!out) {
        std::cout << "Error: cannot create file: " << file << ".replace" << std::endl;
        return (1);
    }
    while (std::getline(in, line)) {
        size_t position = 0;
        while ((position = line.find(string1, position)) != std::string::npos) {
            line.erase(position, string1.length());
            line.insert(position, string2);
            position += string2.length();
        }
        out << line;
        if (!in.eof())
            out << "\n";
    }
    return (0);
}