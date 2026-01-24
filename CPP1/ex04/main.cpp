#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit() için

void replaceContent(std::string const &filename, std::string const &s1, std::string const &s2) {
    // 1. Girdi dosyasını aç
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        std::exit(1);
    }

    // 2. Çıktı dosyasını hazırla (<filename>.replace)
    std::string outFilename = filename + ".replace";
    std::ofstream outputFile(outFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
        inputFile.close(); // Açık dosyayı kapatmayı unutma
        std::exit(1);
    }

    // 3. Dosya içeriğini tamamen oku
    // IMPROVED: Use seekg/read for robust binary file support
    inputFile.seekg(0, std::ios::end);
    std::streamsize fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    
    std::string content;
    if (fileSize > 0) {
        content.resize(fileSize);
        inputFile.read(&content[0], fileSize);
    }

    // 4. Arama ve Değiştirme Döngüsü (Algoritmanın Kalbi)
    size_t pos = 0;
    size_t foundPos;
    
    // s1 boşsa sonsuz döngüye girmemek için kontrol
    if (s1.empty()) {
        outputFile << content;
        inputFile.close();
        outputFile.close();
        return;
    }

    // İçerikte s1'i ara...
    while ((foundPos = content.find(s1, pos)) != std::string::npos) {
        outputFile << content.substr(pos, foundPos - pos);
        
        // Yerine s2'yi yaz
        outputFile << s2;
        
        // Pozisyonu s1'in bittiği yere taşı
        pos = foundPos + s1.length();
    }
    
    // Kalan son parçayı (varsa) yaz
    outputFile << content.substr(pos);

    // 5. Dosyaları kapat
    inputFile.close();
    outputFile.close();
}

int main(int argc, char **argv) {
    // Argüman kontrolü: Program adı + dosya + s1 + s2 = 4 argüman
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