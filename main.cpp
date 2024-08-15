#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string grayscaleToASCII(int grayscale) {
    // A list of ASCII characters that correspond to grayscale values
    const std::string ascii_chars = "@%#*+=-:. ";
    // Map the grayscale value (0-255) to a character index (0-9)
    int index = (grayscale * ascii_chars.size()) / 256;
    return std::string(1, ascii_chars[index]);
}

int main() {
    // File paths
    std::string input_file = R"(image.txt)"; //path image.text
    std::string output_file = R"(ACII art.txt)"; //path ACII art.text

    std::ifstream infile(input_file);
    std::ofstream outfile(output_file);

    if (!infile.is_open()) {
        std::cerr << "Error opening input file: " << input_file << std::endl;
        return 1;
    }
    
    if (!outfile.is_open()) {
        std::cerr << "Error opening output file: " << output_file << std::endl;
        return 1;
    }

    // Read the width and height from the input file
    int width, height;
    infile >> width >> height;

    // Read the grayscale pixel values and convert to ASCII
    std::vector<int> grayscale_values;
    int value;

    // Go through each pixel value in the input file
    for (int i = 0; i < width * height; ++i) {
        infile >> value;
        std::string ascii_char = grayscaleToASCII(value);
        outfile << ascii_char;

        // Add a newline after each row
        if ((i + 1) % width == 0) {
            outfile << '\n';
        }
    }

    // Close the files
    infile.close();
    outfile.close();

    std::cout << "ASCII art saved to " << output_file << std::endl;
    
    return 0;
}
