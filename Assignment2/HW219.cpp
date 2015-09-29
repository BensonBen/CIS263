#include <vector>
#include <iostream>
#include <tuple>

using namespace std;
class max_sub_sum{
private:
    std::vector <int> positions;
public:
    
    max_sub_sum(){
    }
    
    tuple<int, int, int> maxSumRec(const vector<int> a, int left, int right)
    {
        if(left == right)
            if(a[left]>0)
                return a[left];
        else
            return 0;
        
        
        int center = (left +right)/2;
        
        auto maxLeftSum = maxSumRec(a, left, center);
        
        auto maxRightSum = maxSumRec(a, center+1, right);
        
        int maxLeftBorderSum = 0, leftBorderSum = 0;
        
        tuple<int, int, int> temp;
        
        for(int i = center; i>=left; --i){
            leftBorderSum += a[i];
            if(leftBorderSum>maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
                temp = make_tuple(maxLeftBorderSum, i, left);
            }
        }
        
        int maxRightBorderSum = 0, rightBorderSum = 0;
        tuple<int, int, int> temp_tuple_right = NULL;
        
        for(int j = center+1; j<=right; ++j){
            
            rightBorderSum += a[j];
            
            if(rightBorderSum > maxRightBorderSum){
                
                maxRightBorderSum = rightBorderSum;
                
                temp_tuple_right= make_tuple(maxRightBorderSum, j, right);
            }
        }
        
        tuple<int, int, int> max_middle = tuple_finder(temp, temp_tuple_right);
    
        
        return max3(temp, temp_tuple_right, max_middle);
    }
    
    tuple <int, int, int>tuple_finder(tuple <int, int, int> left, tuple<int, int, int> right){
        int temp = get<0>(left) + get<0>(right);
        
        return make_tuple(temp, get<1>(left), get<1>(right));
    }
    
    void print(tuple<int, int, int> temp){
        cout << get<0>(temp)<<endl;
        cout << get<1>(temp)<<endl;
        cout<< get<2>(temp)<<"\n"<<endl;
    }
    
    tuple<int, int, int> max3(tuple<int, int, int> left, tuple<int, int, int> right, tuple<int, int, int> middle ){
        
        vector <tuple<int, int, int>> temp;
        
        temp.push_back(left);
        temp.push_back(right);
        temp.push_back(middle);
        
        tuple<int, int, int> t = temp.at(0);
        
        for(int i =0; i<temp.size(); ++i){
            if(get<0>(temp.at(i)) >= get<0>(t)){
                t = make_tuple(get<0>(temp.at(i)) ,get<1>(temp.at(i)) ,get<2>(temp.at(i)));
            }
        }
        
        return t;
    }
    
    
};

int main(){
    std::vector <int> hello = {10, -700000, 20, -39};
    max_sub_sum m;
    auto temp = m.maxSumRec(hello, 0, hello.size()-1);
    std::cout << std::to_string(get<0>(temp))<<endl;
    std::cout << std::to_string(get<1>(temp))<<endl;
    std::cout<< std::to_string(get<2>(temp))<<endl;
    return 0;
}