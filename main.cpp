#include <chrono>
#include "src/FastPegSolitaire.hpp"

using namespace FastPegSolitaire;

int main(int argc, char* argv[]) {
  auto board = get_english_board();
  /*board = get_diamond_board();*/
  const auto peg_count = __builtin_popcountll(board);

  print_board(board);
  auto result = false;

  const int loop = 1000;

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < loop; i++) {
    counter = 0;

    count_empty = 0;
    result = solve(board, peg_count);
  }
  auto end = std::chrono::high_resolution_clock::now();

  if (result) {
    for (const auto& solved_board : solved_boards) {
      const auto peg_count = __builtin_popcountll(solved_board);
      if (peg_count) {
        std::cout << "Pegs: " << peg_count << std::endl;
        print_board(solved_board);
      }
    }
    std::cout << "Solved! " << std::endl;
  } else {
    std::cout << "Not solved!" << std::endl;
  }

  const auto loop_time =
      std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count() / loop;

  std::cout << "Time: " << loop_time << "ms" << std::endl;

  /*counter = 20279;*/
  std::cout << "Counter:" << counter << std::endl;
  std::cout << "Counter/ms: " << counter / loop_time << std::endl;
  std::cout << "Count empty: " << count_empty << std::endl;

  /*const auto simple = get_one_move();*/
  /*print_board(simple);*/
  /*print_board(rotate_empty_corner_180(simple));*/

  return 0;
}
