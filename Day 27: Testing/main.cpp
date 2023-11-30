#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}
// DO NOT CHANGE CODE ABOVE

// Test for Empty Array
struct TestDataEmptyArray
{
    public:
        static vector<int> get_array()
        {
            return vector<int>{};
        }
};

// Test for Standard Array (no duplicates)
struct TestDataUniqueValues
{
    public:
        static int index;
        
        static vector<int> get_array()
        {
            return vector<int>{1, 2, 3};
        }
        
        static int get_expected_result()
        {
            return 0;
        }
};

// Test for Standard Array w/ Duplicates
struct TestDataExactlyTwoDifferentMinimums
{
    public:
        static vector<int> get_array()
        {
            return vector<int>{1, 2, 1};
        }
        
        static int get_expected_result()
        {
            return 0;
        }
};
// DO NOT CHANGE CODE BELOW

void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}
