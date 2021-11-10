#include <iostream>

static const auto N = 100;

int main() {
  int size, discard;
  std::cin >> size >> discard;

  int grade_interioare[N]{};

  for (int i, j; std::cin >> i >> j;) {
    grade_interioare[j - 1]++;
  }

  bool exista_grade_interioare_nule{};

  for (auto i = 0; i < size; i++) {
    if (grade_interioare[i] != 0) {
      continue;
    }

    exista_grade_interioare_nule = true;
    std::cout << i + 1 << ' ';
  }

  if (!exista_grade_interioare_nule) {
    std::cout << "NU EXISTA";
  }
}
