//
//  RunTime.cpp
//  CIS_343_Assignment2
//
//  Created by Benjamin J. Benson on 9/23/15.
//  Copyright (c) 2015 Benjamin J. Benson. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <array>
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

//Used in algorithm 1.
vector <int> alg_one;

//used to insert the integers into from algorithm 2
vector<int> i_array;
//used to satisfy the boolean conditions from algorithm 2.
bool b_array[9];


//Second interpretation of algorithm 2.
vector <int> alg_two;
vector <int> used_array;


//used as a place holder for the array in algorithm 2.
int i =0;

//Used to satisfy Algorithm 3.
vector <int> integer_array;

/*************************************************
 * Checks if a position in the array has been
 * taken already. Used in Algorithm 1.
 ************************************************/
bool check_list(int num){
    for(int i =0; i<alg_one.size();++i){
        if(num == alg_one.at(i)){
            return false;
        }
    }
    return true;
}

/*****************************************************
 * Populates an array with uniform random numbers.
 * Algorithm 1.
 *****************************************************/
 void generate_alg_one(int size){
    int i = 0;
     while(i<size){
         int rand = (random()%size);
         if(check_list(rand)){
             alg_one.push_back(rand);
             ++i;
         }
     }
}

/******************************************************
 * initiliazes the array used in algorithm 3, and 2.1
 * n is the number of elements put into the array.
 ******************************************************/
void initliaze_int_arr(int n, vector <int> *nums){
    int i=0;
    while(i<n){
        nums->push_back(i);
        ++i;
    }
}

/*****************************************************
 * Used in algorithm 3 to return a random number
 * from 0 till the ceiling provided.
 ****************************************************/
int randInt(int ceiling){
    return random()%ceiling;
}

/***************************************************
 * Used in algorithm 2 to check if all values of
 * the b_array have are taken. Meaning set to true.
 ***************************************************/
bool is_used(){
    for(int i =0; i<sizeof b_array ; i++){
        if(b_array[i]==false){
            return false;
        }
    }
    return true;
}


int main() {
//We chose to use a vector for the integer array because, they're more elegant and modern.
// (;-)
    
    cout << "Starting algorithm 1."<<endl;
    /************************************
     * Algorithm 1.
     ***********************************/
    generate_alg_one(10);
    for(auto c = alg_one.begin(); c!=alg_one.end(); ++c){
        cout << to_string(*c)<<endl;
    }
    alg_one.clear();
    
    /*************************************
     * Algorithm 2
     *************************************/
    while(is_used()==false){
        int rand = random()%10;
        if(b_array[rand]==false){
            i_array.push_back(rand+1);
            ++i;
            b_array[rand]=true;
        }
    }
    
    /**************************************
     * Algorithm 2.1
     **************************************/
    initliaze_int_arr(10, &used_array);
 //   alg_two_point_one();
    
    /*************************************
     * Algorithm 3.
     ************************************/
    initliaze_int_arr(10, &integer_array);
    for(int i =1; i<integer_array.size(); ++i){
        swap(integer_array[i], integer_array[randInt(i)]);
    }
    
    return 0;
}

//2.8 b)
/***********************************************************************
* algorithm 1 has a run time of best case O(n) and worst case O(infinity)
* algorithm 2 has a run time of best case O(n) worst case O(infinity)
* algorithm 2.1 (2nd interpretation.)
* algorithm 3 has a run time of O(n)
***********************************************************************/

//2.8 c)
/***************************************************************
 * Algorithm 1 run times:
 * n = 250: Ran 250 times.
 * n = 500: Ran 500 times.
 * n = 1000: Ran 1000 times.
 * n = 2000: Ran 2000 times.
 * Algorithm 2 run times: 
 * n = 25,000: Ran 625,000,000
 * n = 50,000: Ran
 ***************************************************************/



