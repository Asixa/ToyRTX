#include <RayTracing/Light.h>

#include <RayTracing/ConstTexture.h>
#include <RayTracing/Ray.h>

using namespace RayTracing;
using namespace CppUtility::Other;
using namespace glm;


Light::Light(const rgb & color, float linear, float quadratic)
	: lightTex(ToPtr(new ConstTexture(color))), linear(linear), quadratic(quadratic) { }

Light::Light(const Texture::CPtr & lightTex, float linear, float quadratic)
	: lightTex(lightTex), linear(linear), quadratic(quadratic) { }

bool Light::Scatter(const HitRecord & rec) const {
	float d = rec.ray->GetTMax() * length(rec.ray->GetDir());
	float attDis;
	if (linear == 0.0&&quadratic == 0.0)
		attDis = 1;
	else {
		if (isnan(d))
			attDis = 0;
		else
			attDis = 1.0f / (1.0f + d * (linear + quadratic * d));
	}
	float attAngle = abs(dot(normalize(rec.ray->GetDir()), rec.vertex.normal));
	rec.ray->SetLightColor(attDis * attAngle * lightTex->Value(rec.vertex.u, rec.vertex.v, rec.vertex.pos));
	return false;
}