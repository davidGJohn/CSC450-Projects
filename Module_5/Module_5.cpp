#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

/**
 * @brief Initializes the file with default header if it's empty
 *
 * @param filename Name of the file to check and initialize if needed
 */
void initializeFile(const std::string& filename) {
    std::ifstream checkFile(filename);
    bool isEmpty = checkFile.peek() == std::ifstream::traits_type::eof();
    checkFile.close();

    if (isEmpty) {
        std::ofstream initFile(filename);
        if (initFile) {
            initFile << "Please be sure to append your data to this text file. \n"
                << "\n"
                << "If these first three lines are deleted, then your program is not functioning as expected.\n"
                << "\n";
            initFile.close();
        }
    }
}

/*
 * @brief Reverses all characters in a file and writes to another file
 *
 * @param inputFilename The source file
 * @param outputFilename The destination file to store reversed content
 */
void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile || !outputFile) {
        std::cerr << "Error: Unable to open file(s) for reversing.\n";
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>());

    std::reverse(content.begin(), content.end());

    outputFile << content;

    inputFile.close();
    outputFile.close();

    std::cout << "Reversed content written to " << outputFilename << "\n";
}

/**
 * @brief Main method to append user input and reverse file content
 */
int main() {
    const std::string inputFilename = "CSC450_CT5_mod5.txt";
    const std::string reversedFilename = "CSC450-mod5-reverse.txt";

    initializeFile(inputFilename);

    std::ofstream outFile(inputFilename, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: File could not be opened: " << inputFilename << std::endl;
        return 1;
    }

    std::string userInput;
    std::cout << "Enter text to append (type 'exit' to stop):\n";
    while (true) {
        std::getline(std::cin, userInput);
        if (userInput == "exit") break;

        outFile << userInput << std::endl;
    }

    outFile.close();
    std::cout << "User input appended to file.\n";

    reverseFileContent(inputFilename, reversedFilename);

    return 0;
}
