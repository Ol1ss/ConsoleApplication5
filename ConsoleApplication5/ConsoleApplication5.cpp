#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
    bool writeToFile(std::string filename, std::string data);
    bool readFromFile(std::string filename, std::string& data);
    bool deleteFile(std::string filename);
};

class DataProcessor {
public:
    bool processData(std::string& data);
};

bool FileHandler::writeToFile(std::string filename, std::string data) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Unable to open file " << filename << " for writing." << std::endl;
        return false;
    }

    file << data;

    file.close();
    return true;
}

bool FileHandler::readFromFile(std::string filename, std::string& data) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Unable to open file " << filename << " for reading." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        data += line + "\n";
    }

    file.close();
    return true;
}

bool FileHandler::deleteFile(std::string filename) {
    if (std::remove(filename.c_str()) != 0) {
        std::cout << "Unable to delete file " << filename << "." << std::endl;
        return false;
    }

    return true;
}

bool DataProcessor::processData(std::string& data) {
    return true;
}