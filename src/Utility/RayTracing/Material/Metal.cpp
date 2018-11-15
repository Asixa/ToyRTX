#include <RayTracing/OpTexture.h>
#include <RayTracing/Metal.h>
#include <Utility/Math.h>

using namespace RayTracing;
using namespace CppUtility::Other;
using namespace glm;


Metal::Metal(const Texture::CPtr & specular, float fuzz)
	: specular(specular), fuzz(fuzz) { }

Metal::Metal(float r, float g, float b, float fuzz)
	: Metal(rgb(r,g,b), fuzz) { }

Metal::Metal(const glm::rgb & specular, float fuzz)
	: fuzz(fuzz) {
	this->specular = OpTexture::ConstantTexture(specular);
}

bool Metal::Scatter(HitRecord & rec) const {
	vec3 dir = reflect(rec.ray->GetDir(), rec.vertex.normal);
	vec3 dirFuzz = dir + fuzz * Math::RandInSphere();

	// ��������ڱ���֮��
	if (dot(dirFuzz, rec.vertex.normal) < 0) {
		rec.ray->SetLightColor(vec3(0));
		return false;
	}

	auto attenuation = specular->Value(rec.vertex.u, rec.vertex.v, rec.vertex.pos);
	rec.ray->Update(rec.vertex.pos, dirFuzz, attenuation);
	return true;
}