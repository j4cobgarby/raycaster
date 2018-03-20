/*
 * =====================================================================================
 *
 *       Filename:  vector.c
 *
 *    Description:  Vector implementation
 *
 *        Created:  17/03/18 13:07:27
 *       Compiler:  gcc
 *
 *         Author:  Jacob
 *
 * =====================================================================================
 */

#include "vector.h"

vec3d vec3d_from_pitch_yaw(float pitch, float yaw, vec3d* out) {
    float xzlen = cos(pitch * (M_PI/180));
    vec3d result = {
        xzlen * cos(yaw * (M_PI/180)),
        sin(pitch * (M_PI/180)),
        xzlen * sin(-yaw * (M_PI/180))
    };

    if (out != NULL) {
        memcpy(out, &result, sizeof(vec3d));
    }

    return result;
}

vec3d vec3d_add(vec3d a, vec3d b, vec3d* out) {
    vec3d result = {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };

    if (out != NULL) {
        memcpy(out, &result, sizeof(vec3d));
    }

    return result;
}

vec3d vec3d_sub(vec3d a, vec3d b, vec3d* out) {
    vec3d result = {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };

    if (out != NULL) {
        memcpy(out, &result, sizeof(vec3d));
    }

    return result;
}

vec3d vec3d_cross(vec3d u, vec3d v, vec3d* out) {
    vec3d result = {
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    };

    if (out != NULL) {
        memcpy(out, &result, sizeof(vec3d));
    }

    return result;
}

vec3d vec3d_scale(vec3d u, float s, vec3d* out) {
    vec3d result = {
        u.x * s,
        u.y * s,
        u.z * s
    };

    if (out != NULL) {
        memcpy(out, &result, sizeof(vec3d));
    }

    return result;
}

float vec3d_dot(vec3d u, vec3d v, float* out) {
    float result = 0;
    result += u.x * v.x;
    result += u.y * v.y;
    result += u.z * v.z;

    if (out != NULL) {
        *out = result;
    }

    return result;
}

void vec3d_print(vec3d v) {
    printf("->\n\t{%f, %f, %f}\n", v.x, v.y, v.z);
}

void tri3d_print(tri3d t) {
    printf("|>\n\t{\n\t\t{%f,%f,%f},\n\t\t{%f,%f,%f},\n\t\t{%f,%f,%f}\n\t}\n",
            t.p0.x, t.p0.y, t.p0.z,
            t.p1.x, t.p1.y, t.p1.z,
            t.p2.x, t.p2.y, t.p2.z);
}

