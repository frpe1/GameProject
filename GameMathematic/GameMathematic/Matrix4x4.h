#pragma once


#ifndef MATRIX4x4_H
#define MATRIX4x4_H

#include <iostream>
#include <string>
#include <sstream>
#include "Vector4.h"

namespace Game {
    /// <summary>
    /// Matrix4x4 
    /// </summary>
    template<class T>
    class Matrix4x4 {

        public:
            T m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;


            static const Matrix4x4<T> identity;


            Matrix4x4() : m00 (0), m01(0), m02(0), m03(0), m10(0), m11(0), m12(0), m13(0), m20(0), m21(0), m22(0), m23(0), m30(0), m31(0), m32(0), m33(0) {}
            Matrix4x4(T m00, T  m01, T  m02, T  m03, T  m10, T  m11, T  m12, T  m13, T  m20, T  m21, T  m22, T  m23, T  m30, T  m31, T  m32, T  m33) : m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12), m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31), m32(m32), m33(m33) {}
            Matrix4x4(const Vector4<T>& c0, const Vector4<T>& c1, const Vector4<T>& c2, const Vector4<T>& c3) : m00(c0.x), m01(c1.x), m02(c2.x), m03(c3.x),
                                                                                                                m10(c0.y), m11(c1.y), m12(c2.y), m13(c3.y),
                                                                                                                m20(c0.z), m21(c1.z), m22(c2.z), m23(c3.z),
                                                                                                                m30(c0.w), m31(c1.w), m32(c2.w), m33(c3.w) {}

            /// <summary>
            /// Copy constructor
            /// </summary>
            Matrix4x4(const Matrix4x4<T>& M) : m00(M.m00), m01(M.m01), m02(M.m02), m03(M.m03), m10(M.m10), m11(M.m11), m12(M.m12), m13(M.m13), m20(M.m20), m21(M.m21), m22(M.m22), m23(M.m23), m30(M.m30), m31(M.m31), m32(M.m32), m33(M.m33) {}
            explicit Matrix4x4(T f) : m00(f), m01(f), m02(f), m03(f), m10(f), m11(f), m12(f), m13(f), m20(f), m21(f), m22(f), m23(f), m30(f), m31(f), m32(f), m33(f) {}

            ~Matrix4x4() {}

            Matrix4x4<T> operator-() const;

            Matrix4x4<T>& operator=(const Matrix4x4<T>& M);
            Matrix4x4<T>  operator+(Matrix4x4<T> const& M) const;
            Matrix4x4<T>  operator-(Matrix4x4<T> const& M) const;
            Matrix4x4<T>  operator/(const T& f) const;
            /// <summary>
            /// Scale with an factor f
            /// </summary>
            /// <param name="f"></param>
            /// <returns></returns>
            Matrix4x4<T>  operator*(const T& f) const;

            Vector4<T>  operator*(Vector4<T> const& V) const;

            /// <summary>
            /// Matrix4x4 multiplying
            /// </summary>
            /// <param name="M"></param>
            /// <returns></returns>
            Matrix4x4<T> operator*(Matrix4x4<T> const& M) const;

            /*
            void  operator+=(Matrix4x4<T> const& M);
            void  operator-=(Matrix4x4<T> const& M);
            void  operator+=(const T& f);
            void  operator-=(const T& f);
            void  operator*=(const T& f);
            void  operator/=(const T& f);
            */

            Matrix4x4<T>& inverse();
            T determinant() const;

            /// <summary>
            /// Rotate Translate Scale
            /// </summary>
            /// <param name="M"></param>
            /// <returns></returns>
            static Matrix4x4<T> RTS(Matrix4x4<T> const& M);
            static Matrix4x4<T> Inverse(Matrix4x4<T> const& M);
            static Matrix4x4<T> Scale(Matrix4x4<T> const& M, Matrix4x4<T> const& W);
            static Matrix4x4<T> Scale(Matrix4x4<T> const& M, const T& f);
            static T Determinant(Matrix4x4<T> const& M);

            std::string ToString() {
                std::stringstream ss;
                ss << "[" << std::to_string((T)m00) << " , " << std::to_string((T)m01) << " , " << std::to_string((T)m02) << " , " << std::to_string((T)m03) << "|\n";
                ss << "|" << std::to_string((T)m10) << " , " << std::to_string((T)m11) << " , " << std::to_string((T)m12) << " , " << std::to_string((T)m13) << "|\n";
                ss << "|" << std::to_string((T)m20) << " , " << std::to_string((T)m21) << " , " << std::to_string((T)m22) << " , " << std::to_string((T)m23) << "|\n";
                ss << "|" << std::to_string((T)m30) << " , " << std::to_string((T)m31) << " , " << std::to_string((T)m32) << " , " << std::to_string((T)m33) << "]\n";
                return ss.str();
            }
    };


    template<typename T>
    const Matrix4x4<T> Matrix4x4<T>::identity(1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1);

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator-() const {
        return Matrix4x4<T>(-m00, -m01, -m02, -m03, -m10, -m11, -m12, -m13, -m20, -m21, -m22, -m23, -m30, -m31, -m32, -m33);
    }

    template<typename T>
    Matrix4x4<T>& Matrix4x4<T>::operator=(const Matrix4x4<T>& M) {

        (*this).m00 = M.m00;
        (*this).m01 = M.m01;
        (*this).m02 = M.m02;
        (*this).m03 = M.m03;
        (*this).m10 = M.m10;
        (*this).m11 = M.m11;
        (*this).m12 = M.m12;
        (*this).m13 = M.m13;
        (*this).m20 = M.m20;
        (*this).m21 = M.m21;
        (*this).m22 = M.m22;
        (*this).m23 = M.m23;
        (*this).m30 = M.m30;
        (*this).m31 = M.m31;
        (*this).m32 = M.m32;
        (*this).m33 = M.m33;

        return (*this);
    }


    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator+(Matrix4x4<T> const& M) const {

        return  Matrix4x4<T>(
            m00 + M.m00,
            m01 + M.m01,
            m02 + M.m02,
            m03 + M.m03,
            m10 + M.m10,
            m11 + M.m11,
            m12 + M.m12,
            m13 + M.m13,
            m20 + M.m20,
            m21 + M.m21,
            m22 + M.m22,
            m23 + M.m23,
            m30 + M.m30,
            m31 + M.m31,
            m32 + M.m32,
            m33 + M.m33
        );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator-(Matrix4x4<T> const& M) const {
        return Matrix4x4<T>(
            m00 - M.m00,
            m01 - M.m01,
            m02 - M.m02,
            m03 - M.m03,
            m10 - M.m10,
            m11 - M.m11,
            m12 - M.m12,
            m13 - M.m13,
            m20 - M.m20,
            m21 - M.m21,
            m22 - M.m22,
            m23 - M.m23,
            m30 - M.m30,
            m31 - M.m31,
            m32 - M.m32,
            m33 - M.m33
            );
    }


    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator/(const T& f) const {
        const T s = 1 / f;
        return Matrix4x4<T>(
            m00 * s,
            m01 * s,
            m02 * s,
            m03 * s,
            m10 * s,
            m11 * s,
            m12 * s,
            m13 * s,
            m20 * s,
            m21 * s,
            m22 * s,
            m23 * s,
            m30 * s,
            m31 * s,
            m32 * s,
            m33 * s
            );
    }

    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator*(const T& f) const {
        return Matrix4x4<T>(
            m00 * f,
            m01 * f,
            m02 * f,
            m03 * f,
            m10 * f,
            m11 * f,
            m12 * f,
            m13 * f,
            m20 * f,
            m21 * f,
            m22 * f,
            m23 * f,
            m30 * f,
            m31 * f,
            m32 * f,
            m33 * f
            );
    }


    template<typename T>
    Vector4<T> Matrix4x4<T>::operator*(Vector4<T> const& V) const {
        return Vector4<T>(
            m00 * V.x + m01 * V.y + m02 * V.z + m03 * V.w,
            m10 * V.x + m11 * V.y + m12 * V.z + m13 * V.w,
            m20 * V.x + m21 * V.y + m22 * V.z + m23 * V.w,
            m30 * V.x + m31 * V.y + m32 * V.z + m33 * V.w
            );
    }

    // OBS multiply matrix
    template<typename T>
    Matrix4x4<T> Matrix4x4<T>::operator*(Matrix4x4<T> const& M) const {
        return Matrix4x4<T>(
            m00 * M.m00 + m01 * M.m10 + m02 * M.m20 + m03 * M.m30,
            m00 * M.m01 + m01 * M.m11 + m02 * M.m21 + m03 * M.m31,
            m00 * M.m02 + m01 * M.m12 + m02 * M.m22 + m03 * M.m32,
            m00 * M.m03 + m01 * M.m13 + m02 * M.m23 + m03 * M.m33,

            m10 * M.m00 + m11 * M.m10 + m12 * M.m20 + m13 * M.m30,
            m10 * M.m01 + m11 * M.m11 + m12 * M.m21 + m13 * M.m31,
            m10 * M.m02 + m11 * M.m12 + m12 * M.m22 + m13 * M.m32,
            m10 * M.m03 + m11 * M.m13 + m12 * M.m23 + m13 * M.m33,

            m20 * M.m00 + m21 * M.m10 + m22 * M.m20 + m23 * M.m30,
            m20 * M.m01 + m21 * M.m11 + m22 * M.m21 + m23 * M.m31,
            m20 * M.m02 + m21 * M.m12 + m22 * M.m22 + m23 * M.m32,
            m20 * M.m03 + m21 * M.m13 + m22 * M.m23 + m23 * M.m33,

            m30 * M.m00 + m31 * M.m10 + m32 * M.m20 + m33 * M.m30,
            m30 * M.m01 + m31 * M.m11 + m32 * M.m21 + m33 * M.m31,
            m30 * M.m02 + m31 * M.m12 + m32 * M.m22 + m33 * M.m32,
            m30 * M.m03 + m31 * M.m13 + m32 * M.m23 + m33 * M.m33
            );
    }
    
    template<typename T>
    Matrix4x4<T>&  Matrix4x4<T>::inverse() {
        
        Matrix4x4<T> m = (*this);
        
        T A2323 = m22 * m33 - m23 * m32;
        T A1323 = m21 * m33 - m23 * m31;
        T A1223 = m21 * m32 - m22 * m31;
        T A0323 = m20 * m33 - m23 * m30;
        T A0223 = m20 * m32 - m22 * m30;
        T A0123 = m20 * m31 - m21 * m30;
        T A2313 = m12 * m33 - m13 * m32;
        T A1313 = m11 * m33 - m13 * m31;
        T A1213 = m11 * m32 - m12 * m31;
        T A2312 = m12 * m23 - m13 * m22;
        T A1312 = m11 * m23 - m13 * m21;
        T A1212 = m11 * m22 - m12 * m21;
        T A0313 = m10 * m33 - m13 * m30;
        T A0213 = m10 * m32 - m12 * m30;
        T A0312 = m10 * m23 - m13 * m20;
        T A0212 = m10 * m22 - m12 * m20;
        T A0113 = m10 * m31 - m11 * m30;
        T A0112 = m10 * m21 - m11 * m20;

        T det = m00 * (m11 * A2323 - m12 * A1323 + m13 * A1223)
            - m01 * (m10 * A2323 - m12 * A0323 + m13 * A0223)
            + m02 * (m10 * A1323 - m11 * A0323 + m13 * A0123)
            - m03 * (m10 * A1223 - m11 * A0223 + m12 * A0123);

        m00 = det * (m.m11 * A2323 - m.m12 * A1323 + m.m13 * A1223);
        m01 = det * -(m.m01 * A2323 - m.m02 * A1323 + m.m03 * A1223);
        m02 = det * (m.m01 * A2313 - m.m02 * A1313 + m.m03 * A1213);
        m03 = det * -(m.m01 * A2312 - m.m02 * A1312 + m.m03 * A1212);
        m10 = det * -(m.m10 * A2323 - m.m12 * A0323 + m.m13 * A0223);
        m11 = det * (m.m00 * A2323 - m.m02 * A0323 + m.m03 * A0223);
        m12 = det * -(m.m00 * A2313 - m.m02 * A0313 + m.m03 * A0213);
        m13 = det * (m.m00 * A2312 - m.m02 * A0312 + m.m03 * A0212);
        m20 = det * (m.m10 * A1323 - m.m11 * A0323 + m.m13 * A0123);
        m21 = det * -(m.m00 * A1323 - m.m01 * A0323 + m.m03 * A0123);
        m22 = det * (m.m00 * A1313 - m.m01 * A0313 + m.m03 * A0113);
        m23 = det * -(m.m00 * A1312 - m.m01 * A0312 + m.m03 * A0112);
        m30 = det * -(m.m10 * A1223 - m.m11 * A0223 + m.m12 * A0123);
        m31 = det * (m.m00 * A1223 - m.m01 * A0223 + m.m02 * A0123);
        m32 = det * -(m.m00 * A1213 - m.m01 * A0213 + m.m02 * A0113);
        m33 = det * (m.m00 * A1212 - m.m01 * A0212 + m.m02 * A0112);

        return (*this);

    }


    template<typename T>
    T Matrix4x4<T>::determinant() const {
        T A2323 = m22 * m33 - m23 * m32;
        T A1323 = m21 * m33 - m23 * m31;
        T A1223 = m21 * m32 - m22 * m31;
        T A0323 = m20 * m33 - m23 * m30;
        T A0223 = m20 * m32 - m22 * m30;
        T A0123 = m20 * m31 - m21 * m30;
        T A2313 = m12 * m33 - m13 * m32;
        T A1313 = m11 * m33 - m13 * m31;
        T A1213 = m11 * m32 - m12 * m31;
        T A2312 = m12 * m23 - m13 * m22;
        T A1312 = m11 * m23 - m13 * m21;
        T A1212 = m11 * m22 - m12 * m21;
        T A0313 = m10 * m33 - m13 * m30;
        T A0213 = m10 * m32 - m12 * m30;
        T A0312 = m10 * m23 - m13 * m20;
        T A0212 = m10 * m22 - m12 * m20;
        T A0113 = m10 * m31 - m11 * m30;
        T A0112 = m10 * m21 - m11 * m20;

        T det = m00 * (m11 * A2323 - m12 * A1323 + m13 * A1223)
              - m01 * (m10 * A2323 - m12 * A0323 + m13 * A0223)
              + m02 * (m10 * A1323 - m11 * A0323 + m13 * A0123)
              - m03 * (m10 * A1223 - m11 * A0223 + m12 * A0123);
        return det;
    }


    // =================================================================================== //


    template<typename T>
    T Matrix4x4<T>::Determinant(Matrix4x4<T> const& M)  {
        T A2323 = M.m22 * M.m33 - M.m23 * M.m32;
        T A1323 = M.m21 * M.m33 - M.m23 * M.m31;
        T A1223 = M.m21 * M.m32 - M.m22 * M.m31;
        T A0323 = M.m20 * M.m33 - M.m23 * M.m30;
        T A0223 = M.m20 * M.m32 - M.m22 * M.m30;
        T A0123 = M.m20 * M.m31 - M.m21 * M.m30;
        T A2313 = M.m12 * M.m33 - M.m13 * M.m32;
        T A1313 = M.m11 * M.m33 - M.m13 * M.m31;
        T A1213 = M.m11 * M.m32 - M.m12 * M.m31;
        T A2312 = M.m12 * M.m23 - M.m13 * M.m22;
        T A1312 = M.m11 * M.m23 - M.m13 * M.m21;
        T A1212 = M.m11 * M.m22 - M.m12 * M.m21;
        T A0313 = M.m10 * M.m33 - M.m13 * M.m30;
        T A0213 = M.m10 * M.m32 - M.m12 * M.m30;
        T A0312 = M.m10 * M.m23 - M.m13 * M.m20;
        T A0212 = M.m10 * M.m22 - M.m12 * M.m20;
        T A0113 = M.m10 * M.m31 - M.m11 * M.m30;
        T A0112 = M.m10 * M.m21 - M.m11 * M.m20;

        T det =   M.m00 * (M.m11 * A2323 - M.m12 * A1323 + M.m13 * A1223)
                - M.m01 * (M.m10 * A2323 - M.m12 * A0323 + M.m13 * A0223)
                + M.m02 * (M.m10 * A1323 - M.m11 * A0323 + M.m13 * A0123)
                - M.m03 * (M.m10 * A1223 - M.m11 * A0223 + M.m12 * A0123);
        return det;
    }

}

#endif MATRIX4x4_H