#pragma once
class vec3{
public:
	double e[3];

	vec3() :e{ 0,0,0 } {}
	vec3(double a, double b, double c) :e{ a,b,c } {}

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	vec3 operator- () const { return vec3(-e[0], -e[1], -e[2]); }

	double operator[](int i) const{ return e[i]; }
	double& operator[](int i) { return e[i]; }


	vec3& operator+=(vec3& other) {
		this->e[0] += other.e[0];
		this->e[1] += other.e[1];
		this->e[2] += other.e[2];
		return *this;
	}

	vec3& operator*=(double change) {
		this->e[0] *= change;
		this->e[1] *= change;
		this->e[2] *= change;
		return *this;
	}

	vec3& operator/=(double change) {
		return *this *= 1/ change;
	}
	
	double lengthSquared()const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	//line length
	double length() const {
		return std::sqrt(lengthSquared());
	}
};
using point3 = vec3;

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
	return (1 / t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}

