#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <string>
#include <sstream>

    /// <summary>
    /// Vector3 
    /// </summary>
    template<class T>
    class Vector3 {

    public:
        T x;
        T y;
        T z;

        static const Vector3 zero;
        static const Vector3 one;
        static const Vector3 back;
        static const Vector3 forward;
        static const Vector3 left;
        static const Vector3 right;
        static const Vector3 up;
        static const Vector3 down;


        Vector3() : x(0), y(0), z(0) {}
        Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

        /// <summary>
        /// Copy constructor
        /// </summary>
        Vector3(const Vector3<T>& V) : x(V.x), y(V.y), z(V.z) {}
        explicit Vector3(T f) : x(f), y(f), z(f) {}

        ~Vector3() {}


        // Accessors
        // float X() const { return x; }
        // float Y() const { return y; }
        // float Z() const { return z; }

        // overloaded operators
        //Vector3<T> operator-() const;
        Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }

        Vector3<T>& operator=(const Vector3<T>& V);
        Vector3<T>  operator+(Vector3<T> const& V) const;
        Vector3<T>  operator-(Vector3<T> const& V) const;
        Vector3<T>  operator/(const T& f) const;
        Vector3<T>  operator*(const T& f) const;
        Vector3<T>  operator^(const T& f) const;
       
        /// <summary>
        /// Scalar product
        /// </summary>
        /// <param name="V"></param>
        /// <returns></returns>
        float operator*(Vector3<T> const& V) const; // scalar product
       
        void  operator+=(Vector3<T> const& V);
        void  operator-=(Vector3<T> const& V);
        void  operator+=(const T& f);
        void  operator-=(const T& f);
        void  operator*=(const T& f);
        void  operator/=(const T& f);

        bool  operator==(Vector3<T> const& V) const;
        bool  operator!=(Vector3<T> const& V) const;

        // TODO: more comp operators needed for two vectors
        bool  operator>=(const T& f) const;
        bool  operator>(const T& f) const;
        bool  operator<=(const T& f) const;
        bool  operator<(const T& f) const;

       

        /// <summary>
        /// Return length of this vector
        /// </summary>
        /// <returns></returns>
        T magnitude();

        /// <summary>
        /// Returns this vector with a magnitude of 1
        /// </summary>
        /// <returns></returns>
        Vector3<T> normalized();

        /// <summary>
        /// Return the inverse of this vector
        /// </summary>
        /// <returns></returns>
        Vector3<T> inverse();

        /// <summary>
        /// Multiplies every component of this vector by the same component of scale.
        /// </summary>
        /// <param name="V"></param>
        void Scale(Vector3<T> const& V);

        

        /// <summary>
        /// Take abs value of a vector and return the new vector with positive values only.
        /// It removes the sign
        /// </summary>
        /// <param name="V"></param>
        /// <returns></returns>
        static Vector3<T> Abs(Vector3<T> const& V);

        /// <summary>
        /// Scalar product
        /// </summary>
        /// <param name="V"></param>
        /// <param name="U"></param>
        /// <returns></returns>
        static T Dot(Vector3<T> const& V, Vector3<T> const& U);
        static T Distance(Vector3<T> const& V, Vector3<T> const& U);
        static Vector3<T>& Cross(Vector3<T> const& V, Vector3<T> const& U);

        /// <summary>
        /// The length of a vector
        /// </summary>
        /// <param name="V"></param>
        /// <returns></returns>
        static T Magnitude(Vector3<T> const& V);
        static Vector3<T> const Normalize(Vector3<T> const& V);
        static Vector3<T> const Lerp(Vector3<T> const& V, Vector3<T> const& U, T t);
        static Vector3<T>& Slerp(Vector3<T> const& V, Vector3<T> const& U, T t);
        static Vector3<T> const MoveTowards(Vector3<T> const& current, Vector3<T> const& target, T maxDistanceDelta);

        /// <summary>
        /// Multiples two vectors component-wise
        /// </summary>
        /// <param name="V"></param>
        /// <param name="U"></param>
        /// <returns></returns>
        static Vector3<T> const Scale(Vector3<T> const& V, Vector3<T> const& U); // (ex (1,2,3) * (2,3,4) = (2,6,12))
        static Vector3<T> const Inverse(Vector3<T> const& V);

        // Feature: more methods to implement
        //static Vector3& Project(Vector3 const& V, Vector3& normal);
        //static Vector3& RotateY(float angle);
        
        std::string ToString() {
            std::stringstream ss;
            ss << "(x: " << std::to_string((T)x) << " , y: " << std::to_string((T)y) + " , z: " << std::to_string((T)z) << ")\n";
            return ss.str();
        }

    };

    template<typename T>
    Vector3<T>& Vector3<T>::operator=(const Vector3<T>& V) {
        (*this).x = V.x;
        (*this).y = V.y;
        (*this).z = V.z;

        return (*this);
    }

    template<typename T>
    const Vector3<T> Vector3<T>::zero(0, 0, 0);

    template<typename T>
    const Vector3<T>  Vector3<T>::one(1, 1, 1);

    template<typename T>
    const Vector3<T>  Vector3<T>::back(0, 0, -1);

    template<typename T>
    const Vector3<T>  Vector3<T>::forward(0, 0, 1);

    template<typename T>
    const Vector3<T>  Vector3<T>::left(-1, 0, 0);

    template<typename T>
    const Vector3<T>  Vector3<T>::right(1, 0, 0);

    template<typename T>
    const Vector3<T>  Vector3<T>::up(0, 1, 0);

    template<typename T>
    const Vector3<T>  Vector3<T>::down(0, -1, 0);

    template<typename T>
    Vector3<T> Vector3<T>::operator+(Vector3<T> const& V) const {
        return Vector3(x + V.x, y + V.y, z + V.z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-(Vector3<T> const& V) const {
        return Vector3<T>(x - V.x, y - V.y, z - V.z);
    }


    template<typename T>
    Vector3<T> Vector3<T>::operator/(const T& f) const {
        return Vector3<T>(x / f, y / f, z / f);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*(const T& f) const {
        return Vector3<T>(x * f, y * f, z * f);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator^(const T& f) const {
        return Vector3<T>(powf(x, f), powf(y, f), powf(z, f));
    }

    // OBS scalar product!
    template<typename T>
    float Vector3<T>::operator*(Vector3<T> const& V) const {
        return (x * V.x) + (y * V.y) + (z * V.z);
    }


    // =================================================================================== //


    template<typename T>
    void Vector3<T>::operator+=(Vector3<T> const& V) {

        x += V.x;
        y += V.y;
        z += V.z;
    }

    template<typename T>
    void Vector3<T>::operator-=(Vector3<T> const& V) {
        x -= V.x;
        y -= V.y;
        z -= V.z;
    }
    template<typename T>
    void Vector3<T>::operator+=(const T& f) {
        x += f;
        y += f;
        z += f;
    }
    template<typename T>
    void Vector3<T>::operator-=(const T& f) {
        x -= f;
        y -= f;
        z -= f;
    }
    template<typename T>
    void Vector3<T>::operator*=(const T& f) {
        x *= f;
        y *= f;
        z *= f;
    }
    template<typename T>
    void Vector3<T>::operator/=(const T& f) {
        x /= f;
        y /= f;
        z /= f;
    }

    template<typename T>
    bool Vector3<T>::operator==(Vector3<T> const& V) const {
        return (x == V.x) && (y == V.y) && (z == V.z);
    }

    template<typename T>
    bool Vector3<T>::operator!=(Vector3<T> const& V) const {
        return (x != V.x) && (y != V.y) && (z != V.z);
    }
    template<typename T>
    bool Vector3<T>::operator>=(const T& f) const {
        return (x >= f) && (y >= f) && (z >= f);
    }
    template<typename T>
    bool Vector3<T>::operator<=(const T& f) const {
        return (x <= f) && (y <= f) && (z <= f);
    }
    template<typename T>
    bool Vector3<T>::operator>(const T& f) const {
        return (x > f) && (y > f) && (z > f);
    }
    template<typename T>
    bool Vector3<T>::operator<(const T& f) const {
        return (x < f) && (y < f) && (z < f);
    }

    // =================================================================================== //

    template<typename T>
    T Vector3<T>::magnitude() {
        return sqrtf(x * x + y * y + z * z);
    }
    template<typename T>
    Vector3<T> Vector3<T>::normalized() {

        Vector3<T> r;

        float d = this->magnitude();
        if (d > 0.00000f) {
            T s = 1 / d;
            r.x = x * s;
            r.y = y * s;
            r.z = z * s;
        }

        return r;
    }
    template<typename T>
    Vector3<T> Vector3<T>::inverse() {
        Vector3<T> r(-x, -y, -z);
        return r;
    }
    template<typename T>
    void Vector3<T>::Scale(Vector3<T> const& V) {
        x *= V.x;
        y *= V.y;
        z *= V.z;
    }

    // =================================================================================== //
    template<typename T>
    Vector3<T> Vector3<T>::Abs(Vector3<T> const& V) {
        return Vector3<T>(fabsf(V.x), fabsf(V.y), fabsf(V.z));
    }
    template<typename T>
    T Vector3<T>::Dot(Vector3<T> const& V, Vector3<T> const& U) {
        return (V.x * U.x) + (V.x * U.y) + (V.z * U.z);
    }

    template<typename T>
    T Vector3<T>::Distance(Vector3<T> const& V, Vector3<T> const& U) {
        Vector3<T> r;

        r.x = (V.x - U.x) * (V.x - U.x);
        r.y = (V.y - U.y) * (V.y - U.y);
        r.z = (V.z - U.z) * (V.z - U.z);

        return sqrtf(r.x + r.y + r.z);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::Cross(Vector3<T> const& V, Vector3<T> const& U) {
        Vector3<T> r;

        r.x = (V.y * U.z) - (V.z - U.y);
        r.y = -((V.x * U.z) - (V.z * U.x));
        r.z = (V.x * U.y) - (V.y * U.x);

        return r;
    }
    template<typename T>
    T Vector3<T>::Magnitude(Vector3<T> const& V) {
        Vector3<T> r = V;

        return r.magnitude();
    }

    template<typename T>
    Vector3<T> const Vector3<T>::Normalize(Vector3<T> const& V) {
        Vector3<T> r(V.x, V.y, V.z);
        r = r.normalized();
        return r;
    }

    template<typename T>
    Vector3<T> const Vector3<T>::Lerp(Vector3<T> const& V, Vector3<T> const& U, T t) {
        Vector3<T> r;

        T v = 0.0f;

        if (t < 0.0f)
            v = 0.0f;
        else if (t > 1.0f)
            v = 1.0f;
        else
            v = t;

        r.x = V.x + (U.x - V.x) * v;
        r.y = V.y + (U.y - V.y) * v;
        r.z = V.z + (U.z - V.z) * v;

        return r;
    }

    template<typename T>
    Vector3<T>& Vector3<T>::Slerp(Vector3<T> const& V, Vector3<T> const& U, T t) {
        Vector3<T> r;
        // TODO: yet to be implemented
        return r;
    }

    template<typename T>
    Vector3<T> const Vector3<T>::MoveTowards(Vector3<T> const& current, Vector3<T> const& target, T maxDistanceDelta) {
        Vector3<T> r;

        Vector3<T>::Abs(target - current);

        if (Vector3<T>::Abs(target - current) <= maxDistanceDelta) {
            r = target;
            return r;
        }

        T sign = Vector3<T>::Abs(target - current) >= 0.0f ? 1.0f : -1.0f;

        Vector3<T> t = Vector3<T>::Abs(target - current);

        r = current + t * sign * maxDistanceDelta;

        return r;
    }

    template<typename T>
    Vector3<T> const Vector3<T>::Scale(Vector3<T> const& V, Vector3<T> const& U) {
        Vector3<T> r;

        r.x = (V.x * U.x);
        r.y = (V.y * U.y);
        r.z = (V.z * U.z);

        return r;
    }
    template<typename T>
    Vector3<T> const Vector3<T>::Inverse(Vector3<T> const& V) {
        Vector3<T> r;

        r.x = -V.x;
        r.y = -V.y;
        r.z = -V.z;

        return r;
    }

    // =================================================================================== //

    /// <summary>
    /// Vector3 with float type
    /// </summary>
    using Vector3f = Vector3<float>;

    /// <summary>
    /// Vector3 with double type
    /// </summary>
    using Vector3d = Vector3<double>;

    /// <summary>
    /// Vector3 with int type
    /// </summary>
    using Vector3i = Vector3<int>;


    /// <summary>
    /// 
    /// </summary>
    //typedef Vector3<float> vec3ff;


#endif VECTOR3_H // VECTOR3_H