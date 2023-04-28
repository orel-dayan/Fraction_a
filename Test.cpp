#include "doctest.h"
#include <iostream>
#include <string.h>

#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("bool operations == and !=")
{
  Fraction f1(1, 8), f2(2, 16), f3(1, 9);
  CHECK(f1 == f2);
  CHECK(!(f1 == f3));
  CHECK(f1 == Fraction(1, 8));
  CHECK(f1 == 0.125);
  CHECK(!(f1 == Fraction(1, 9)));
  CHECK(!(f1 == 0.111));
  CHECK(Fraction(1, 8) == f1);
  CHECK(0.125 == f1);
  CHECK(!(Fraction(1, 9) == f1));
  CHECK(!(0.75 == f1));
  CHECK(Fraction(2, 4) == Fraction(1, 2));
  CHECK(0.2 == Fraction(1, 5));
  CHECK(!(Fraction(1, 2) == Fraction(1, 3)));
  CHECK(!(0.5 == Fraction(1, 7)));
  CHECK(!(f1 != f2));
  CHECK(f1 != f3);
  CHECK(!(f1 != Fraction(1, 8)));
  CHECK(!(f1 != 0.125));
  CHECK(f1 != Fraction(1, 5));
  CHECK(f1 != 0.2);
  CHECK(!(Fraction(1, 8) != f1));
  CHECK(!(0.125 != f1));
  CHECK(Fraction(1, 5) != f1);
  CHECK(0.89 != f1);
  CHECK(!(Fraction(2, 8) != Fraction(1, 4)));
  CHECK(!(0.25 != Fraction(1, 4)));
}
TEST_CASE("bool operators <, >, <=, >=")
{
  Fraction f1(1, 8), f2(2, 16), f3(1, 9);

  CHECK(!(f1 < f3));
  CHECK(!(f3 > f1));
  CHECK(f3 < f1);
  CHECK(f1 > f3);
  CHECK(f1 <= f2);
  CHECK(f2 >= f1);
  CHECK(f2 <= f1);
  CHECK(f1 >= f2);
  CHECK(!(f1 > f2));
}
TEST_CASE("check if constructor make zero ")
{
  Fraction franc(0, 1);
  CHECK(franc == 0);
}
TEST_CASE(" check constructor with negative numbers")
{
  Fraction franc1(-1, 5);
  Fraction franc2(1, -5);
  Fraction franc3(-1, -5);
  CHECK(franc1 == -0.2);
  CHECK(franc2 == -0.2);
  CHECK(franc3 == 0.2);
}

TEST_CASE(" division by zero")
{
  Fraction franc1(6, 5);
  Fraction franc2(0, 1);

  CHECK_THROWS_AS(franc1 / franc2, std::runtime_error);
  CHECK_NOTHROW(franc2 / franc1);
}
TEST_CASE(" check if constructor throws exception when dem is zero ")
{

  CHECK_THROWS(Fraction(1, 0)); // invalid fraction (division by zero)
}
TEST_CASE("increment and decrement operators")
{

  Fraction fraction(7, 4);              // 1.75
  CHECK(fraction++ == Fraction(7, 4));  // 1.75
  CHECK(fraction == Fraction(11, 4));   // 1.75 + 1 = 2.75 = 11/4
  CHECK(++fraction == Fraction(15, 4)); // 11/4 + 1 = 15/4 = 3.75

  CHECK(fraction-- == Fraction(15, 4)); // 3.75
  CHECK(fraction == Fraction(11, 4));   // 3.75 - 1 = 2.75 = 11/4
  CHECK(--fraction == Fraction(7, 4));
}

TEST_CASE("arithmethic operators")
{
  Fraction f1(1, 8), f2(2, 16), f3(1, 9);
  // check + and - operators
  CHECK(f1 + f2 == Fraction(1, 4));             // 1/8 + 1/8 = 8/64 + 8/64 = 16/64 = 1/4
  CHECK(f1 + f3 == Fraction(17, 72));           // 1/8 + 1/9 = 9/72 + 8/72 = 17/72
  CHECK(f2 + f3 == Fraction(17, 72));           // 2/16 + 1/9 = 18/144 + 16/144 = 34/144 = 17/72
  CHECK(f1 - f2 == Fraction(0, 1));             // 1/8 - 1/8 = 8/64 - 8/64 = 0/1
  CHECK(f1 - f3 == Fraction(1, 72));            // 1/8 - 1/9 = 9/72 - 8/72 = 1/72
  CHECK(f2 - f3 == Fraction(1, 72));            // 2/16 - 1/9 = 18/144 - 16/144 = 2/144 = 1/72
  CHECK(f1 + Fraction(1, 8) == Fraction(1, 4)); // 1/8 + 1/8 = 8/64 + 8/64 = 16/64 = 1/4
  CHECK(f1 + 0.125 == Fraction(1, 4));          // 1/8 + 1/8 = 8/64 + 8/64 = 16/64 = 1/4
  CHECK(f1 - Fraction(1, 8) == Fraction(0, 1)); // 1/8 - 1/8 = 8/64 - 8/64 = 0/1
  CHECK(f1 - 0.125 == Fraction(0, 1));
  CHECK(Fraction(1, 8) + f1 == Fraction(1, 4)); // 1/8 + 1/8 = 8/64 + 8/64 = 16/64 = 1/4
  CHECK(0.125 + f1 == Fraction(1, 4));          // 1/8 + 1/8 = 8/64 + 8/64 = 16/64 = 1/4
  CHECK(Fraction(1, 8) - f1 == Fraction(0, 1)); // 1/8 - 1/8 = 8/64 - 8/64 = 0/1
  CHECK(Fraction(1) * 5.5 == Fraction(11, 2));
  CHECK(5.5 * Fraction(1) == Fraction(11, 2));
  CHECK(Fraction(1) / Fraction(11, 2) == Fraction(2, 11));
}
TEST_CASE("assignment operators ")
{
  Fraction f1(1), f2(5, 16), f3(1, 9);
  // check += and -= operators
  CHECK((f1 += f2) == Fraction(21, 16));   // 1 + 5/16 = 16/16 + 5/16 = 21/16
  CHECK(f1 == Fraction(21, 16));           // f1 changed
  CHECK(f2 != Fraction(21, 16));           // f2 not changed
  CHECK((f1 += f3) == Fraction(205, 144)); // 21/16 + 1/9 = 189/144 + 16/144 = 205/144
  f1 = Fraction(1);                        // reset f1
  f1 /= Fraction(5);                       // 1/5
  CHECK(f1 == Fraction(1, 5));             // 1/5
  f2 = Fraction(5);                        // reset f2
  f2 *= Fraction(5);
  CHECK(f2 == Fraction(25)); // 25
}
