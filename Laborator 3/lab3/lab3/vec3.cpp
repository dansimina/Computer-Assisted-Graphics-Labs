#include "vec3.h"
namespace egc {
    vec3& vec3::operator =(const vec3& srcVector) {
        x = srcVector.x;
        y = srcVector.y;
        z = srcVector.z;
        return *this;
    }
    vec3 vec3::operator +(const vec3& srcVector) const {
        vec3 v;

        v.x = this->x + srcVector.x;
        v.y = this->y + srcVector.y;
        v.z = this->z + srcVector.z;
        return v;
    }
    vec3& vec3::operator +=(const vec3& srcVector) {
        this->x += srcVector.x;
        this->y += srcVector.y;
        this->z += srcVector.z;
        return *this;
    }
    vec3 vec3::operator *(float scalarValue) const {
        vec3 v;

        v.x = this->x * scalarValue;
        v.y = this->y * scalarValue;
        v.z = this->z * scalarValue;
        return v;
    }
    vec3 vec3::operator -(const vec3& srcVector) const {
        vec3 v;

        v.x = this->x - srcVector.x;
        v.y = this->y - srcVector.y;
        v.z = this->z - srcVector.z;
        return v;
    }
    vec3& vec3::operator -=(const vec3& srcVector) {
        this->x -= srcVector.x;
        this->y -= srcVector.y;
        this->z -= srcVector.z;
        return *this;
    }
    vec3 vec3::operator -() const {
        vec3 v;

        v.x = -this->x;
        v.y = -this->y;
        v.z = -this->z;
        return v;
    }
    float vec3::length() const {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }
    vec3& vec3::normalize() {
        float len = this->length();

        this->x = this->x / len;
        this->y = this->y / len;
        this->z = this->z / len;
        return *this;
    }

    float dotProduct(const vec3& v1, const vec3& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
    vec3 crossProduct(const vec3& v1, const vec3& v2) {
        vec3 v;

        v.x = v1.y * v2.z - v1.z * v2.y;
        v.y = v1.z * v2.x - v1.x * v2.z;
        v.z = v1.x * v2.y - v1.y * v2.z;
        return v;
    }
}