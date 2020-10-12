#include "Vector3.h"

namespace Game {
    // =================================================================================== //
    /*
    extern "C++" {
        template<typename T>
        Vector3<T> Vector3<T>::operator-() const { return Vector3<T>(-x, -y, -z); }
    }
    */
    /*
    // overloaded assignment operator
    template<typename T>
    Vector3<T>& Vector3<T>::operator=(const Vector3<T>& V) {
        (*this).x = V.x;
        (*this).y = V.y;
        (*this).z = V.z;

        return (*this);
    }



    Vector3 Vector3::operator+(Vector3 const& V) const {
        return Vector3(x + V.x, y + V.y, z + V.z);
    }

    Vector3 Vector3::operator-(Vector3 const& V) const {
        return Vector3(x - V.x, y - V.y, z - V.z);
    }



    Vector3 Vector3::operator/(const float& f) const {
        return Vector3(x / f, y / f, z / f);
    }

    Vector3 Vector3::operator*(const float& f) const {
        return Vector3(x * f, y * f, z * f);
    }

    Vector3 Vector3::operator^(const float& f) const {
        return Vector3(powf(x, f), powf(y, f), powf(z, f));
    }

    // OBS scalar product!
    float Vector3::operator*(Vector3 const& V) const {
        return (x * V.x) + (y * V.y) + (z * V.z);
    }

    /*
    // =================================================================================== //



    void Vector3::operator+=(Vector3 const& V) {

        x += V.x;
        y += V.y;
        z += V.z;
    }


    void Vector3::operator-=(Vector3 const& V) {
        x -= V.x;
        y -= V.y;
        z -= V.z;
    }

    void Vector3::operator+=(const float& f) {
        x += f;
        y += f;
        z += f;
    }

    void Vector3::operator-=(const float& f) {
        x -= f;
        y -= f;
        z -= f;
    }

    void Vector3::operator*=(const float& f) {
        x *= f;
        y *= f;
        z *= f;
    }

    void Vector3::operator/=(const float& f) {
        x /= f;
        y /= f;
        z /= f;
    }


    bool Vector3::operator==(Vector3 const& V) const {
        return (x == V.x) && (y == V.y) && (z == V.z);
    }


    bool Vector3::operator!=(Vector3 const& V) const {
        return (x != V.x) && (y != V.y) && (z != V.z);
    }

    bool Vector3::operator>=(const float& f) const {
        return (x >=f) && (y >= f) && (z >= f);
    }

    bool Vector3::operator<=(const float& f) const {
        return (x <= f) && (y <= f) && (z <= f);
    }

    bool Vector3::operator>(const float& f) const {
        return (x > f) && (y > f) && (z > f);
    }

    bool Vector3::operator<(const float& f) const {
        return (x < f) && (y < f) && (z < f);
    }


    // =================================================================================== //


    float Vector3::magnitude() {
        return sqrtf(x * x + y * y + z * z);
    }

    Vector3 Vector3::normalized() {

        Vector3 r;

        float d = this->magnitude();
        if (d > 0.00000f) {
            float s = 1 / d;
            r.x = x * s;
            r.y = y * s;
            r.z = z * s;
        }

        return r;
    }

    Vector3 Vector3::inverse() {
        Vector3 r(-x, -y, -z);
        return r;
    }

    void Vector3::Scale(Vector3 const& V) {
        x *= V.x;
        y *= V.y;
        z *= V.z;
    }



    // =================================================================================== //

    Vector3 Vector3::Abs(Vector3 const& V) {
        return Vector3(fabsf(V.x), fabsf(V.y), fabsf(V.z));
    }

    float Vector3::Dot(Vector3 const& V, Vector3 const& U) {
        return (V.x * U.x) + (V.x * U.y) + (V.z * U.z);
    }


    float Vector3::Distance(Vector3 const& V, Vector3 const& U) {
        Vector3 r;

        r.x = (V.x - U.x) * (V.x - U.x);
        r.y = (V.y - U.y) * (V.y - U.y);
        r.z = (V.z - U.z) * (V.z - U.z);

        return sqrtf(r.x + r.y + r.z);
    }


    Vector3& Vector3::Cross(Vector3 const& V, Vector3 const& U) {
        Vector3 r;

        r.x = (V.y * U.z) - (V.z - U.y);
        r.y = -((V.x * U.z) - (V.z * U.x));
        r.z = (V.x * U.y) - (V.y * U.x);

        return r;
    }

    float Vector3::Magnitude(Vector3 const& V) {
        Vector3 r = V;

        return r.magnitude();
    }


    Vector3 const Vector3::Normalize(Vector3 const& V) {
        Vector3 r(V.x, V.y, V.z);
        r = r.normalized();
        return r;
    }


    Vector3 const Vector3::Lerp(Vector3 const& V, Vector3 const& U, float t) {
        Vector3 r;

        float v = 0.0f;

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


    Vector3& Vector3::Slerp(Vector3 const& V, Vector3 const& U, float t) {
        Vector3 r;
        // TODO: yet to be implemented
        return r;
    }


    Vector3 const Vector3::MoveTowards(Vector3 const& current, Vector3 const& target, float maxDistanceDelta) {
        Vector3 r;

        Vector3::Abs(target - current);

        if (Vector3::Abs(target - current) <= maxDistanceDelta) {
            r = target;
            return r;
        }

        float sign = Vector3::Abs(target - current) >= 0.0f ? 1.0f : -1.0f;

        Vector3 t = Vector3::Abs(target - current);

        r = current + t * sign * maxDistanceDelta;

        return r;
    }


    Vector3 const Vector3::Scale(Vector3 const& V, Vector3 const& U) {
        Vector3 r;

        r.x = (V.x * U.x);
        r.y = (V.y * U.y);
        r.z = (V.z * U.z);

        return r;
    }

    Vector3 const Vector3::Inverse(Vector3 const& V) {
        Vector3 r;

        r.x = -V.x;
        r.y = -V.y;
        r.z = -V.z;

        return r;
    }

    */
    /*
    template<class T>
    std::string Vector3<T>::ToString() {
        std::stringstream ss;
        ss << "(x: " << std::to_string((T)x) << " , y: " << std::to_string((T)y) + " , z: " << std::to_string((T)z) << ")\n";
        return ss.str();
    }
    */
}
