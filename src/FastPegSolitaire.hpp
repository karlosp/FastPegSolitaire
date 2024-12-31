#include <array>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <utility>

namespace {
constexpr std::uint64_t p33 = 1ul << 32;
constexpr std::uint64_t p32 = 1ul << 31;
constexpr std::uint64_t p31 = 1ul << 30;
constexpr std::uint64_t p30 = 1ul << 29;
constexpr std::uint64_t p29 = 1ul << 28;
constexpr std::uint64_t p28 = 1ul << 27;
constexpr std::uint64_t p27 = 1ul << 26;
constexpr std::uint64_t p26 = 1ul << 25;
constexpr std::uint64_t p25 = 1ul << 24;
constexpr std::uint64_t p24 = 1ul << 23;
constexpr std::uint64_t p23 = 1ul << 22;
constexpr std::uint64_t p22 = 1ul << 21;
constexpr std::uint64_t p21 = 1ul << 20;
constexpr std::uint64_t p20 = 1ul << 19;
constexpr std::uint64_t p19 = 1ul << 18;
constexpr std::uint64_t p18 = 1ul << 17;
constexpr std::uint64_t p17 = 1ul << 16;
constexpr std::uint64_t p16 = 1ul << 15;
constexpr std::uint64_t p15 = 1ul << 14;
constexpr std::uint64_t p14 = 1ul << 13;
constexpr std::uint64_t p13 = 1ul << 12;
constexpr std::uint64_t p12 = 1ul << 11;
constexpr std::uint64_t p11 = 1ul << 10;
constexpr std::uint64_t p10 = 1ul << 9;
constexpr std::uint64_t p9 = 1ul << 8;
constexpr std::uint64_t p8 = 1ul << 7;
constexpr std::uint64_t p7 = 1ul << 6;
constexpr std::uint64_t p6 = 1ul << 5;
constexpr std::uint64_t p5 = 1ul << 4;
constexpr std::uint64_t p4 = 1ul << 3;
constexpr std::uint64_t p3 = 1ul << 2;
constexpr std::uint64_t p2 = 1ul << 1;
constexpr std::uint64_t p1 = 1ul << 0;

/*constexpr std::uint32_t pr33 = 1ul << 32;*/
constexpr std::uint32_t pr32 = 1ul << 31;
constexpr std::uint32_t pr31 = 1ul << 30;
constexpr std::uint32_t pr30 = 1ul << 29;
constexpr std::uint32_t pr29 = 1ul << 28;
constexpr std::uint32_t pr28 = 1ul << 27;
constexpr std::uint32_t pr27 = 1ul << 26;
constexpr std::uint32_t pr26 = 1ul << 25;
constexpr std::uint32_t pr25 = 1ul << 24;
constexpr std::uint32_t pr24 = 1ul << 23;
constexpr std::uint32_t pr23 = 1ul << 22;
constexpr std::uint32_t pr22 = 1ul << 21;
constexpr std::uint32_t pr21 = 1ul << 20;
constexpr std::uint32_t pr20 = 1ul << 19;
constexpr std::uint32_t pr19 = 1ul << 18;
constexpr std::uint32_t pr18 = 1ul << 17;
constexpr std::uint32_t pr17 = 1ul << 16;
constexpr std::uint32_t pr16 = 1ul << 15;
constexpr std::uint32_t pr15 = 1ul << 14;
constexpr std::uint32_t pr14 = 1ul << 13;
constexpr std::uint32_t pr13 = 1ul << 12;
constexpr std::uint32_t pr12 = 1ul << 11;
constexpr std::uint32_t pr11 = 1ul << 10;
constexpr std::uint32_t pr10 = 1ul << 9;
constexpr std::uint32_t pr9 = 1ul << 8;
constexpr std::uint32_t pr8 = 1ul << 7;
constexpr std::uint32_t pr7 = 1ul << 6;
constexpr std::uint32_t pr6 = 1ul << 5;
constexpr std::uint32_t pr5 = 1ul << 4;
constexpr std::uint32_t pr4 = 1ul << 3;
constexpr std::uint32_t pr3 = 1ul << 2;
constexpr std::uint32_t pr2 = 1ul << 1;
constexpr std::uint32_t pr1 = 1ul << 0;

}  // namespace

namespace FastPegSolitaire {
constexpr std::uint64_t get_english_board() {
  // English board initial state (33-bit representation)
  return 0b111111111111111101111111111111111;  // One empty spot in the center
}

constexpr std::uint64_t get_diamond_board() {
  // English board initial state (33-bit representation)
  return 0b010111011111011101110111110111010;  // One empty spot in the center
}

std::uint64_t get_one_move() {
  return 0b000011000000000000000000000000000;
}

std::uint64_t rotate_empty_corner_180(std::uint64_t board) {
  std::bitset<64> bits(board);

  std::bitset<64> result;

  result.set(28, bits.test(4));
  result.set(27, bits.test(5));
  result.set(26, bits.test(6));
  result.set(25, bits.test(7));
  result.set(24, bits.test(8));
  result.set(23, bits.test(9));
  result.set(22, bits.test(10));
  result.set(21, bits.test(11));
  result.set(20, bits.test(12));
  result.set(19, bits.test(13));
  result.set(18, bits.test(14));
  result.set(17, bits.test(15));
  result.set(16, bits.test(16));
  result.set(15, bits.test(17));
  result.set(14, bits.test(18));
  result.set(13, bits.test(19));
  result.set(12, bits.test(20));
  result.set(11, bits.test(21));
  result.set(10, bits.test(22));
  result.set(9, bits.test(23));
  result.set(8, bits.test(24));
  result.set(7, bits.test(25));
  result.set(6, bits.test(26));
  result.set(5, bits.test(27));
  result.set(4, bits.test(28));

  return result.to_ulong();
}

constexpr inline std::array<char, 33> board_to_string(std::uint64_t board) {
  std::array<char, 33> result{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                              '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

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

constexpr const std::array<std::pair<std::uint64_t, std::uint64_t>, 76> can_moves{
    // Peg 33
    std::pair<std::uint64_t, std::uint64_t>{p33 | p30, p33 | p30 | p25},  // 33 down
    {p33 | p32, p33 | p32 | p31},                                         // 33 right
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
    {p4 | p5, p4 | p5 | p6},   // 4 left
    {p4 | p9, p4 | p9 | p16},  // 4 up
    // Peg 3
    {p3 | p6, p3 | p6 | p11},  // 3 up
    {p3 | p2, p3 | p2 | p1},   // 3 right
    // Peg 2
    {p2 | p5, p2 | p5 | p10},  // 2 up
    // Peg 1
    {p1 | p2, p1 | p2 | p3},  // 1 left
    {p1 | p4, p1 | p4 | p9}   // 1 up
};

constexpr const std::array<std::pair<std::uint32_t, std::uint32_t>, 72> can_moves_32{
    // Peg 33
    /*std::pair<std::uint32_t, std::uint32_t>{pr33 | pr30, pr33 | pr30 | pr25},  // 33 down*/
    /*{pr33 | pr32, pr33 | pr32 | pr31},                                         // 33 right*/
    // Peg 32
    std::pair<std::uint32_t, std::uint32_t>{pr32 | pr29, pr32 | pr29 | pr24},  // 32 down
    // Peg 31
    /*{pr31 | pr32, pr31 | pr32 | pr33},  // 31 left*/
    {pr31 | pr28, pr31 | pr28 | pr23},  // 31 down
    // Peg 30
    {pr30 | pr25, pr30 | pr25 | pr18},  // 30 down
    {pr30 | pr29, pr30 | pr29 | pr28},  // 30 right
    // Peg 29
    {pr29 | pr24, pr29 | pr24 | pr17},  // 29 down
    // Peg 28
    {pr28 | pr29, pr28 | pr29 | pr30},  // 28 left
    {pr28 | pr23, pr28 | pr23 | pr16},  // 28 down
    // Peg 27
    {pr27 | pr20, pr27 | pr20 | pr13},  // 27 down
    {pr27 | pr26, pr27 | pr26 | pr25},  // 27 right
    // Peg 26
    {pr26 | pr19, pr26 | pr19 | pr12},  // 26 down
    {pr26 | pr25, pr26 | pr25 | pr24},  // 26 right
    // Peg 25
    {pr25 | pr26, pr25 | pr26 | pr27},  // 25 left
    {pr25 | pr18, pr25 | pr18 | pr11},  // 25 down
    /*{pr25 | pr30, pr25 | pr30 | pr33},  // 25 up*/
    {pr25 | pr24, pr25 | pr24 | pr23},  // 25 right
    // Peg 24
    {pr24 | pr25, pr24 | pr25 | pr26},  // 24 left
    {pr24 | pr17, pr24 | pr17 | pr10},  // 24 down
    {pr24 | pr29, pr24 | pr29 | pr32},  // 24 up
    {pr24 | pr23, pr24 | pr23 | pr22},  // 24 right
    // Peg 23
    {pr23 | pr24, pr23 | pr24 | pr25},  // 23 left
    {pr23 | pr16, pr23 | pr16 | pr9},   // 23 down
    {pr23 | pr28, pr23 | pr28 | pr31},  // 23 up
    {pr23 | pr22, pr23 | pr22 | pr21},  // 23 right
    // Peg 22
    {pr22 | pr23, pr22 | pr23 | pr24},  // 22 left
    {pr22 | pr15, pr22 | pr15 | pr8},   // 22 down
    // Peg 21
    {pr21 | pr22, pr21 | pr22 | pr23},  // 21 left
    {pr21 | pr14, pr21 | pr14 | pr7},   // 21 down
    // Peg 20
    {pr20 | pr19, pr20 | pr19 | pr18},  // 20 right
    // Peg 19
    {pr19 | pr18, pr19 | pr18 | pr17},  // 19 right
    // Peg 18
    {pr18 | pr19, pr18 | pr19 | pr20},  // 18 left
    {pr18 | pr11, pr18 | pr11 | pr6},   // 18 down
    {pr18 | pr25, pr18 | pr25 | pr30},  // 18 up
    {pr18 | pr17, pr18 | pr17 | pr16},  // 18 right
    // Peg 17
    {pr17 | pr18, pr17 | pr18 | pr19},  // 17 left
    {pr17 | pr10, pr17 | pr10 | pr5},   // 17 down
    {pr17 | pr24, pr17 | pr24 | pr29},  // 17 up
    {pr17 | pr16, pr17 | pr16 | pr15},  // 17 right
    // Peg 16
    {pr16 | pr17, pr16 | pr17 | pr18},  // 16 left
    {pr16 | pr9, pr16 | pr9 | pr4},     // 16 down
    {pr16 | pr23, pr16 | pr23 | pr28},  // 16 up
    {pr16 | pr15, pr16 | pr15 | pr14},  // 16 right
    // Peg 15
    {pr15 | pr16, pr15 | pr16 | pr17},  // 15 left
    // Peg 14
    {pr14 | pr15, pr14 | pr15 | pr16},  // 14 left
    // Peg 13
    {pr13 | pr20, pr13 | pr20 | pr27},  // 13 up
    {pr13 | pr12, pr13 | pr12 | pr11},  // 13 right
    // Peg 12
    {pr12 | pr19, pr12 | pr19 | pr26},  // 12 up
    {pr12 | pr11, pr12 | pr11 | pr10},  // 12 right
    // Peg 11
    {pr11 | pr12, pr11 | pr12 | pr13},  // 11 left
    {pr11 | pr6, pr11 | pr6 | pr3},     // 11 down
    {pr11 | pr18, pr11 | pr18 | pr25},  // 11 up
    {pr11 | pr10, pr11 | pr10 | pr9},   // 11 right
    // Peg 10
    {pr10 | pr11, pr10 | pr11 | pr12},  // 10 left
    {pr10 | pr5, pr10 | pr5 | pr2},     // 10 down
    {pr10 | pr17, pr10 | pr17 | pr24},  // 10 up
    {pr10 | pr9, pr10 | pr9 | pr8},     // 10 right
    // Peg 9
    {pr9 | pr10, pr9 | pr10 | pr11},  // 9 left
    {pr9 | pr4, pr9 | pr4 | pr1},     // 9 down
    {pr9 | pr16, pr9 | pr16 | pr23},  // 9 up
    {pr9 | pr8, pr9 | pr8 | pr7},     // 9 right
    // Peg 8
    {pr8 | pr9, pr8 | pr9 | pr10},    // 8 left
    {pr8 | pr15, pr8 | pr15 | pr22},  // 8 up
    // Peg 7
    {pr7 | pr8, pr7 | pr8 | pr9},     // 7 left
    {pr7 | pr14, pr7 | pr14 | pr21},  // 7 up
    // Peg 6
    {pr6 | pr11, pr6 | pr11 | pr18},  // 6 up
    {pr6 | pr5, pr6 | pr5 | pr4},     // 6 right
    // Peg 5
    {pr5 | pr10, pr5 | pr10 | pr17},  // 5 up
    // Peg 4
    {pr4 | pr5, pr4 | pr5 | pr6},   // 4 left
    {pr4 | pr9, pr4 | pr9 | pr16},  // 4 up
    // Peg 3
    {pr3 | pr6, pr3 | pr6 | pr11},  // 3 up
    {pr3 | pr2, pr3 | pr2 | pr1},   // 3 right
    // Peg 2
    {pr2 | pr5, pr2 | pr5 | pr10},  // 2 up
    // Peg 1
    {pr1 | pr2, pr1 | pr2 | pr3},  // 1 left
    {pr1 | pr4, pr1 | pr4 | pr9}   // 1 up
};

std::uint64_t counter{};

std::array<std::uint64_t, 32> solved_boards{0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
                                            0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul,
                                            0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul, 0ul};
int count_empty = 0;

bool solve32(const std::uint32_t board, const std::size_t pegs) {
  ++counter;

  if (pegs == 1) {
    solved_boards[0] = board;
    return true;
  }

  const auto new_pegs = pegs - 1;
  if (((board & can_moves_32[0].second) == can_moves_32[0].first) &&
      solve32(board ^ can_moves_32[0].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[1].second) == can_moves_32[1].first) &&
      solve32(board ^ can_moves_32[1].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (board & 0b001110000000000000000) {
    ++count_empty;
    if (((board & can_moves_32[2].second) == can_moves_32[2].first) &&
        solve32(board ^ can_moves_32[2].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[3].second) == can_moves_32[3].first) &&
        solve32(board ^ can_moves_32[3].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[4].second) == can_moves_32[4].first) &&
        solve32(board ^ can_moves_32[4].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[5].second) == can_moves_32[5].first) &&
        solve32(board ^ can_moves_32[5].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[6].second) == can_moves_32[6].first) &&
        solve32(board ^ can_moves_32[6].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 30, 29, 28
  if (((board & can_moves_32[7].second) == can_moves_32[7].first) &&
      solve32(board ^ can_moves_32[7].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[8].second) == can_moves_32[8].first) &&
      solve32(board ^ can_moves_32[8].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[9].second) == can_moves_32[9].first) &&
      solve32(board ^ can_moves_32[9].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[10].second) == can_moves_32[10].first) &&
      solve32(board ^ can_moves_32[10].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  // Peg 25
  if ((board & pr25)) {
    if (((board & can_moves_32[11].second) == can_moves_32[11].first) &&
        solve32(board ^ can_moves_32[11].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[12].second) == can_moves_32[12].first) &&
        solve32(board ^ can_moves_32[12].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[13].second) == can_moves_32[13].first) &&
        solve32(board ^ can_moves_32[13].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }
  if ((board & pr24)) {
    if (((board & can_moves_32[14].second) == can_moves_32[14].first) &&
        solve32(board ^ can_moves_32[14].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[15].second) == can_moves_32[15].first) &&
        solve32(board ^ can_moves_32[15].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[16].second) == can_moves_32[16].first) &&
        solve32(board ^ can_moves_32[16].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[17].second) == can_moves_32[17].first) &&
        solve32(board ^ can_moves_32[17].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 24
  if ((board & pr23)) {
    if (((board & can_moves_32[18].second) == can_moves_32[18].first) &&
        solve32(board ^ can_moves_32[18].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[19].second) == can_moves_32[19].first) &&
        solve32(board ^ can_moves_32[19].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[20].second) == can_moves_32[20].first) &&
        solve32(board ^ can_moves_32[20].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[21].second) == can_moves_32[21].first) &&
        solve32(board ^ can_moves_32[21].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 23
  if (((board & can_moves_32[22].second) == can_moves_32[22].first) &&
      solve32(board ^ can_moves_32[22].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[23].second) == can_moves_32[23].first) &&
      solve32(board ^ can_moves_32[23].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[24].second) == can_moves_32[24].first) &&
      solve32(board ^ can_moves_32[24].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[25].second) == can_moves_32[25].first) &&
      solve32(board ^ can_moves_32[25].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[26].second) == can_moves_32[26].first) &&
      solve32(board ^ can_moves_32[26].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[27].second) == can_moves_32[27].first) &&
      solve32(board ^ can_moves_32[27].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if ((board & pr18)) {
    if (((board & can_moves_32[28].second) == can_moves_32[28].first) &&
        solve32(board ^ can_moves_32[28].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[29].second) == can_moves_32[29].first) &&
        solve32(board ^ can_moves_32[29].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[30].second) == can_moves_32[30].first) &&
        solve32(board ^ can_moves_32[30].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[31].second) == can_moves_32[31].first) &&
        solve32(board ^ can_moves_32[31].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 18
  if ((board & pr17)) {
    if (((board & can_moves_32[32].second) == can_moves_32[32].first) &&
        solve32(board ^ can_moves_32[32].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[33].second) == can_moves_32[33].first) &&
        solve32(board ^ can_moves_32[33].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[34].second) == can_moves_32[34].first) &&
        solve32(board ^ can_moves_32[34].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[35].second) == can_moves_32[35].first) &&
        solve32(board ^ can_moves_32[35].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 17
  if ((board & pr16)) {
    if (((board & can_moves_32[36].second) == can_moves_32[36].first) &&
        solve32(board ^ can_moves_32[36].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[37].second) == can_moves_32[37].first) &&
        solve32(board ^ can_moves_32[37].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[38].second) == can_moves_32[38].first) &&
        solve32(board ^ can_moves_32[38].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[39].second) == can_moves_32[39].first) &&
        solve32(board ^ can_moves_32[39].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 16
  if (((board & can_moves_32[40].second) == can_moves_32[40].first) &&
      solve32(board ^ can_moves_32[40].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[41].second) == can_moves_32[41].first) &&
      solve32(board ^ can_moves_32[41].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[42].second) == can_moves_32[42].first) &&
      solve32(board ^ can_moves_32[42].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[43].second) == can_moves_32[43].first) &&
      solve32(board ^ can_moves_32[43].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[44].second) == can_moves_32[44].first) &&
      solve32(board ^ can_moves_32[44].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[45].second) == can_moves_32[45].first) &&
      solve32(board ^ can_moves_32[45].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if ((board & pr11)) {
    if (((board & can_moves_32[46].second) == can_moves_32[46].first) &&
        solve32(board ^ can_moves_32[46].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[47].second) == can_moves_32[47].first) &&
        solve32(board ^ can_moves_32[47].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[48].second) == can_moves_32[48].first) &&
        solve32(board ^ can_moves_32[48].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[49].second) == can_moves_32[49].first) &&
        solve32(board ^ can_moves_32[49].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 11
  if (board & pr10) {
    if (((board & can_moves_32[50].second) == can_moves_32[50].first) &&
        solve32(board ^ can_moves_32[50].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[51].second) == can_moves_32[51].first) &&
        solve32(board ^ can_moves_32[51].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[52].second) == can_moves_32[52].first) &&
        solve32(board ^ can_moves_32[52].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[53].second) == can_moves_32[53].first) &&
        solve32(board ^ can_moves_32[53].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 10
  if (board & pr9) {
    if (((board & can_moves_32[54].second) == can_moves_32[54].first) &&
        solve32(board ^ can_moves_32[54].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[55].second) == can_moves_32[55].first) &&
        solve32(board ^ can_moves_32[55].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[56].second) == can_moves_32[56].first) &&
        solve32(board ^ can_moves_32[56].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[57].second) == can_moves_32[57].first) &&
        solve32(board ^ can_moves_32[57].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 9
  if (((board & can_moves_32[58].second) == can_moves_32[58].first) &&
      solve32(board ^ can_moves_32[58].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[59].second) == can_moves_32[59].first) &&
      solve32(board ^ can_moves_32[59].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[60].second) == can_moves_32[60].first) &&
      solve32(board ^ can_moves_32[60].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[61].second) == can_moves_32[61].first) &&
      solve32(board ^ can_moves_32[61].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (board & 0b00000000000000000000000000111000) {
    if (((board & can_moves_32[62].second) == can_moves_32[62].first) &&
        solve32(board ^ can_moves_32[62].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[63].second) == can_moves_32[63].first) &&
        solve32(board ^ can_moves_32[63].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[64].second) == can_moves_32[64].first) &&
        solve32(board ^ can_moves_32[64].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[65].second) == can_moves_32[65].first) &&
        solve32(board ^ can_moves_32[65].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
    if (((board & can_moves_32[66].second) == can_moves_32[66].first) &&
        solve32(board ^ can_moves_32[66].second, new_pegs)) {
      solved_boards[new_pegs] = board;
      return true;
    }
  }  // Peg 6, 5, 4
  if (((board & can_moves_32[67].second) == can_moves_32[67].first) &&
      solve32(board ^ can_moves_32[67].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[68].second) == can_moves_32[68].first) &&
      solve32(board ^ can_moves_32[68].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[69].second) == can_moves_32[69].first) &&
      solve32(board ^ can_moves_32[69].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[70].second) == can_moves_32[70].first) &&
      solve32(board ^ can_moves_32[70].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves_32[71].second) == can_moves_32[71].first) &&
      solve32(board ^ can_moves_32[71].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  /*if (((board & can_moves_32[72].second) == can_moves_32[72].first) && solve32(board ^ can_moves_32[72].second,
   * new_pegs)) {*/
  /*  solved_boards[new_pegs] = board;*/
  /*  return true;*/
  /*}*/
  /*if (((board & can_moves_32[73].second) == can_moves_32[73].first) && solve32(board ^ can_moves_32[73].second,
   * new_pegs)) {*/
  /*  solved_boards[new_pegs] = board;*/
  /*  return true;*/
  /*}*/
  /*if (((board & can_moves_32[74].second) == can_moves_32[74].first) && solve32(board ^ can_moves_32[74].second,
   * new_pegs)) {*/
  /*  solved_boards[new_pegs] = board;*/
  /*  return true;*/
  /*}*/
  /*if (((board & can_moves_32[75].second) == can_moves_32[75].first) && solve32(board ^ can_moves_32[75].second,
   * new_pegs)) {*/
  /*  solved_boards[new_pegs] = board;*/
  /*  return true;*/
  /*}*/

  return false;
}

bool solve(const std::uint64_t board, const std::size_t pegs) {
  if ((board & 0b111100001000000000000000000000000) == 0) {
    return solve32(static_cast<std::uint32_t>(board), pegs);
  } else if ((board & 0b000000000000000000000000100001111) == 0) {
    /*return solve32(static_cast<std::uint32_t>(1ul >> rotate_empty_corner_180(board)), pegs);*/
  } else if ((board & 0b000000100000010000001110000000000) == 0) {
    ++count_empty;
  } else if ((board & 0b000000000011100000010000001000000) == 0) {
  }

  ++counter;

  if (pegs == 1) {
    solved_boards[0] = board;
    return true;
  }

  /*for (const auto& can_move : can_moves) {*/
  /*  const auto new_pegs = pegs - 1;*/
  /*  if ((board & can_move.second) == can_move.first && solve(board ^ can_move.second, new_pegs)) {*/
  /*    solved_boards[new_pegs] = board;*/
  /*    return true;*/
  /*  }*/
  /*}*/

  // Unrolling the loop, it is 2x faster
  const auto new_pegs = pegs - 1;
  if (((board & can_moves[0].second) == can_moves[0].first) && solve(board ^ can_moves[0].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[1].second) == can_moves[1].first) && solve(board ^ can_moves[1].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[2].second) == can_moves[2].first) && solve(board ^ can_moves[2].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[3].second) == can_moves[3].first) && solve(board ^ can_moves[3].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[4].second) == can_moves[4].first) && solve(board ^ can_moves[4].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[5].second) == can_moves[5].first) && solve(board ^ can_moves[5].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[6].second) == can_moves[6].first) && solve(board ^ can_moves[6].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[7].second) == can_moves[7].first) && solve(board ^ can_moves[7].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[8].second) == can_moves[8].first) && solve(board ^ can_moves[8].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[9].second) == can_moves[9].first) && solve(board ^ can_moves[9].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[10].second) == can_moves[10].first) && solve(board ^ can_moves[10].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[11].second) == can_moves[11].first) && solve(board ^ can_moves[11].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[12].second) == can_moves[12].first) && solve(board ^ can_moves[12].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[13].second) == can_moves[13].first) && solve(board ^ can_moves[13].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[14].second) == can_moves[14].first) && solve(board ^ can_moves[14].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[15].second) == can_moves[15].first) && solve(board ^ can_moves[15].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[16].second) == can_moves[16].first) && solve(board ^ can_moves[16].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[17].second) == can_moves[17].first) && solve(board ^ can_moves[17].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[18].second) == can_moves[18].first) && solve(board ^ can_moves[18].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[19].second) == can_moves[19].first) && solve(board ^ can_moves[19].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[20].second) == can_moves[20].first) && solve(board ^ can_moves[20].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[21].second) == can_moves[21].first) && solve(board ^ can_moves[21].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[22].second) == can_moves[22].first) && solve(board ^ can_moves[22].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[23].second) == can_moves[23].first) && solve(board ^ can_moves[23].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[24].second) == can_moves[24].first) && solve(board ^ can_moves[24].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[25].second) == can_moves[25].first) && solve(board ^ can_moves[25].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[26].second) == can_moves[26].first) && solve(board ^ can_moves[26].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[27].second) == can_moves[27].first) && solve(board ^ can_moves[27].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[28].second) == can_moves[28].first) && solve(board ^ can_moves[28].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[29].second) == can_moves[29].first) && solve(board ^ can_moves[29].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[30].second) == can_moves[30].first) && solve(board ^ can_moves[30].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[31].second) == can_moves[31].first) && solve(board ^ can_moves[31].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[32].second) == can_moves[32].first) && solve(board ^ can_moves[32].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[33].second) == can_moves[33].first) && solve(board ^ can_moves[33].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[34].second) == can_moves[34].first) && solve(board ^ can_moves[34].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[35].second) == can_moves[35].first) && solve(board ^ can_moves[35].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[36].second) == can_moves[36].first) && solve(board ^ can_moves[36].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[37].second) == can_moves[37].first) && solve(board ^ can_moves[37].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[38].second) == can_moves[38].first) && solve(board ^ can_moves[38].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[39].second) == can_moves[39].first) && solve(board ^ can_moves[39].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[40].second) == can_moves[40].first) && solve(board ^ can_moves[40].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[41].second) == can_moves[41].first) && solve(board ^ can_moves[41].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[42].second) == can_moves[42].first) && solve(board ^ can_moves[42].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[43].second) == can_moves[43].first) && solve(board ^ can_moves[43].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[44].second) == can_moves[44].first) && solve(board ^ can_moves[44].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[45].second) == can_moves[45].first) && solve(board ^ can_moves[45].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[46].second) == can_moves[46].first) && solve(board ^ can_moves[46].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[47].second) == can_moves[47].first) && solve(board ^ can_moves[47].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[48].second) == can_moves[48].first) && solve(board ^ can_moves[48].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[49].second) == can_moves[49].first) && solve(board ^ can_moves[49].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[50].second) == can_moves[50].first) && solve(board ^ can_moves[50].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[51].second) == can_moves[51].first) && solve(board ^ can_moves[51].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[52].second) == can_moves[52].first) && solve(board ^ can_moves[52].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[53].second) == can_moves[53].first) && solve(board ^ can_moves[53].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[54].second) == can_moves[54].first) && solve(board ^ can_moves[54].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[55].second) == can_moves[55].first) && solve(board ^ can_moves[55].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[56].second) == can_moves[56].first) && solve(board ^ can_moves[56].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[57].second) == can_moves[57].first) && solve(board ^ can_moves[57].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[58].second) == can_moves[58].first) && solve(board ^ can_moves[58].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[59].second) == can_moves[59].first) && solve(board ^ can_moves[59].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[60].second) == can_moves[60].first) && solve(board ^ can_moves[60].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[61].second) == can_moves[61].first) && solve(board ^ can_moves[61].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[62].second) == can_moves[62].first) && solve(board ^ can_moves[62].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[63].second) == can_moves[63].first) && solve(board ^ can_moves[63].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[64].second) == can_moves[64].first) && solve(board ^ can_moves[64].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[65].second) == can_moves[65].first) && solve(board ^ can_moves[65].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[66].second) == can_moves[66].first) && solve(board ^ can_moves[66].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[67].second) == can_moves[67].first) && solve(board ^ can_moves[67].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[68].second) == can_moves[68].first) && solve(board ^ can_moves[68].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[69].second) == can_moves[69].first) && solve(board ^ can_moves[69].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[70].second) == can_moves[70].first) && solve(board ^ can_moves[70].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[71].second) == can_moves[71].first) && solve(board ^ can_moves[71].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[72].second) == can_moves[72].first) && solve(board ^ can_moves[72].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[73].second) == can_moves[73].first) && solve(board ^ can_moves[73].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[74].second) == can_moves[74].first) && solve(board ^ can_moves[74].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }
  if (((board & can_moves[75].second) == can_moves[75].first) && solve(board ^ can_moves[75].second, new_pegs)) {
    solved_boards[new_pegs] = board;
    return true;
  }

  return false;
}
}  // namespace FastPegSolitaire
