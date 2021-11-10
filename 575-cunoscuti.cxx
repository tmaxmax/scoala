#include <iostream>

static const auto N = 100;

int main() {
  int size, discard;
  std::cin >> size >> discard;

  int grade_interioare[N]{}, grad_maxim{};

  for (int i, j; std::cin >> i >> j;) {
    const auto grad = ++grade_interioare[j - 1];
    if (grad > grad_maxim) {
      grad_maxim = grad;
    }
  }

  for (auto i = 0; i < size; i++) {
    if (grade_interioare[i] == grad_maxim) {
      std::cout << i + 1 << ' ';
    }
  }
}
