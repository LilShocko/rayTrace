#pragma once
#include "vec3.h"
class ray{
private:
	point3 orig;
	vec3 dir;
public:
	ray(){}

	ray(const point3& _origin, const vec3& _dir) :orig(_origin), dir(_dir){}

	const point3& origin() const{ return this->orig; }
	const point3& direction() const { return this->dir; }

	point3 at(double t) {
		return orig + t * dir;
	}


};

