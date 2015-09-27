//
//  HW219.cpp
//  Max_Subsequence
//
//  Created by Benjamin J. Benson on 9/27/15.
//  Copyright (c) 2015 Benjamin J. Benson. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;
class max_sub_sum{
private:
    std::vector <int> positions;
public:
    
    max_sub_sum(){
        cout<<"fuck this shit."<<endl;
    }
    
    int maxSumRec(const std::vector<int> a, int left, int right)
    {
        if(left == right)
            if(a[left]>0)
                return a[left];
        else
            return 0;
    
        
        int center = (left +right)/2;
        int maxLeftSum = maxSumRec(a, left, center);
        int maxRightSum = maxSumRec(a, center+1, right);
        
        int maxLeftBorderSum = 0, leftBorderSum = 0;
        for(int i = center; i>=left; --i){
            leftBorderSum += a[i];
            if(leftBorderSum>maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }
        
        int maxRightBorderSum = 0, rightBorderSum = 0;
        for(int j = center+1; j<=right; ++j){
            rightBorderSum += a[j];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        
        return max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
    }
    
    int max3(int maxLeftSum, int maxRightSum, int borderSum){
        int result = 0;
        if(maxLeftSum >= maxRightSum){
            result = maxLeftSum;
        }
        if(maxLeftSum >= borderSum){
            result = maxLeftSum;
        }
        if(maxRightSum >= maxLeftSum){
            result = maxRightSum;
        }
        if(maxRightSum >=borderSum){
            result = maxRightSum;
        }
        if(borderSum >= maxRightSum){
            result = borderSum;
        }
        if(borderSum >= maxLeftSum){
            result = borderSum;
        }
        return result;
    }
    
    
};




int main(){
    std::vector <int> hello = {10, -10000, 20, 40, -39};
    max_sub_sum m;
    int temp = m.maxSumRec(hello, 0, hello.size()-1);
    std::cout << std::to_string(temp);
    return 0;
}
