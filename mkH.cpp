#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for toupper
#include <locale> // for std::toupper

std::string mkUpper(std::string inStr)
{
    for(char &c : inStr)
    {
        c=std::toupper(c);
    }
    return inStr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ofstream outfile(filename + ".h");

    if (outfile.is_open()) {
        outfile << "#ifndef _" << mkUpper(filename) << "_H_" << std::endl;
        outfile << "#define _" << mkUpper(filename) << "_H_" << std::endl << std::endl;
        outfile << "#endif // _" << filename << "_H_" << std::endl;

        std::cout << "Generated header file '" << filename << ".h' successfully." << std::endl;
        outfile.close();
    } else {
        std::cerr << "Unable to open file '" << filename << ".h' for writing." << std::endl;
        return 1;
    }

    return 0;
}