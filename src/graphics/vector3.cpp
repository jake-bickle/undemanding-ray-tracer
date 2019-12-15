#include <graphics/vector3.h>
#include <cmath>

template <typename T>
Vector3<T>::Vector3()
    : x(0), y(0), z(0) {}

template <typename T>
Vector3<T>::Vector3(const Vector3<T>& copy)
    : x(copy.x), y(copy.y), z(copy.z) {}

template <typename T>
Vector3<T>::Vector3(T initalizer)
    : x(initalizer), y(initalizer), z(initalizer) {}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
    : x(x), y(y), z(z) {}

template <typename T>
Vector3<T>& Vector3<T>::normalize(){
    *this *= (1 / this->magnitude());
    return *this;
}

template <typename T>
T Vector3<T>::dot(const Vector3<T>& vec) const{
    return vec.x * x + vec.y * y + vec.z * z;
}

template <typename T>
T Vector3<T>::magnitude_squared() const{
    return this->dot(*this);
}

template <typename T>
T Vector3<T>::magnitude() const{
    return sqrt(this->magnitude_squared());
}

template <typename T>
Vector3<T>& Vector3<T>::floor(){
    x = int(x);
    y = int(y);
    z = int(z);
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator *= (const T& scalar){
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator * (const T& scalar) const{
    Vector3<T> new_vec(*this);
    return new_vec *= scalar;
}

template <typename T>
Vector3<T>& Vector3<T>::operator *= (const Vector3<T>& rhs){
    this->x *= rhs.x;
    this->y *= rhs.y;
    this->z *= rhs.z;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator * (const Vector3<T>& rhs) const{
    return Vector3<T>(*this) *= rhs;
}

template <typename T>
Vector3<T> Vector3<T>::operator + (const Vector3<T>& rhs) const{
    return Vector3<T>(*this) += rhs;
}

template <typename T>
Vector3<T>& Vector3<T>::operator += (const Vector3<T>& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator - (const Vector3<T>& rhs) const{
    return Vector3<T>(*this) -= rhs;
}

template <typename T>
Vector3<T>& Vector3<T>::operator -= (const Vector3<T>& rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}