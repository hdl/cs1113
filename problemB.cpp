#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;
double cal_average(vector<double> &nums){
    double result=0;
    int i=0;
    for(i=0; i<nums.size(); i++){
        result+=nums[i];
    }
    result=result/nums.size();
    return result;
}

double std_dev(vector<double> &nums, double average){
    double result=0;
    int i=0;
    for(i=0; i<nums.size(); i++)
        result = result + (nums[i]-average)*(nums[i]-average);
    result=result/nums.size();
    return sqrt(result);
}

double cal_range(std::vector<double> &nums){
    double max=nums[0];
    double min=nums[0];
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>max)
            max=nums[i];
        if(nums[i]<min)
            min=nums[i];
    }
    return max-min;
}

vector<double> read_file(string file_name){
    vector<double> nums;
    std::ifstream file(file_name);
    if(file.is_open()){
        double temp;
        while(file >> temp){
            nums.push_back(temp);
            //cout << "the nums is" << temp <<endl;
        }
    }else{
        cout<<"Error in reading file, quit!"<<endl;
        exit(0);
    }
    file.close();
    return nums;
}
int main(){

    string filename;
    cout << "Enter Input File name:";
    cin >> filename;

    std::vector<double> nums;

    nums = read_file(filename);
    double average = cal_average(nums);
    cout << "The average is "<<average<<endl;
    nums.clear();

    nums = read_file(filename);
    double dev = std_dev(nums, average);
    cout << "The Standard Deviation is "<<dev<<endl;
    nums.clear();

    nums = read_file(filename);
    double range = cal_range(nums);
    cout << "The Range of the Numbers  is "<<range<<endl;
    nums.clear();


    return 0;
}
