#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include <RayTracing/Texture.h>
#include <RayTracing/Material.h>

#include <Utility/Math.h>

namespace RayTracing {
	class Lambertian : public Material {
		HEAP_OBJ_SETUP(Lambertian)
	public:
		Lambertian(float r, float g, float b);
		Lambertian(const glm::rgb & albedo);
		Lambertian(const Texture::Ptr & albedo);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(HitRecord & rec) const;
	protected:

		Texture::Ptr albedo;
	};
}

#endif // !_LAMBERTIAN_H_
