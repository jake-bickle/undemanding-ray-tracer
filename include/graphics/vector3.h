#pragma once

#include <iostream>

template <typename T>
class Vector3{
    public:
        Vector3();
        Vector3(T xx);
        Vector3(T x, T y, T z);

    private:
        T x;
        T y;
        T z;

    public:
        Vector3& normalize();  // Does this need to be Vector3f<T>& ?
        T dot(const Vector3<T>& vec) const;
        T length_squared() const;
        T length() const;
        Vector3<T> operator * (const T& scalar) const;
        Vector3<T> operator * (const Vector3<T>& rhs_vector) const;
        Vector3<T>& operator *= (const T& scalar);
        Vector3<T>& operator *= (const Vector3<T>& rhs_vector);
        friend std::ostream operator << (std::ostream& os, const Vector3<T>& rhs_vector);
};
