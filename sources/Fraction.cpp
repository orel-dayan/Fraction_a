#include "Fraction.hpp"

namespace ariel
{

  /**
   * @brief  __gcd- greatest common divisor  - Euclidean algorithm
   *
   * @param a - the numerator
   * @param b - the denominator
   * @return long long - the greatest common divisor
   */
  long long __gcd(long long a, long long b)
  {
    if (b == 0)
    {
      return a;
    }
    return __gcd(b, a % b);
  }

  /**
   *
   * @brief check if the result of the operation is overflow
   * std :: numeric_limits <int> :: max () - the maximum value of int
   * std :: numeric_limits <int> :: min () - the minimum value of int
   *
   * @param a - the numerator
   * @param b - the denominator
   * @throw std::overflow_error if the result is overflow
   * @return void
   */

  void check_overflow(long long a, long long b)
  {
    constexpr long long max_int = std::numeric_limits<int>::max();
    constexpr long long min_int = std::numeric_limits<int>::min();

    if (a > max_int || b > max_int || a < min_int || b < min_int)
    {
      throw std::overflow_error("");
    }
  }

  Fraction::Fraction(int numerator, int denominator)
      : m_numetator(numerator), m_denominator(denominator)
  {
    if (denominator == 0)
    {
      throw std::invalid_argument("Error: denominator can't be 0");
    }

    simplify(); // simplify the fraction
  }

  // operator+

  Fraction operator+(Fraction fracA, Fraction fracB)
  {
    long long newNumerator = (long long)fracA.m_numetator * (long long)fracB.m_denominator + (long long)fracB.m_numetator * (long long)fracA.m_denominator;
    long long newDenominator = (long long)fracA.m_denominator * (long long)fracB.m_denominator;
    check_overflow(newNumerator, newDenominator);

    return Fraction(newNumerator, newDenominator);
  }
  Fraction operator+(Fraction fracA, float fracB)
  {
    return fracA + Fraction(fracB);
  }
  Fraction operator+(float fracA, Fraction fracB)
  {
    return Fraction(fracA) + fracB;
  }

  // operator-

  Fraction operator-(Fraction fracA, Fraction fracB)
  {
    long long newNumerator = (long long)fracA.m_numetator * (long long)fracB.m_denominator - (long long)fracB.m_numetator * (long long)fracA.m_denominator;
    long long newDenominator = (long long)fracA.m_denominator * (long long)fracB.m_denominator;
    check_overflow(newNumerator, newDenominator);
    return Fraction(newNumerator, newDenominator);
  }
  Fraction operator-(Fraction fracA, float fracB)
  {
    return fracA - Fraction(fracB);
  }
  Fraction operator-(float fracA, Fraction fracB)
  {
    return Fraction(fracA) - fracB;
  }

  // operator*

  Fraction operator*(Fraction fracA, Fraction fracB)
  {
    long long newNumerator = (long long)fracA.m_numetator * (long long)fracB.m_numetator;
    long long newDenominator = (long long)fracA.m_denominator * (long long)fracB.m_denominator;
    check_overflow(newNumerator, newDenominator);
    return Fraction(newNumerator, newDenominator);
  }

  Fraction operator*(Fraction fracA, float fracB)
  {
    return fracA * Fraction(fracB);
  }
  Fraction operator*(float fracA, Fraction fracB)
  {
    return Fraction(fracA) * fracB;
  }

  // operator/

  Fraction operator/(Fraction fracA, Fraction fracB)
  {
    if (fracB.m_numetator == 0)
    {
      throw std::runtime_error(" Error: cant divide by zero");
    }
    long long newNumerator = (long long)fracA.m_numetator * (long long)fracB.m_denominator;
    long long newDenominator = (long long)fracA.m_denominator * (long long)fracB.m_numetator;
    check_overflow(newNumerator, newDenominator);
    return Fraction(newNumerator, newDenominator);
  }
  Fraction operator/(Fraction fracA, float fracB)
  {
    return fracA / Fraction(fracB);
  }
  Fraction operator/(float fracA, Fraction fracB)
  {
    return Fraction(fracA) / fracB;
  }

  // opertor +=

  Fraction &Fraction::operator+=(Fraction frac)
  {
    Fraction temp = *this + frac;
    m_numetator = temp.m_numetator;
    m_denominator = temp.m_denominator;
    return *this;
  }
  Fraction &Fraction::operator+=(float frac)
  {
    *this = *this + frac;
    return *this;
  }

  // opertor -=
  Fraction &Fraction::operator-=(Fraction frac)
  {
    Fraction temp = *this - frac;
    m_numetator = temp.m_numetator;
    m_denominator = temp.m_denominator;
    return *this;
  }
  Fraction &Fraction::operator-=(float frac)
  {
    *this = *this - frac;
    return *this;
  }

  // opertor *=
  Fraction &Fraction::operator*=(Fraction frac)
  {
    Fraction temp = *this * frac;
    m_numetator = temp.m_numetator;
    m_denominator = temp.m_denominator;
    return *this;
  }
  Fraction &Fraction::operator*=(float frac)
  {
    *this = *this * frac;

    return *this;
  }

  // opertor /=
  Fraction &Fraction::operator/=(Fraction frac)
  {
    Fraction temp = *this / frac;
    m_numetator = temp.m_numetator;
    m_denominator = temp.m_denominator;
    return *this;
  }
  Fraction &Fraction::operator/=(float frac)
  {
    *this = *this / frac;
    return *this;
  }
  // opertor ++ (pre)
  Fraction &Fraction::operator++()
  {
    return (*this += 1);
  }

  // opertor ++ (int)
  Fraction Fraction::operator++(int)
  {
    Fraction temp = *this;
    *this += 1;
    return temp;
  }
  // opertor -- (pre)
  Fraction &Fraction::operator--()
  {
    return (*this -= 1);
  }

  // opertor -- (int)
  Fraction Fraction::operator--(int)
  {
    Fraction temp = *this;
    *this -= 1;
    return temp;
  }

  // oper bool ==
  bool operator==(Fraction fracA, Fraction fracB)
  {
    int numA = (int)(((float)fracA.m_numetator / (float)fracA.m_denominator) * FLOAT_PRECISION);
    int numB = (int)(((float)fracB.m_numetator / (float)fracB.m_denominator) * FLOAT_PRECISION);
    return numA == numB;
  }

  bool operator>(Fraction francA, Fraction francB)
  {

    return francA.m_numetator * francB.m_denominator > francB.m_numetator * francA.m_denominator;
  }
  bool operator>=(Fraction francA, Fraction francB)
  {
    return francA.m_numetator * francB.m_denominator >= francB.m_numetator * francA.m_denominator;
  }
  // io operators

  std::istream &operator>>(std::istream &stream, Fraction &frac)
  {
    int num, den;

    stream >> num >> den;

    if (stream.fail())
    {
      throw std::runtime_error("Error: Input failed");
    }

    if (den == 0)
    {
      throw std::runtime_error("Error: cant divide by zero");
    }

    frac = Fraction(num, den);
    return stream;
  }

  std::ostream &operator<<(std::ostream &stream, const Fraction &frac)
  {
    if (frac.getNumerator() == 0)
    {
      stream << "0";
    }
    else
    {
      stream << frac.getNumerator() << "/" << frac.getDenominator();
    }
    return stream;
  }

  // private method for simplifying fraction

  Fraction &Fraction::simplify()
  {
    if (m_numetator == 0)
    {
      m_denominator = 1;
      return *this;
    }

    int gcd = __gcd(m_numetator, m_denominator);
    m_numetator /= gcd;
    m_denominator /= gcd;

    if (m_denominator < 0)
    {
      m_numetator *= -1;
      m_denominator *= -1;
    }

    return *this;
  }
}
