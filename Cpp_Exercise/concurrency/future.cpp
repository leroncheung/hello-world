#include <iostream>
#include <future>
#include <vector>
#include <numeric>

// template <typename T>
int getSum(std::vector<int>& nums) {
// int getSum() {
    int ans = std::accumulate(begin(nums), end(nums), 0);
    // int ans = 100;
    return ans;
}

std::ostream& operator<<(std::ostream& ostr, std::vector<int>& nums) {
    for(auto num : nums) {
        ostr << num << " ";
    }
    return ostr;
}

int main() {
    std::vector<int> nums(100);
    std::iota(begin(nums), end(nums), 1);
    std::cout << nums << std::endl;
    std::future<int> ans = std::async(getSum, std::ref(nums));
    // std::future<int> ans = std::async(getSum);
    std::cout << "Main thread!" << std::endl;
    std::cout << "Result: " << ans.get() << std::endl;

    return 0;
}