#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print(T i) {
    cout << i << endl;
}

int main(int argc, char** argv)
{
    vector<string> nums;

    nums.push_back("one");
    nums.push_back("two");
    nums.push_back("three");
    nums.push_back("four");
    nums.push_back("five");

    vector<int> lengths;

    transform(nums.begin(), nums.end(), back_inserter(lengths), mem_fun_ref(&string::length));

    for_each(lengths.begin(), lengths.end(), print<int>);
}

