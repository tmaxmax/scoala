#include <fstream>

constexpr static auto N = 100;

void read_graph(std::istream& in, bool graph[][N], bool directed) {
  for (int i, j; in >> i >> j;) {
    i--;
    j--;

    graph[i][j] = true;
    if (!directed) {
      graph[j][i] = true;
    }
  }
}

int shortest_path(const bool graph[][N], int size, int from, int to, int path[]) {
  bool visited[N]{};
  int queue[N], queue_start{}, queue_end{};
  int parents[N];

  queue[queue_start] = to;
  visited[to] = true;
  parents[to] = -1;

  while (queue_start <= queue_end) {
    const auto v = queue[queue_start++];

    for (auto i = 0; i < size; i++) {
      if (visited[i] || !graph[v][i]) {
        continue;
      }

      queue[++queue_end] = i;
      visited[i] = true;
      parents[i] = v;

      if (i == from) {
        goto save_path;
      }
    }
  }

save_path:
  auto path_length = 0;
  for (auto parent = from; parent != -1; parent = parents[parent]) {
    path[path_length++] = parent;
  }

  return path_length;
}

int main() {
  std::ifstream fin{"lantminim.in"};
  std::ofstream fout{"lantminim.out"};

  bool graph[N][N]{};
  int size, from, to;

  fin >> size >> from >> to;
  read_graph(fin, graph, false);

  int path[N];
  const auto path_length = shortest_path(graph, size, from - 1, to - 1, path);

  fout << path_length << '\n';
  for (auto i = 0; i < path_length; i++) {
    fout << path[i] + 1 << ' ';
  }
}
