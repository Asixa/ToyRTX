#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include <RayTracing/Material.h>

namespace RayTracing {
	class Lambertian : public Material {
		HEAP_OBJ_SETUP(Lambertian)
	public:
		Lambertian(float r, float g, float b);
		Lambertian(const glm::vec3 & albedo);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(HitRecord & rec) const;
	protected:

		glm::vec3 albedo;
	};
}

#endif // !_LAMBERTIAN_H_
