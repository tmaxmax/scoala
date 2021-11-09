#include <fstream>

template <std::size_t N>
void mul_mat(int result[][N], const int rhs[][N], int size) {
  for (auto i = 0U; i < size; i++) {
    int tmp[N]{};

    for (auto j = 0U; j < size; j++) {
      for (auto k = 0U; k < size; k++) {
        tmp[j] += result[i][k] * rhs[k][j];
      }
    }

    for (auto k = 0; k < size; k++) {
      result[i][k] = tmp[k];
    }
  }
};

template <std::size_t N>
void read_graph(std::istream& in, int mat[][N], bool directed) {
  for (int i, j; in >> i >> j;) {
    i--;
    j--;

    mat[i][j] = 1;
    if (!directed) {
      mat[j][i] = 1;
    }
  }

  if (!in.good() && !in.eof()) {
    throw "Bad stream";
  }
}

template <std::size_t M, std::size_t N>
void copy_mat(int result[][M], const int source[][N], int rows, int cols) {
  for (auto i = 0; i < rows; i++) {
    for (auto j = 0; j < cols; j++) {
      result[i][j] = source[i][j];
    }
  }
}

template <std::size_t N>
int shortest_path_length(const int graph[][N], int size, int from, int to) {
  int pow[N][N];
  copy_mat(pow, graph, size, size);

  for (auto l = 1; l < size; l++) {
    if (pow[from][to] > 0) {
      return l;
    }

    mul_mat(pow, graph, size);
  }

  return -1;
}

int main() {
  std::ifstream fin{"lantminim.in"};
  std::ofstream fout{"lantminim.out"};

  int size, from, to, graf[100][100]{};

  fin >> size >> from >> to;
  read_graph(fin, graf, false);

  fout << shortest_path_length(graf, size, from - 1, to - 1) + 1 << '\n';
}
