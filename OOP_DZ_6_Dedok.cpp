#include <iostream>
using namespace std;
//класс Fraction(Дробь)
class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть равен 0!" << "\n";
        }
        simplify();
    }
    void simplify() {
        int gcd = gcd_recursive(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    int gcd_recursive(int a, int b) {
        if (b == 0) return a;
        return gcd_recursive(b, a % b);
    }
    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Ошибка: деление на ноль!" << "\n";
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    void display() const {
        cout << numerator << "/" << denominator;
    }
};
//класс Date
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    int operator-(const Date& other) const {
        int days1 = day + month * 30 + year * 365;
        int days2 = other.day + other.month * 30 + other.year * 365;
        return days1 - days2;
    }
    Date operator+(int days) const {
        int d = day + days;
        int m = month;
        int y = year;
        while (d > daysInMonth(m, y)) {
            d -= daysInMonth(m, y);
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        return Date(d, m, y);
    }
    int daysInMonth(int m, int y) const {
        if (m == 2) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                return 29;
            }
            else {
                return 28;
            }
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }
    void display() const {
        cout << day << "." << month << "." << year;
    }
};
int main()
{
    //Task_1(к классу Fraction)
    Fraction a(1, 2);
    Fraction b(3, 4);
    Fraction sum = a + b;
    sum.display();
    cout << "\n";
    Fraction difference = a - b;
    difference.display();
    cout << "\n";
    Fraction product = a * b;
    product.display();  
    cout << "\n";
    Fraction quotient = a / b;
    quotient.display();
    cout << "\n";
    cout << "\n";
    //Task_2(к классу Date)
    Date d1(19, 12, 2019);
    Date d2(1, 9, 2022);
    int diff = d2 - d1;
    cout << "Difference between days: " << diff << "\n";
    Date newDate = d1 + 15;
    cout << "Date after adding 15 more days(from d1): ";
    newDate.display();
}