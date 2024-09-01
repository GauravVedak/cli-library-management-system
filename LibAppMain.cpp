// Final Project
// LibAppMain Module
// File    LibAppMain.cpp
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////#include <fstream>
#include <iostream>
#include "LibApp.h"
#include "Date.h"
#include "Menu.h"
#include "Date.cpp"
using namespace sdds;
void runApp(const char* filename) {
    size_t i{};
    char ch;
    char original[31] = "orig";
    while (filename[i]) {
        original[4u + i] = filename[i];
        i++;
    }
    original[4u + i] = char(0);
    std::ofstream outFile(filename);
    std::ifstream inFile(original);
    while (inFile.get(ch)) {
        outFile << ch;
    }
    outFile.close();
    inFile.close();
    sdds::sdds_day = 13;
    sdds::sdds_mon = 8;
    sdds::sdds_year = 2024;
    sdds::sdds_test = true;
    sdds::LibApp app(filename);
    app.run();
    std::cout << "Content of " << filename << "\n=========>\n";
    inFile.open(filename);
    while (inFile.get(ch)) std::cout << ch;
    std::cout << "<=========\n";
}
int main() {
    Menu outFile("Select Data File");
    outFile << "LibRecsSmall.txt" << "LibRecs.txt";
    switch (outFile.run()) {
    case 1:
        std::cout << "Test started using small data: " << std::endl;
        runApp("LibRecsSmall.txt");
        break;
    case 2:
        std::cout << "Test started using big data: " << std::endl;
        runApp("LibRecs.txt");
        break;
    default:
        std::cout << "Aborted by user! " << std::endl;
        break;
    }
    return 0;
}