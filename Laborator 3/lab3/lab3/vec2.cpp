#include "vec2.h"
#include <cmath>
namespace egc {
    vec2& vec2::operator =(const vec2& srcVector) {
        x = srcVector.x;
        y = srcVector.y;

        return *this;
    }
    vec2 vec2::operator +(const vec2& srcVector) const {
        vec2 v;
        
        v.x = this->x + srcVector.x;
        v.y = this->y + srcVector.y;
        return v;
    }
    vec2& vec2::operator +=(const vec2& srcVector) {
        this->x += srcVector.x;
        this->y += srcVector.y;
        return *this;
    }
    vec2 vec2::operator *(float scalarValue) const {
        vec2 v;

        v.x = this->x * scalarValue;
        v.y = this->y * scalarValue;
        return v;
    }
    vec2 vec2::operator -(const vec2& srcVector) const {
        vec2 v;

        v.x = this->x - srcVector.x;
        v.y = this->y - srcVector.y;
        return v;
    }
    vec2& vec2::operator -=(const vec2& srcVector) {
        this->x -= srcVector.x;
        this->y -= srcVector.y;
        return *this;
    }
    vec2 vec2::operator -() const {
        vec2 v;

        v.x = -this->x;
        v.y = -this->y;
        return v;
    }
    float vec2::length() const {
        return sqrt(this->x * this->x + this->y * this->y);
    }
    vec2& vec2::normalize() {
        float len = this->length();

        this->x = this->x / len;
        this->y = this->y / len;
        return *this;
    }

    float dotProduct(const vec2& v1, const vec2& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }
}