#include <RayTracing/Sphere.h>
#include <Utility/Math.h>

using namespace RayTracing;
using namespace CppUtility::Other;
using namespace glm;

Sphere::Sphere(const vec3 & center, float radius, const Material::CPtr & material)
	: center(center), radius(radius), Hitable(material) {
	vec3 minP = center - vec3(radius);
	vec3 maxP = center + vec3(radius);
	box = AABB(minP, maxP);
};

HitRst Sphere::RayIn(Ray::Ptr & ray) const {
	vec3 oc = ray->GetOrigin() - center;
	float a = dot(ray->GetDir(), ray->GetDir());
	float b = dot(oc, ray->GetDir());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;

	if (discriminant <= 0)
		return HitRst::FALSE;

	float t = (-b - sqrt(discriminant)) / a;
	if (t > ray->GetTMax() || t < Ray::tMin) {
		t = (-b + sqrt(discriminant)) / a;
		if (t > ray->GetTMax() || t < Ray::tMin)
			return HitRst::FALSE;
	}
	
	ray->SetTMax(t);

	HitRst hitRst(true);
	vec3 pos = ray->At(t);
	vec3 normal = (pos - center) / radius;
	vec2 uv = Math::Sphere2UV(normal);
	hitRst.record = HitRecord(ray, pos, normal, uv[0], uv[1]);
	hitRst.material = GetMat();
	hitRst.isMatCoverable = IsMatCoverable();

	return hitRst;
}