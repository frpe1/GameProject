#pragma once

#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>
#include <string>
#include <sstream>

namespace Game {
    /// <summary>
    /// Vector4 
    /// </summary>
    template<class T>
    class Vector4 {

    public:
        T x;
        T y;
        T z;
        T w;

        static const Vector4 zero;
        static const Vector4 one;
        static const Vector4 back;
        static const Vector4 forward;
        static const Vector4 left;
        static const Vector4 right;
        static const Vector4 up;
        static const Vector4 down;


        Vector4() : x(0), y(0), z(0), w(0) {}
        Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

        /// <summary>
        /// Copy constructor
        /// </summary>
        Vector4(const Vector4<T>& V) : x(V.x), y(V.y), z(V.z), w(V.w) {}
        explicit Vector4(T f) : x(f), y(f), z(f), w(f) {}

        ~Vector4() {}


        // Accessors
        // float X() const { return x; }
        // float Y() const { return y; }
        // float Z() const { return z; }

        // overloaded operators
        //Vector4<T> operator-() const;
        Vector4<T> operator-() const { return Vector4<T>(-x, -y, -z, -w); }

        Vector4<T>& operator=(const Vector4<T>& V);
        Vector4<T>  operator+(Vector4<T> const& V) const;
        Vector4<T>  operator-(Vector4<T> const& V) const;
        Vector4<T>  operator/(const T& f) const;
        Vector4<T>  operator*(const T& f) const;
        Vector4<T>  operator^(const T& f) const;

        /// <summary>
        /// Scalar product
        /// </summary>
        /// <param name="V"></param>
        /// <returns></returns>
        float operator*(Vector4<T> const& V) const; // scalar product

        void  operator+=(Vector4<T> const& V);
        void  operator-=(Vector4<T> const& V);
        void  operator+=(const T& f);
        void  operator-=(const T& f);
        void  operator*=(const T& f);
        void  operator/=(const T& f);

        bool  operator==(Vector4<T> const& V) const;
        bool  operator!=(Vector4<T> const& V) const;

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
        Vector4<T> normalized();

        /// <summary>
        /// Return the inverse of this vector
        /// </summary>
        /// <returns></returns>
        Vector4<T> inverse();

        /// <summary>
        /// Multiplies every component of this vector by the same component of scale.
        /// </summary>
        /// <param name="V"></param>
        void Scale(Vector4<T> const& V);



        /// <summary>
        /// Take abs value of a vector and return the new vector with positive values only.
        /// It removes the sign
        /// </summary>
        /// <param name="V"></param>
        /// <returns></returns>
        static Vector4<T> Abs(Vector4<T> const& V);

        /// <summary>
        /// Scalar product
        /// </summary>
        /// <param name="V"></param>
        /// <param name="U"></param>
        /// <returns></returns>
        static T Dot(Vector4<T> const& V, Vector4<T> const& U);
        static T Distance(Vector4<T> const& V, Vector4<T> const& U);
        static Vector4<T>& Cross(Vector4<T> const& V, Vector4<T> const& U);

        /// <summary>
        /// The length of a vector
        /// </summary>
        /// <param name="V"></param>
        /// <returns></returns>
        static T Magnitude(Vector4<T> const& V);
        static Vector4<T> const Normalize(Vector4<T> const& V);
        static Vector4<T> const Lerp(Vector4<T> const& V, Vector4<T> const& U, T t);
        static Vector4<T>& Slerp(Vector4<T> const& V, Vector4<T> const& U, T t);
        static Vector4<T> const MoveTowards(Vector4<T> const& current, Vector4<T> const& target, T maxDistanceDelta);

        /// <summary>
        /// Multiples two vectors component-wise
        /// </summary>
        /// <param name="V"></param>
        /// <param name="U"></param>
        /// <returns></returns>
        static Vector4<T> const Scale(Vector4<T> const& V, Vector4<T> const& U); // (ex (1,2,3) * (2,3,4) = (2,6,12))
        static Vector4<T> const Inverse(Vector4<T> const& V);


        // Feature: more methods to implement
        //static Vector4& Project(Vector4 const& V, Vector4& normal);
        //static Vector4& RotateY(float angle);

        std::string ToString() {
            std::stringstream ss;
            ss << "(x: " << std::to_string((T)x) << " , y: " << std::to_string((T)y) << " , z: " << std::to_string((T)z) << " , w: " << std::to_string((T)w) <<  ")\n";
            return ss.str();
        }

    };

    template<typename T>
    Vector4<T>& Vector4<T>::operator=(const Vector4<T>& V) {
        (*this).x = V.x;
        (*this).y = V.y;
        (*this).z = V.z;
        (*this).w = V.w;

        return (*this);
    }

    template<typename T>
    const Vector4<T> Vector4<T>::zero(0, 0, 0, 0);

    template<typename T>
    const Vector4<T>  Vector4<T>::one(1, 1, 1, 1);

    template<typename T>
    const Vector4<T>  Vector4<T>::back(0, 0, -1, 0);

    template<typename T>
    const Vector4<T>  Vector4<T>::forward(0, 0, 1, 0);

    template<typename T>
    const Vector4<T>  Vector4<T>::left(-1, 0, 0, 0);

    template<typename T>
    const Vector4<T>  Vector4<T>::right(1, 0, 0, 0);

    template<typename T>
    const Vector4<T>  Vector4<T>::up(0, 1, 0, 0);

    template<typename T>
    const Vector4<T>  Vector4<T>::down(0, -1, 0, 0);

    template<typename T>
    Vector4<T> Vector4<T>::operator+(Vector4<T> const& V) const {
        return Vector4(x + V.x, y + V.y, z + V.z, w + V.w);
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator-(Vector4<T> const& V) const {
        return Vector4<T>(x - V.x, y - V.y, z - V.z, w - V.w);
    }


    template<typename T>
    Vector4<T> Vector4<T>::operator/(const T& f) const {
        return Vector4<T>(x / f, y / f, z / f, w / f);
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator*(const T& f) const {
        return Vector4<T>(x * f, y * f, z * f, w * f);
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator^(const T& f) const {
        return Vector4<T>(powf(x, f), powf(y, f), powf(z, f), powf(w, f));
    }

    // OBS scalar product!
    template<typename T>
    float Vector4<T>::operator*(Vector4<T> const& V) const {
        return (x * V.x) + (y * V.y) + (z * V.z) + (w * V.w);
    }


    // =================================================================================== //


    template<typename T>
    void Vector4<T>::operator+=(Vector4<T> const& V) {

        x += V.x;
        y += V.y;
        z += V.z;
        w += V.w;
    }

    template<typename T>
    void Vector4<T>::operator-=(Vector4<T> const& V) {
        x -= V.x;
        y -= V.y;
        z -= V.z;
        w -= V.w;
    }
    template<typename T>
    void Vector4<T>::operator+=(const T& f) {
        x += f;
        y += f;
        z += f;
        w += f;
    }
    template<typename T>
    void Vector4<T>::operator-=(const T& f) {
        x -= f;
        y -= f;
        z -= f;
        w -= f;
    }
    template<typename T>
    void Vector4<T>::operator*=(const T& f) {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
    }
    template<typename T>
    void Vector4<T>::operator/=(const T& f) {
        x /= f;
        y /= f;
        z /= f;
        w /= f;
    }

    template<typename T>
    bool Vector4<T>::operator==(Vector4<T> const& V) const {
        return (x == V.x) && (y == V.y) && (z == V.z) && (w == V.w);
    }

    template<typename T>
    bool Vector4<T>::operator!=(Vector4<T> const& V) const {
        return (x != V.x) && (y != V.y) && (z != V.z) && (w != V.w);
    }
    template<typename T>
    bool Vector4<T>::operator>=(const T& f) const {
        return (x >= f) && (y >= f) && (z >= f) && (w >= f);
    }
    template<typename T>
    bool Vector4<T>::operator<=(const T& f) const {
        return (x <= f) && (y <= f) && (z <= f) && (w <= f);
    }
    template<typename T>
    bool Vector4<T>::operator>(const T& f) const {
        return (x > f) && (y > f) && (z > f) && (w > f);
    }
    template<typename T>
    bool Vector4<T>::operator<(const T& f) const {
        return (x < f) && (y < f) && (z < f) && (w < f);
    }

    // =================================================================================== //

    template<typename T>
    T Vector4<T>::magnitude() {
        return sqrtf(x * x + y * y + z * z, w * w);
    }
    template<typename T>
    Vector4<T> Vector4<T>::normalized() {

        Vector4<T> r;

        float d = this->magnitude();
        if (d > 0.00000f) {
            T s = 1 / d;
            r.x = x * s;
            r.y = y * s;
            r.z = z * s;
            r.w = w * s;
        }

        return r;
    }
    template<typename T>
    Vector4<T> Vector4<T>::inverse() {
        Vector4<T> r(-x, -y, -z, -w);
        return r;
    }
    template<typename T>
    void Vector4<T>::Scale(Vector4<T> const& V) {
        x *= V.x;
        y *= V.y;
        z *= V.z;
        w *= V.w;
    }

    // =================================================================================== //
    template<typename T>
    Vector4<T> Vector4<T>::Abs(Vector4<T> const& V) {
        return Vector4<T>(fabsf(V.x), fabsf(V.y), fabsf(V.z), fabsf(V.w));
    }
    template<typename T>
    T Vector4<T>::Dot(Vector4<T> const& V, Vector4<T> const& U) {
        return (V.x * U.x) + (V.x * U.y) + (V.z * U.z) + (V.w * U.w);
    }

    template<typename T>
    T Vector4<T>::Distance(Vector4<T> const& V, Vector4<T> const& U) {
        Vector4<T> r;

        r.x = (V.x - U.x) * (V.x - U.x);
        r.y = (V.y - U.y) * (V.y - U.y);
        r.z = (V.z - U.z) * (V.z - U.z);
        r.w = (V.w - U.w) * (V.w - U.w);

        return sqrtf(r.x + r.y + r.z + r.w);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::Cross(Vector4<T> const& V, Vector4<T> const& U) {
        Vector4<T> r;

        r.x = (V.y * U.z) - (V.z - U.y);
        r.y = -((V.x * U.z) - (V.z * U.x));
        r.z = (V.x * U.y) - (V.y * U.x);

        return r;
    }
    template<typename T>
    T Vector4<T>::Magnitude(Vector4<T> const& V) {
        Vector4<T> r = V;

        return r.magnitude();
    }

    template<typename T>
    Vector4<T> const Vector4<T>::Normalize(Vector4<T> const& V) {
        Vector4<T> r(V.x, V.y, V.z, V.w);
        r = r.normalized();
        return r;
    }

    template<typename T>
    Vector4<T> const Vector4<T>::Lerp(Vector4<T> const& V, Vector4<T> const& U, T t) {
        Vector4<T> r;

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
        r.w = V.w + (U.w - V.w) * v;

        return r;
    }

    template<typename T>
    Vector4<T>& Vector4<T>::Slerp(Vector4<T> const& V, Vector4<T> const& U, T t) {
        Vector4<T> r;
        // TODO: yet to be implemented
        return r;
    }

    template<typename T>
    Vector4<T> const Vector4<T>::MoveTowards(Vector4<T> const& current, Vector4<T> const& target, T maxDistanceDelta) {
        Vector4<T> r;

        Vector4<T>::Abs(target - current);

        if (Vector4<T>::Abs(target - current) <= maxDistanceDelta) {
            r = target;
            return r;
        }

        T sign = Vector4<T>::Abs(target - current) >= 0.0f ? 1.0f : -1.0f;

        Vector4<T> t = Vector4<T>::Abs(target - current);

        r = current + t * sign * maxDistanceDelta;

        return r;
    }

    template<typename T>
    Vector4<T> const Vector4<T>::Scale(Vector4<T> const& V, Vector4<T> const& U) {
        Vector4<T> r;

        r.x = (V.x * U.x);
        r.y = (V.y * U.y);
        r.z = (V.z * U.z);
        r.w = (V.w * U.w);

        return r;
    }
    template<typename T>
    Vector4<T> const Vector4<T>::Inverse(Vector4<T> const& V) {
        Vector4<T> r;

        r.x = -V.x;
        r.y = -V.y;
        r.z = -V.z;
        r.w = -V.w;

        return r;
    }



    // =================================================================================== //

    /// <summary>
    /// Vector4 with float type
    /// </summary>
    using Vector4f = Vector4<float>;

    /// <summary>
    /// Vector4 with double type
    /// </summary>
    using Vector4d = Vector4<double>;

    /// <summary>
    /// Vector4 with int type
    /// </summary>
    using Vector4i = Vector4<int>;


    /// <summary>
    /// 
    /// </summary>
    //typedef Vector4<float> vec3ff;
}


#endif VECTOR4_H // VECTOR4_H