#include <bitset>
#include <chrono>
#include "src/FastPegSolitaire.hpp"

using namespace FastPegSolitaire;

int main(int argc, char* argv[]) {
  const auto board = get_english_board();

  print_board(board);
  std::cout << std::endl;

  const auto simple_board = get_one_move();
  print_board(simple_board);

  std::cout << std::endl;

  auto result = false;

  const int loop = 100;

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < loop; i++) {
    counter = 0;
    result = solve(board, __builtin_popcountll(board));
  }
  auto end = std::chrono::high_resolution_clock::now();

  if (result) {
    std::cout << "Solved!" << std::endl;
  } else {
    std::cout << "Not solved!" << std::endl;
  }

  const auto loop_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1.0 / loop;

  std::cout << "Time: " << loop_time << "ms" << std::endl;

  counter = 57394;
  std::cout << counter << std::endl;
  std::cout << "Counter/ms: " << counter / loop_time << std::endl;

  return 0;
}
