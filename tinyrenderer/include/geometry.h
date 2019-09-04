#pragma once

#include <cmath>
#include <iostream>
#include <array>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////

template <class t> struct Vec2 {
  Vec2() = default;
  Vec2(t _u, t _v) : data{_u, _v} {}
  Vec2<t> &operator=(const Vec2<t> &V) {
    if (this != &V) {
      data = V.data;
    }
    return *this;
  }

  inline Vec2<t> operator+(const Vec2<t> &V) const {
    return Vec2<t>(x() + V.x(), y() + V.y());
  }
  inline Vec2<t> operator-(const Vec2<t> &V) const {
    return Vec2<t>(x() - V.x(), y() - V.y());
  }
  inline Vec2<t> operator*(float f) const {
    return Vec2<t>(t(x() * f), t(y() * f));
  }
  inline t x() const { return data[0]; }
  inline t &x() { return data[0]; }
  inline t y() const { return data[1]; }
  inline t &y() { return data[1]; }
  inline t operator[](int f) const { return data[f]; }
  inline t &operator[](int f) { return data[f]; }
  template <class> friend std::ostream &operator<<(std::ostream &s, Vec2<t> &v);

private:
  std::array<t, 2> data;
};

template <class t> struct Vec3 {
  Vec3() = default;
  Vec3(t _x, t _y, t _z) : data{_x, _y, _z} {}
  inline Vec3<t> operator^(const Vec3<t> &v) const {
    return Vec3<t>(y() * v.z() - z() * v.y(), z() * v.x() - x() * v.z(), x() * v.y() - y() * v.x());
  }
  inline Vec3<t> operator+(const Vec3<t> &v) const {
    return Vec3<t>(x() + v.x(), y() + v.y(), z() + v.z());
  }
  inline Vec3<t> operator-(const Vec3<t> &v) const {
    return Vec3<t>(x() - v.x(), y() - v.y(), z() - v.z());
  }
  inline Vec3<t> operator*(float f) const {
    return Vec3<t>(x() * f, y() * f, z() * f);
  }
  inline t operator*(const Vec3<t> &v) const {
    return x() * v.x() + y() * v.y() + z() * v.z();
  }
  inline t x() const { return data[0]; }
  inline t &x() { return data[0]; }
  inline t y() const { return data[1]; }
  inline t &y() { return data[1]; }
  inline t z() const { return data[2]; }
  inline t &z() { return data[2]; }
  inline t operator[](int f) const { return data[f]; }
  inline t &operator[](int f) { return data[f]; }
  float norm() const { return std::sqrt(x() * x() + y() * y() + z() * z()); }
  Vec3<t> &normalize(t l = 1) {
    *this = (*this) * (l / norm());
    return *this;
  }
  template <class> friend std::ostream &operator<<(std::ostream &s, Vec3<t> &v);

private:
  std::array<t, 3> data;
};

template <typename t> Vec3<t> cross(Vec3<t> lhs, Vec3<t> rhs) {
  return lhs ^ rhs;
}

typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;

template <class t> std::ostream &operator<<(std::ostream &s, Vec2<t> &v) {
  s << "(" << v.x() << ", " << v.y() << ")\n";
  return s;
}

template <class t> std::ostream &operator<<(std::ostream &s, Vec3<t> &v) {
  s << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")\n";
  return s;
}

class Matrix {
public:
  Matrix(int r = 4, int c = 4);
  inline int nrows();
  inline int ncols();

  static Matrix identity(int dimensions);
  std::vector<float> &operator[](int i);
  Matrix operator*(const Matrix &a) const;

  Matrix transpose() const;
  Matrix inverse() const;

  friend std::ostream &operator<<(std::ostream &s, Matrix &m);

private:
  std::vector<std::vector<float>> m;
  int rows, cols;
};
