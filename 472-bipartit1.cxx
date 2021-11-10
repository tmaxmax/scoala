#include <fstream>

static const auto N = 15;

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

bool partition_graph(const bool graph[][N], int size, int partitions[]) {
  int queue[N], queue_start{}, queue_end{};

  queue[queue_end++] = 0;
  partitions[0] = 1;

  while (queue_start < queue_end) {
    const auto v = queue[queue_start++];

    for (auto i = 0; i < size; i++) {
      if (!graph[v][i]) {
        continue;
      }

      if (partitions[i] == 0) {
        queue[queue_end++] = i;
        partitions[i] = 3 - partitions[v];
      } else if (partitions[i] == partitions[v]) {
        return false;
      }
    }
  }

  return true;
}

void write_partition(std::ostream& out, int partitions[], int graph_size, int partition) {
  for (auto i = 0; i < graph_size; i++) {
    if (partitions[i] == partition) {
      out << i + 1 << ' ';
    }
  }
  out << '\n';
}

int main() {
  std::ifstream fin{"bipartit1.in"};
  std::ofstream fout{"bipartit1.out"};

  int size, discard;
  fin >> size >> discard;

  bool graph[N][N]{};
  read_graph(fin, graph, false);

  int partitions[N]{};

  if (partition_graph(graph, size, partitions)) {
    fout << "DA\n";
    write_partition(fout, partitions, size, 1);
    write_partition(fout, partitions, size, 2);
  } else {
    fout << "NU";
  }
}
