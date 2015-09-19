#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "WordPuzzleSolver.h"
void create_file();

using namespace std;

const string INPUTFILE = "/Users/ben/Desktop/263/pzl_100_100.txt";
//const string INPUTFILE = "/Users/ben/Desktop/263/wordinput.txt";

// Windows users may want to use one of the following paths
//const string INPUTFILE = "C:\\Customize\\it\\to\\your\\own\\path.txt"
//const string INPUTFILE = "C:/Customize/it/to/your/own/path.txt"

int main() {
    //create_file();
    ifstream puzzle_input (INPUTFILE);
    
    WordPuzzleSolver one;
    
    one.load (puzzle_input);
    
    puzzle_input.close();
    
    one.solve ("");
    one.write_file();
    //one.solve ("quadruple");   // or solve using the other technique
}
