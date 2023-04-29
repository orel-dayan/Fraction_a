#include <iostream>
#include <stdexcept>
#include <limits>
/**
 * @file Fraction.hpp
 * @brief Header file for the Fraction class
 * @author Orel Dayan
 * This file contains the declaration of the Fraction class and its methods and operators.
 * For more information - read the readme file.
 * Below are all the links I used for the assignment :
 * https://en.cppreference.com/w/cpp/language/operators
 * https://en.cppreference.com/w/cpp/types/numeric_limits
 * https://learn.microsoft.com/en-us/cpp/cpp/general-rules-for-operator-overloading?view=msvc-170
 * https://www.tutorialspoint.com/reduce-the-fraction-to-its-lowest-form-in-cplusplus
 *
 */

namespace ariel
{
  const int MAX_DIGITS = 1000;
  const float FLOAT_PRECISION = 1000.0;

  class Fraction
  {
  private:
    int m_numetator;   // Numerator
    int m_denominator; // Denominator

    // private method :

    Fraction &simplify(); // simplify the fraction , & - return by reference because we want to chain the operators

  public:
    Fraction() : m_numetator(0), m_denominator(1) {} // default constructor

    Fraction(int numerator, int denominator); // constructor with parameters (numerator, denominator)

    Fraction(float frac) : Fraction((int)(frac * MAX_DIGITS), MAX_DIGITS) {} // constructor with parameters (float) - convert float to fraction

    int getNumerator() const { return m_numetator; }     // get the numerator
    int getDenominator() const { return m_denominator; } // get the denominator

    // operator io : >> , <<

    friend std::istream &operator>>(std::istream &stream, Fraction &franc);
    friend std::ostream &operator<<(std::ostream &stream, const Fraction &franc);

    // opertor + :

    friend Fraction operator+(Fraction francA, Fraction francB);
    friend Fraction operator+(float fracA, Fraction fracB);
    friend Fraction operator+(Fraction francA, float fracB);

    // opertor - :

    friend Fraction operator-(Fraction francA, Fraction francB);
    friend Fraction operator-(float fracA, Fraction fracB);
    friend Fraction operator-(Fraction francA, float fracB);

    // opertor * :

    friend Fraction operator*(Fraction francA, Fraction francB);
    friend Fraction operator*(float fracA, Fraction fracB);
    friend Fraction operator*(Fraction francA, float fracB);

    // opertor /

    friend Fraction operator/(Fraction fracA, Fraction fracB);
    friend Fraction operator/(Fraction fracA, float fracB);
    friend Fraction operator/(float fracA, Fraction fracB);

    // opertor += , -= , *= , /=

    Fraction &operator+=(Fraction fra);
    Fraction &operator+=(float fra);

    Fraction &operator-=(Fraction fra);
    Fraction &operator-=(float fra);

    Fraction &operator*=(Fraction fra);
    Fraction &operator*=(float fra);

    Fraction &operator/=(Fraction fra);
    Fraction &operator/=(float fra);

    // opertor ++ , -- : perfix and postfix

    Fraction &operator++();
    Fraction operator++(int);

    Fraction &operator--();
    Fraction operator--(int);

    // bool operators : == , != , > , >= , < , <=

    friend bool operator==(Fraction fracA, Fraction fracB); // in the .cpp file
    friend bool operator==(Fraction francA, float fracB) { return francA == Fraction(fracB); }
    friend bool operator==(float francA, Fraction fracB) { return Fraction(francA) == fracB; }

    friend bool operator!=(Fraction francA, Fraction fracB) { return !(francA == fracB); }
    friend bool operator!=(Fraction francA, float fracB) { return !(francA == fracB); }
    friend bool operator!=(float francA, Fraction fracB) { return !(francA == fracB); }

    friend bool operator>(Fraction francA, Fraction francB); // in the .cpp file
    friend bool operator>(Fraction francA, float francB) { return francA > Fraction(francB); }
    friend bool operator>(float francA, Fraction francB) { return Fraction(francA) > francB; }

    friend bool operator>=(Fraction francA, Fraction francB); // in the .cpp file
    friend bool operator>=(Fraction francA, float francB) { return francA >= Fraction(francB); }
    friend bool operator>=(float francA, Fraction francB) { return Fraction(francA) >= francB; }

    // operator < , <= : using the operators above ( == , != , > , >= )

    friend bool operator<(Fraction francA, Fraction francB) { return !(francA >= francB); }
    friend bool operator<(Fraction francA, float francB) { return !(francA >= francB); }
    friend bool operator<(float francA, Fraction francB) { return !(francA >= francB); }

    friend bool operator<=(Fraction frA, Fraction frB) { return !(frA > frB); }
    friend bool operator<=(Fraction frA, float frB) { return !(frA > frB); }
    friend bool operator<=(float frA, Fraction frB) { return !(frA > frB); }
  };
}
