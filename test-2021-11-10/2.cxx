#include <fstream>

static const auto N = 100;

void citeste_graf(std::istream& in, bool graf[][N], int grade[]) {
  for (int i, j; in >> i >> j;) {
    i--;
    j--;

    graf[i][j] = graf[j][i] = true;
    grade[i]++;
    grade[j]++;
  }
}

int componenta_conexa(const bool graf[][N], int numar_varfuri, bool vizitate[], int start, int varfuri[]) {
  int c_inceput{}, c_sfarsit{};

  varfuri[c_sfarsit++] = start;
  vizitate[start] = true;

  while (c_inceput < c_sfarsit) {
    const auto v = varfuri[c_inceput++];

    for (auto i = 0; i < numar_varfuri; i++) {
      if (vizitate[i] || !graf[v][i]) {
        continue;
      }

      varfuri[c_sfarsit++] = i;
      vizitate[i] = true;
    }
  }

  return c_sfarsit;
}

int main() {
  std::ifstream fin{"graf2.in"};
  std::ofstream fout{"graf2.out"};

  int numar_varfuri;
  fin >> numar_varfuri;

  bool graf[N][N]{};
  int grade[N]{};
  citeste_graf(fin, graf, grade);

  // Cerinta 1: Gaseste numarul de componente conexe si componenta conexa minima

  bool vizitate[N]{};
  int varfuri_componenta_conexa_minima[N], numar_varfuri_componenta_conexa_minima{-1}, numar_componente_conexe{};

  for (auto i = 0; i < numar_varfuri; i++) {
    if (vizitate[i]) {
      continue;
    }

    int varfuri[N];
    const auto nr_varfuri = componenta_conexa(graf, numar_varfuri, vizitate, i, varfuri);
    numar_componente_conexe++;

    if (numar_varfuri_componenta_conexa_minima != -1 && numar_varfuri_componenta_conexa_minima <= nr_varfuri) {
      continue;
    }

    numar_varfuri_componenta_conexa_minima = nr_varfuri;
    for (auto j = 0; j < nr_varfuri; j++) {
      varfuri_componenta_conexa_minima[j] = varfuri[j];
    }
  }

  fout << numar_componente_conexe << '\n'
       << numar_varfuri_componenta_conexa_minima;
  for (auto i = 0; i < numar_varfuri_componenta_conexa_minima; i++) {
    fout << ' ' << varfuri_componenta_conexa_minima[i] + 1;
  }

  // Cerinta 2: numarul de muchii necesar pentru ca graful sa fie conex

  fout << '\n'
       << numar_componente_conexe - 1;

  // Cerinta 3: lista muchiilor care trebuie adaugata pentru ca graful sa fie complet

  for (auto i = 0; i < numar_varfuri; i++) {
    for (auto j = i + 1; j < numar_varfuri; j++) {
      if (graf[i][j]) {
        continue;
      }

      fout << '\n'
           << i + 1 << ' ' << j + 1;
    }
  }
}
