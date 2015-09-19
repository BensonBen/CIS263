
#include "WordPuzzleSolver.h"
#include <iostream>
#include <iomanip>

WordPuzzleSolver::WordPuzzleSolver() {
    /* add more code here as necessary */
}


void WordPuzzleSolver::triplets(){
    //int row, col;
    //start looking for the first word the the vector
    for(int i = 0; i<the_words.size(); ++i){
        //columns
        for(int j =0; j<the_grid.size(); ++j){
            //rows
            for (int k =0; k<the_grid[0].size(); ++k) {
                //get the word we're looking for, and the first letter
                //of that word, then compare to it the position within
                //the array.
                if(the_words.at(i).at(0) == the_grid[j][k]){
                    
                    auto check = colCheck(j, k, the_words.at(i), 0);
                    
                    if(std::get<0>(check)){
                        //TEXT 0 2 DOWN
                        result += get<1>(check)+" "+to_string(j)+" "+to_string(k)+" ACROSS\n";
                        break;
                    }
                    auto check2 = rowCheck(j,k,the_words.at(i),0);
                    if(get<0>(check2)){
                        result += get<1>(check2)+" "+to_string(j)+" "+to_string(k)+" DOWN\n";
                        break;
                    }
                }
            }
        }
    }
}

void WordPuzzleSolver::quantiplets(){
    for(int i = 0; i<the_words.size(); ++i){
        //columns
        for(int j =0; j<the_grid.size(); ++j){
            //rows
            for (int k =0; k<the_grid[0].size(); ++k) {
                //get the word we're looking for, and the first letter
                //of that word, then compare to it the position within
                //the array.
                if(the_words.at(i).at(0) == the_grid[j][k]){
                    
                    auto check = quan_check_col(j, k, the_words.at(i), the_words.at(i).size(),0);
                    if(std::get<0>(check)){
                        //TEXT 0 2 DOWN
                        result += get<1>(check)+" "+to_string(j)+" "+to_string(k)+" ACROSS\n";
                        break;
                    }
                    
                    auto check2 = quan_check_row(j, k, the_words.at(i), the_words.at(i).size(), 0);
                    
                    if(get<0>(check2)){
                        result += get<1>(check2)+" "+to_string(j)+" "+to_string(k)+" DOWN\n";
                    }
                }
            }
        }
    }
}

tuple <bool, string> WordPuzzleSolver::quan_check_row(int row, int &col, string &word, int length, int pos){
    if(pos==length){
        return make_tuple(true, word);
    }
    if((the_grid[0].size() - col)< length){
        make_tuple(false, word);
    }
    
    if(row >= the_grid.size() || pos > word.size()){
        return make_tuple(false, word);
    }
    if(the_grid[row][col] == word.at(pos)){
        return quan_check_row(++row, col, word, length, ++pos);
    }
    return make_tuple(false, word);
}

tuple <bool, string> WordPuzzleSolver::quan_check_col(int &row, int col, string &word, int length, int pos){
    if(pos==word.length()){
        return make_tuple(true, word);
    }
    if((the_grid[0].size() - col)< length){
        make_tuple(false, word);
    }
    
    if(the_grid[row][col+length-1]!=word.at(length-1)){
        make_tuple(false, word);
    }
    if(col >= the_grid[0].size() || pos > word.size()){
        return make_tuple(false, word);
    }
    if(the_grid[row][col] == word.at(pos)){
        return quan_check_col(row, ++col, word, length, ++pos);
    }
    return make_tuple(false, word);
}

/*****************************************************************************************
 * This method is the column check using the triplet method.
 * Once it is called it checks the accross the grid.
 ****************************************************************************************/
tuple <bool, string> WordPuzzleSolver::colCheck(int &row, int col, string &word, int pos){
    
    if(pos==word.length()){
        return make_tuple(true, word);
    }
    
    if(col >= the_grid[0].size() || pos > word.size()){
        return make_tuple(false, word);
    }
    if(the_grid[row][col] == word.at(pos)){
       return colCheck(row, ++col, word, ++pos);
    }
    return make_tuple(false, word);
}

/*****************************************************************************************
 * This method is the  check using the triplet method.
 * Checks the downward position within grid.
 ****************************************************************************************/
tuple <bool, string> WordPuzzleSolver::rowCheck(int row, int &col, string &word, int pos){
    if(pos==word.length()){
        return make_tuple(true, word);
    }
    if(row >= the_grid.size() || pos > word.size()){
        return make_tuple(false, word);
    }
    if(the_grid[row][col]==word.at(pos)){
        return rowCheck(++row, col, word, ++pos);
    }
    
   return make_tuple(false, word);
}

void WordPuzzleSolver::write_file(){
    ofstream fs("/Users/ben/Desktop/263/result.txt");
    
    if(fs.is_open()){
        fs << result;
    }
   
    fs.close();
}



void WordPuzzleSolver::load (ifstream &input) {
    int height, width, num_words;
    input >> height >> width;
    
    the_grid.resize (height, vector<char>(width));
    
    /* the following nested loops read all the letters and place them
     * into the grid */
    for (int k = 0; k < height; k++) {
        for (int m = 0; m < width; m++) {
            /* "ws" is an I/O manipulator to skip whitespaces */
            input >> ws >> the_grid[k][m];
        }
    }
    
    input >> num_words;
    
    string w;
    for (int k = 0; k < num_words; k++)
    {
        input >> w;  /* no ws I/O manip required here */
        the_words.push_back (w);
    }
    
    /* You may add more code to this function */
}

void WordPuzzleSolver::solve(const string &which) {
    
//#ifndef MUTE_ALL_DEBUGGING_OUTPUT
//    // Print your DEBUGGING output to clog
//    clog << "...for debugging only..." << endl;
//    
//    clog << "The board size is "
//    << the_grid.size() << "x" << the_grid[0].size() << endl;
//    clog << "and " << the_words.size() << " words to search." << endl << endl;
//    
//    for (auto& me : the_words) {   // me is now a string
//        clog << me << endl;
//    }
//#endif
    
    /* Java string "operator==" will be used here */
    if (which == "triple") {
        triplets();
        cout << "......." << endl;
    }
    else {
        cout << "using quantuplets.";
        quantiplets();
        /* refer to third paragraph of page 2 in textbook */
    }
}