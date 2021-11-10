#include <iostream>

static const auto N = 100;

struct Grad {
  int exterior, interior;
};

int main() {
  int size, discard, suma_grade;
  std::cin >> size >> discard >> suma_grade;

  Grad grade[N]{};

  for (int i, j; std::cin >> i >> j;) {
    grade[i - 1].exterior++;
    grade[j - 1].interior++;
  }

  const auto are_suma_gradelor_ceruta = [suma_grade](Grad g) { return g.interior + g.exterior == suma_grade; };

  bool exista_grade_cu_suma_ceruta{};

  for (auto i = 0; i < size; i++) {
    if (!are_suma_gradelor_ceruta(grade[i])) {
      continue;
    }

    exista_grade_cu_suma_ceruta = true;
    std::cout << i + 1 << ' ';
  }

  if (!exista_grade_cu_suma_ceruta) {
    std::cout << "Nu exista";
  }
}
