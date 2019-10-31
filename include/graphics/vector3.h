#pragma once
#include <iostream>

template <typename T>
struct Vector3{
    T x;
    T y;
    T z;

    Vector3();
    Vector3(const Vector3<T>& copy);
    Vector3(T initalizer);
    Vector3(T x, T y, T z);
    Vector3<T>& normalize();  
    T dot(const Vector3<T>& vec) const;
    T magnitude_squared() const;
    T magnitude() const;
    Vector3<T> operator * (const T& scalar) const;
    Vector3<T> operator * (const Vector3<T>& rhs) const;
    Vector3<T>& operator *= (const T& scalar);
    Vector3<T>& operator *= (const Vector3<T>& rhs);
    Vector3<T> operator + (const Vector3<T>& rhs) const;
    Vector3<T>& operator += (const Vector3<T>& rhs);
    Vector3<T> operator - (const Vector3<T>& rhs) const;
    Vector3<T>& operator -= (const Vector3<T>& rhs);

    friend std::ostream& operator << (std::ostream& os, const Vector3<T>& rhs){
        os << "[" << rhs.x << " " << rhs.y << " " << rhs.z << "]";
        return os;
    }
};
