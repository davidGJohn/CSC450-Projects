#include <iostream>
#include <string>


int main() {
    std::string input1;
    std::string input2;
    std::string result;

    std::cout << "=== String Concatenation Program ===\n";

    for (int i = 1; i <= 3; ++i) {
        std::cout << "\n--- Test Case " << i << " ---\n";

        // Prompt user for first input
        std::cout << "Enter the first string: ";
        std::getline(std::cin, input1);

        // Prompt user for second input
        std::cout << "Enter the second string: ";
        std::getline(std::cin, input2);

        // Concatenate safely using std::string
        result = input1 + input2;

        // Output the result
        std::cout << "Concatenated string: " << result << "\n";
    }

    std::cout << "\Program Finished.\n";
    return 0;
}
