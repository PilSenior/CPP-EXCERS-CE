#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void replaceContent(std::string const &filename, std::string const &s1, std::string const &s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        std::exit(1);
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outputFile(outFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
        inputFile.close();
        std::exit(1);
    }

    // IMPROVED: Read entire file using stringstream (more portable)
    std::string content;
    std::string line;
    bool firstLine = true;
    
    while (std::getline(inputFile, line)) {
        if (!firstLine) {
            content += "\n";
        }
        content += line;
        firstLine = false;
    }

    // Handle case where file doesn't end with newline
    if (inputFile.eof() && !content.empty()) {
        // File read successfully
    }

    size_t pos = 0;
    size_t foundPos;
    
    if (s1.empty()) {
        outputFile << content;
        inputFile.close();
        outputFile.close();
        return;
    }

    while ((foundPos = content.find(s1, pos)) != std::string::npos) {
        outputFile << content.substr(pos, foundPos - pos);
        outputFile << s2;
        pos = foundPos + s1.length();
    }
    
    outputFile << content.substr(pos);

    inputFile.close();
    outputFile.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceContent(filename, s1, s2);

    return 0;
}
