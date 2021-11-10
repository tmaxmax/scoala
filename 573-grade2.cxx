#include <algorithm>
#include <iostream>

static const auto N = 100;

struct Grad {
  int exterior, interior;
};

int main() {
  int size, discard;
  std::cin >> size >> discard;

  Grad grade[N]{};

  for (int i, j; std::cin >> i >> j;) {
    grade[i - 1].exterior++;
    grade[j - 1].interior++;
  }

  const auto are_gradele_egale = [](Grad g) { return g.interior == g.exterior; };

  std::cout << std::count_if(grade, grade + size, are_gradele_egale) << '\n';

  for (auto i = 0; i < size; i++) {
    if (are_gradele_egale(grade[i])) {
      std::cout << i + 1 << ' ';
    }
  }
}
