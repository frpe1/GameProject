#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <string>
#include <sstream>

class Vector3 {

public:
    float x;
    float y;
    float z;

    static Vector3 const zero;
    static Vector3 const one;
    static Vector3 const back;
    static Vector3 const forward;
    static Vector3 const left;
    static Vector3 const right;
    static Vector3 const up;
    static Vector3 const down;

    Vector3();
    Vector3(float x, float y, float z);
    Vector3(Vector3 const& other); // Copy constructor

    ~Vector3() {}

    float magnitude();
    Vector3 normalized();
    Vector3& inverse();

    // Accessors
    // float X() const { return x; }
    // float Y() const { return y; }
    // float Z() const { return z; }

    // overloaded operators
    Vector3& operator=(Vector3 const& V);
    Vector3  operator+(Vector3 const& V) const;
    Vector3  operator-(Vector3 const& V) const;
    Vector3  operator/(const float& f) const;
    Vector3  operator*(const float& f) const;

    /// <summary>
    /// Scalar product
    /// </summary>
    /// <param name="V"></param>
    /// <returns></returns>
    float operator*(Vector3 const& V) const; // scalar product

    void  operator+=(Vector3 const& V);
    void  operator-=(Vector3 const& V);
    void  operator+=(const float& f);
    void  operator-=(const float& f);
    void  operator*=(const float& f);
    void  operator/=(const float& f);

    bool  operator==(Vector3 const& V) const;
    bool  operator!=(Vector3 const& V) const;

    // TODO: more comp operators needed for two vectors
    bool  operator>=(const float& f) const;
    bool  operator>(const float& f) const;
    bool  operator<=(const float& f) const;
    bool  operator<(const float& f) const;


    /// <summary>
    /// Take abs value of a vector and return the new vector with positive values only.
    /// It removes the sign
    /// </summary>
    /// <param name="V"></param>
    /// <returns></returns>
    static Vector3& Abs(Vector3 const& V);

    /// <summary>
    /// Scalar product
    /// </summary>
    /// <param name="V"></param>
    /// <param name="U"></param>
    /// <returns></returns>
    static float Dot(Vector3 const& V, Vector3 const& U);
    static float Distance(Vector3 const& V, Vector3 const& U);
    static Vector3& Cross(Vector3 const& V, Vector3 const& U);
    
    /// <summary>
    /// The length of a vector
    /// </summary>
    /// <param name="V"></param>
    /// <returns></returns>
    static float Magnitude(Vector3 const& V);
    static Vector3 Normalize(Vector3 const& V);
    static Vector3& Lerp(Vector3 const& V, Vector3 const& U, float t);
    static Vector3& Slerp(Vector3 const& V, Vector3 const& U, float t);
    static Vector3& MoveTowards(Vector3 const& current, Vector3 const& target, float maxDistanceDelta);
    static Vector3& Scale(Vector3 const& V, Vector3 const& U); // (ex (1,2,3) * (2,3,4) = (2,6,12))
    static Vector3& Inverse(Vector3 const& V);
    
    // Feature: more methods to implement
    //static Vector3& Project(Vector3 const& V, Vector3& normal);
    //static Vector3& RotateY(float angle);

    std::string ToString();
};

#endif VECTOR3_H // VECTOR3_H