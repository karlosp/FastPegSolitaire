#include <array>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>

#include <vector>
namespace {
std::uint64_t p33 = 1ul << 32;
std::uint64_t p32 = 1ul << 31;
std::uint64_t p31 = 1ul << 30;
std::uint64_t p30 = 1ul << 29;
std::uint64_t p29 = 1ul << 28;
std::uint64_t p28 = 1ul << 27;
std::uint64_t p27 = 1ul << 26;
std::uint64_t p26 = 1ul << 25;
std::uint64_t p25 = 1ul << 24;
std::uint64_t p24 = 1ul << 23;
std::uint64_t p23 = 1ul << 22;
std::uint64_t p22 = 1ul << 21;
std::uint64_t p21 = 1ul << 20;
std::uint64_t p20 = 1ul << 19;
std::uint64_t p19 = 1ul << 18;
std::uint64_t p18 = 1ul << 17;
std::uint64_t p17 = 1ul << 16;
std::uint64_t p16 = 1ul << 15;
std::uint64_t p15 = 1ul << 14;
std::uint64_t p14 = 1ul << 13;
std::uint64_t p13 = 1ul << 12;
std::uint64_t p12 = 1ul << 11;
std::uint64_t p11 = 1ul << 10;
std::uint64_t p10 = 1ul << 9;
std::uint64_t p9 = 1ul << 8;
std::uint64_t p8 = 1ul << 7;
std::uint64_t p7 = 1ul << 6;
std::uint64_t p6 = 1ul << 5;
std::uint64_t p5 = 1ul << 4;
std::uint64_t p4 = 1ul << 3;
std::uint64_t p3 = 1ul << 2;
std::uint64_t p2 = 1ul << 1;
std::uint64_t p1 = 1ul << 0;

}  // namespace

namespace FastPegSolitaire {
std::uint64_t get_english_board() {
  // English board initial state (33-bit representation)
  return 0b111111111111111101111111111111111;  // One empty spot in the center
}

std::uint64_t get_one_move() {
  return 0b110001000000000000000000000000000;
}

inline std::vector<char> board_to_string(std::uint64_t board) {
  std::vector<char> result(33, '0');
  for (int i = 0; i < 33; i++) {
    if (board & (1UL << i)) {
      result[i] = 'X';
    }
  }

  return result;
}

inline void print_board(std::uint64_t board) {
  auto board_str = board_to_string(board);
  std::size_t index = 0u;

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if ((i < 2 || i > 4) && (j < 2 || j > 4)) {
        std::cout << " ";
      } else {
        std::cout << board_str[index];
        ++index;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

static const std::vector<std::pair<std::uint64_t, std::uint64_t>> can_moves{
    // Peg 33
    {p33 | p30, p33 | p30 | p25},  // 33 down
    {p33 | p32, p33 | p32 | p31},  // 33 right
    // Peg 32
    {p32 | p29, p32 | p29 | p24},  // 32 down
    // Peg 31
    {p31 | p32, p31 | p32 | p33},  // 31 left
    {p31 | p28, p31 | p28 | p23},  // 31 down
    // Peg 30
    {p30 | p25, p30 | p25 | p18},  // 30 down
    {p30 | p29, p30 | p29 | p28},  // 30 right
    // Peg 29
    {p29 | p24, p29 | p24 | p17},  // 29 down
    // Peg 28
    {p28 | p29, p28 | p29 | p30},  // 28 left
    {p28 | p23, p28 | p23 | p16},  // 28 down
    // Peg 27
    {p27 | p20, p27 | p20 | p13},  // 27 down
    {p27 | p26, p27 | p26 | p25},  // 27 right
    // Peg 26
    {p26 | p19, p26 | p19 | p12},  // 26 down
    {p26 | p25, p26 | p25 | p24},  // 26 right
    // Peg 25
    {p25 | p26, p25 | p26 | p27},  // 25 left
    {p25 | p18, p25 | p18 | p11},  // 25 down
    {p25 | p30, p25 | p30 | p33},  // 25 up
    {p25 | p24, p25 | p24 | p23},  // 25 right
    // Peg 24
    {p24 | p25, p24 | p25 | p26},  // 24 left
    {p24 | p17, p24 | p17 | p10},  // 24 down
    {p24 | p29, p24 | p29 | p32},  // 24 up
    {p24 | p23, p24 | p23 | p22},  // 24 right
    // Peg 23
    {p23 | p24, p23 | p24 | p25},  // 23 left
    {p23 | p16, p23 | p16 | p9},   // 23 down
    {p23 | p28, p23 | p28 | p31},  // 23 up
    {p23 | p22, p23 | p22 | p21},  // 23 right
    // Peg 22
    {p22 | p23, p22 | p23 | p24},  // 22 left
    {p22 | p15, p22 | p15 | p8},   // 22 down
    // Peg 21
    {p21 | p22, p21 | p22 | p23},  // 21 left
    {p21 | p14, p21 | p14 | p7},   // 21 down
    // Peg 20
    {p20 | p19, p20 | p19 | p18},  // 20 right
    // Peg 19
    {p19 | p18, p19 | p18 | p17},  // 19 right
    // Peg 18
    {p18 | p19, p18 | p19 | p20},  // 18 left
    {p18 | p11, p18 | p11 | p6},   // 18 down
    {p18 | p25, p18 | p25 | p30},  // 18 up
    {p18 | p17, p18 | p17 | p16},  // 18 right
    // Peg 17
    {p17 | p18, p17 | p18 | p19},  // 17 left
    {p17 | p10, p17 | p10 | p5},   // 17 down
    {p17 | p24, p17 | p24 | p29},  // 17 up
    {p17 | p16, p17 | p16 | p15},  // 17 right
    // Peg 16
    {p16 | p17, p16 | p17 | p18},  // 16 left
    {p16 | p9, p16 | p9 | p4},     // 16 down
    {p16 | p23, p16 | p23 | p28},  // 16 up
    {p16 | p15, p16 | p15 | p14},  // 16 right
    // Peg 15
    {p15 | p16, p15 | p16 | p17},  // 15 left
    // Peg 14
    {p14 | p15, p14 | p15 | p16},  // 14 left
    // Peg 13
    {p13 | p20, p13 | p20 | p27},  // 13 up
    {p13 | p12, p13 | p12 | p11},  // 13 right
    // Peg 12
    {p12 | p19, p12 | p19 | p26},  // 12 up
    {p12 | p11, p12 | p11 | p10},  // 12 right
    // Peg 11
    {p11 | p12, p11 | p12 | p13},  // 11 left
    {p11 | p6, p11 | p6 | p3},     // 11 down
    {p11 | p18, p11 | p18 | p25},  // 11 up
    {p11 | p10, p11 | p10 | p9},   // 11 right
    // Peg 10
    {p10 | p11, p10 | p11 | p12},  // 10 left
    {p10 | p5, p10 | p5 | p2},     // 10 down
    {p10 | p17, p10 | p17 | p24},  // 10 up
    {p10 | p9, p10 | p9 | p8},     // 10 right
    // Peg 9
    {p9 | p10, p9 | p10 | p11},  // 9 left
    {p9 | p4, p9 | p4 | p1},     // 9 down
    {p9 | p16, p9 | p16 | p23},  // 9 up
    {p9 | p8, p9 | p8 | p7},     // 9 right
    // Peg 8
    {p8 | p9, p8 | p9 | p10},    // 8 left
    {p8 | p15, p8 | p15 | p22},  // 8 up
    // Peg 7
    {p7 | p8, p7 | p8 | p9},     // 7 left
    {p7 | p14, p7 | p14 | p21},  // 7 up
    // Peg 6
    {p6 | p11, p6 | p11 | p18},  // 6 up
    {p6 | p5, p6 | p5 | p4},     // 6 right
    // Peg 5
    {p5 | p10, p5 | p10 | p17},  // 5 up
                                 // Peg 4
    {p4 | p5, p4 | p5 | p6},     // 4 left
    {p4 | p9, p4 | p9 | p16},    // 4 up
    // Peg 3
    {p3 | p6, p3 | p6 | p11},  // 3 up
    {p3 | p2, p3 | p2 | p1},   // 3 right
    // Peg 2
    {p2 | p5, p2 | p5 | p10},  // 2 up
    // Peg 1
    {p1 | p2, p1 | p2 | p3},  // 1 left
    {p1 | p4, p1 | p4 | p9},  // 1 up
};

std::uint64_t counter{};

std::array<std::uint64_t, 33> solved_boards;

bool solve(const std::uint64_t board, const std::size_t pegs) {
  ++counter;

  if (pegs == 1) {
    solved_boards[0] = board;
    return true;
  }

  for (const auto& can_move : can_moves) {
    const auto new_pegs = pegs - 1;
    if (((board ^ can_move.first) & can_move.second) == 0 && solve(board ^ can_move.second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }

  return false;
}
}  // namespace FastPegSolitaire
