#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

  std::cout << "原始数据";
  std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });
  std::cout << std::endl;

  auto it =
      std::find_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });
  if (it != nums.end()) {
    std::cout << "第一个偶数：" << *it << "（索引："
              << std::distance(nums.begin(), it) << "）" << std::endl;
  }

  int cnt =
      std::count_if(nums.begin(), nums.end(), [](int n) { return n > 4; });
  std::cout << "大于4的元素个数：" << cnt << std::endl;

  std::vector<int> squared(nums.size());
  std::transform(nums.begin(), nums.end(), squared.begin(),
                 [](int n) { return n * n; });
  std::cout << "平方后：";
  for (int n : squared)
    std::cout << n << " ";
  std::cout << std::endl;

  bool hasNeg =
      std::any_of(nums.begin(), nums.end(), [](int n) { return n < 0; });
  bool allPos =
      std::all_of(nums.begin(), nums.end(), [](int n) { return n > 0; });
  std::cout << "\n存在负数：" << std::boolalpha << hasNeg << std::endl;
  std::cout << "全部为正：" << std::boolalpha << allPos << std::endl;

  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  std::cout << "元素总和：" << sum << std::endl;

  std::vector<int> unique_nums = nums;
  std::sort(unique_nums.begin(), unique_nums.end());
  unique_nums.erase(std::unique(unique_nums.begin(), unique_nums.end()),
                    unique_nums.end());
  std::cout << "去重后：";
  for (int n : unique_nums)
    std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}
