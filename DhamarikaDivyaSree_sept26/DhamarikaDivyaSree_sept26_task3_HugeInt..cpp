#include "HugeInt.h"
#include <cctype>
#include <stdexcept>

// ---------------- Constructors ----------------
HugeInt::HugeInt(long value) {
    for (int i = 0; i < digits; i++) integer[i] = 0;
    for (int j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const std::string& number) {
    for (int i = 0; i < digits; i++) integer[i] = 0;
    int length = number.size();
    for (int j = digits - length, k = 0; j < digits; j++, k++)
        if (isdigit(number[k])) integer[j] = number[k] - '0';
}

// ---------------- Addition: HugeInt + HugeInt ----------------
HugeInt HugeInt::operator+(const HugeInt& op2) const {
    HugeInt temp;
    int carry = 0;
    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        } else carry = 0;
    }
    return temp;
}

// ---------------- Addition: HugeInt + int ----------------
HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

// ---------------- Addition: HugeInt + string ----------------
HugeInt HugeInt::operator+(const std::string& op2) const {
    return *this + HugeInt(op2);
}

// ---------------- Multiplication ----------------
HugeInt HugeInt::operator*(const HugeInt& op2) const {
    HugeInt result;
    int temp[digits * 2] = {0};

    for (int i = digits - 1; i >= 0; i--) {
        for (int j = digits - 1; j >= 0; j--) {
            int k = i + j - (digits - 1);
            if (k >= 0 && k < digits) {
                temp[k] += integer[i] * op2.integer[j];
            }
        }
    }

    for (int i = digits - 1; i > 0; i--) {
        temp[i - 1] += temp[i] / 10;
        temp[i] %= 10;
    }

    for (int i = 0; i < digits; i++) result.integer[i] = temp[i];
    return result;
}

// ---------------- Division ----------------
HugeInt HugeInt::operator/(const HugeInt& divisor) const {
    if (*this < divisor) return HugeInt(0);

    HugeInt quotient, remainder;
    for (int i = 0; i < digits; i++) {
        // shift remainder left
        for (int j = 0; j < digits - 1; j++) remainder.integer[j] = remainder.integer[j + 1];
        remainder.integer[digits - 1] = integer[i];

        int count = 0;
        while (!(remainder < divisor)) {
            remainder = remainder - divisor;
            count++;
        }
        quotient.integer[i] = count;
    }
    return quotient;
}

// ---------------- Relational Operators ----------------
bool HugeInt::operator==(const HugeInt& right) const {
    for (int i = 0; i < digits; i++) if (integer[i] != right.integer[i]) return false;
    return true;
}
bool HugeInt::operator!=(const HugeInt& right) const { return !(*this == right); }
bool HugeInt::operator<(const HugeInt& right) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] < right.integer[i]) return true;
        if (integer[i] > right.integer[i]) return false;
    }
    return false;
}
bool HugeInt::operator>(const HugeInt& right) const { return right < *this; }
bool HugeInt::operator<=(const HugeInt& right) const { return !(*this > right); }
bool HugeInt::operator>=(const HugeInt& right) const { return !(*this < right); }

// ---------------- Output Operator ----------------
std::ostream& operator<<(std::ostream& output, const HugeInt& num) {
    int i;
    for (i = 0; (num.integer[i] == 0) && (i < HugeInt::digits); i++);
    if (i == HugeInt::digits) output << 0;
    else for (; i < HugeInt::digits; i++) output << num.integer[i];
    return output;
}

// ---------------- Input Operator ----------------
std::istream& operator>>(std::istream& in, HugeInt& num) {
    std::string s;
    in >> s;
    num = HugeInt(s);
    return in;
}
