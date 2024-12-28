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

  const int loop = 1000;

  auto start = std::chrono::high_resolution_clock::now();
  int results_count = 0;

  for (int i = 0; i < loop; i++) {
    counter = 0;

    result = solve(board, __builtin_popcountll(board));
    if (result) {
      results_count++;
    }
  }
  auto end = std::chrono::high_resolution_clock::now();

  if (result) {
    for (const auto& solved_board : solved_boards) {
      if (__builtin_popcountll(solved_board)) {
        print_board(solved_board);
      }
    }
    std::cout << "Solved! " << results_count << std::endl;
  } else {
    std::cout << "Not solved!" << std::endl;
  }

  const auto loop_time =
      std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count() / loop;

  std::cout << "Time: " << loop_time << "ms" << std::endl;

  /*counter = 20279;*/
  std::cout << "Counter:" << counter << std::endl;
  std::cout << "Counter/ms: " << counter / loop_time << std::endl;

  return 0;
}