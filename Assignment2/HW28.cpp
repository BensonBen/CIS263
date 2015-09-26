//
//  RunTime.cpp
//  CIS_343_Assignment2
//
//  Created by Benjamin J. Benson and Matt Noblett and Michael K on 9/23/15.
//  Copyright (c) 2015 Benjamin J. Benson. All rights reserved.
//
#include <chrono>
#include <ctime>
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
bool b_array[400000];


//Second interpretation of algorithm 2.
vector <int> alg_two;
vector <int> used_array;


//used as a place holder for the array in algorithm 2.
int i =0;

//Used to satisfy Algorithm 3.
vector <int> integer_array;

/*************************************************
 * Checks if a position in the array has beenc
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
    
    //    cout << "Starting algorithm 1."<<endl;
    //    /************************************
    //     * Algorithm 1.
    //     ***********************************/
    //    chrono::time_point<chrono::system_clock> start, end;
    //    start = chrono::system_clock::now();
    //
    //    for(int i =0; i<10; ++i){
    //        generate_alg_one(2000);
    //        for(auto c = alg_one.begin(); c!=alg_one.end(); ++c){
    //            cout << to_string(*c)<<endl;
    //        }
    //        alg_one.clear();
    //    }
    //
    //    end = chrono::system_clock::now();
    //    chrono::duration<double> elapse = (end - start)/10;
    //    cout << "Elapse time is " << elapse.count() << endl;
    
    
    //    cout << "Starting Algorithm 2. ";
    //    chrono::time_point<chrono::system_clock> start, end;
    //    start = chrono::system_clock::now();
    //
    //    /*************************************
    //     * Algorithm 2
    //     *************************************/
    //    while(is_used()==false){
    //        int rand = random()%400000;
    //        if(b_array[rand]==false){
    //            i_array.push_back(rand+1);
    //            ++i;
    //            b_array[rand]=true;
    //        }
    //    }
    //
    //    end = chrono::system_clock::now();
    //    chrono::duration<double> elapse = (end - start);
    //    cout << "Elapse time is " << elapse.count() << endl;
    
    
    //    /**************************************
    //     * Algorithm 2.1
    //     **************************************/
    //    initliaze_int_arr(10, &used_array);
    //    //   alg_two_point_one();
    //
    cout << "Starting Algorithm 3. ";
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    
    /*************************************
     * Algorithm 3.
     ************************************/
    for(int i = 0; i< 10; ++i){
        initliaze_int_arr(6400000, &integer_array);
        
        for(int i =1; i<integer_array.size(); ++i){
            swap(integer_array[i], integer_array[randInt(i)]);
        }
        integer_array.clear();
    }
    end = chrono::system_clock::now();
    chrono::duration<double> elapse = (end - start)/10;
    cout << "Elapse time is " << elapse.count() << endl;
    
    return 0;
}

//2.8 b)
/*******************************************************************************
 * algorithm 1 has a run time of best case O(n) and worst case O (x    infinity)
 *                                                                   ->
 * algorithm 2 has a run time of best case O(n) worst case O(x  infinity)
 *                                                            ->
 * algorithm 3 has a run time of O(n)
 *******************************************************************************/

//2.8 c)
/***************************************************************
 * Algorithm 1 run times:
 * n = 250: Starting algorithm 1. Elapse time is 0.001175
 * n = 500: Starting algorithm 1. Elapse time is 0.005677
 * n = 1000: Starting algorithm 1. Elapse time is 0.028052
 * n = 2000: Starting algorithm 1. Elapse time is 0.115673
 * Algorithm 2 run times:
 * n = 25,000: Starting Algorithm 2. Elapse time is 0.239192
 * n = 50,000: Starting Algorithm 2. Elapse time is 0.767564
 * n = 100,000: Starting Algorithm 2. Elapse time is 1.41248
 * n = 200,000: Starting Algorithm 2. Elapse time is 243.898
 * n = 400,000:  Starting Algorithm 2. Elapse time is 825.783
 * n = 800,000: Starting Algorithm 2. Elapse time is ALOT.
 * Algorithm 3 run times:
 * n = 100,000: Starting Algorithm 3. Elapse time is 0.0077633
 * n = 200,000: Starting Algorithm 3. Elapse time is 0.015253
 * n = 400,000: Starting Algorithm 3. Elapse time is 0.031481
 * n = 800,000: Starting Algorithm 3. Elapse time is 0.067472
 * n = 1,600,000: Starting Algorithm 3. Elapse time is 0.160693
 * n = 3,200,000: Starting Algorithm 3. Elapse time is 0.355092
 * n = 6,400,000: Starting Algorithm 3. Elapse time is 0.75582
 ***************************************************************/

//2.8 d)
/**************************************************************
 * Algorithm 1 analysis, every time n doubles, the run time
 * increases by 5x - 6x.
 *
 * Algorithm 2 analysis, every time n increases the time increases
 * exponentially somewhere on the order of some constant raised
 * to the power of n elements.
 *
 * Algorithm 3 analysis, every time n elements doubles the time
 * elapsed doubles. So we can assume that the algorithm runs
 * on the order of n O(n).
 ***************************************************************/

//2.8 e)
/**************************************************************
 * The worst case run time is c^n for algorithm 1.
 *
 * The worst case run time is c^n for algorithm 2.
 *
 * The worst case run time is O(n) for algorithm 3.
 *************************************************************/
