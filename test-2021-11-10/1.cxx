#include <fstream>

static const auto N = 100;

int main() {
  std::ifstream fin{"graf1.in"};
  std::ofstream fout{"graf1.out"};

  int numar_varfuri;
  fin >> numar_varfuri;

  bool graf[N][N]{};
  int numar_muchii{}, grade[N]{}, grad_maxim{};

  for (int i, j; fin >> i >> j;) {
    i--;
    j--;

    graf[i][j] = graf[j][i] = true;
    numar_muchii++;

    grade[i]++;
    grade[j]++;
    grad_maxim = std::max(std::max(grad_maxim, grade[i]), grade[j]);
  }

  const auto este_muchie_de_eliminat = [&](int i, int j) {
    return i % 2 == 0 && grade[j] == grad_maxim;
  };

  for (auto i = 0; i < numar_varfuri; i++) {
    for (auto j = 0; j < numar_muchii; j++) {
      if (graf[i][j] && (este_muchie_de_eliminat(i, j) || este_muchie_de_eliminat(j, i))) {
        numar_muchii--;
        graf[i][j] = graf[j][i] = false;
      }
    }
  }

  fout << numar_muchii << '\n';
  for (auto i = 0; i < numar_varfuri; i++) {
    for (auto j = 0; j < numar_muchii; j++) {
      fout << graf[i][j] << ' ';
    }
    fout << '\n';
  }
}
