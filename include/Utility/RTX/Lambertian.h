#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include <Utility/RTX/Material.h>

#include <glm/glm.hpp>

namespace RayTracing {
	class Texture;

	class Lambertian : public Material {
		MATERIAL_SETUP(Lambertian)
	public:
		Lambertian(float r, float g, float b);
		Lambertian(const glm::rgb & albedo);
		Lambertian(CppUtility::Other::CPtr<Texture> albedo);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(const HitRecord & rec) const;
		
		const CppUtility::Other::CPtr<Texture> GetTexture() const { return albedo; }
	protected:
		CppUtility::Other::CPtr<Texture> albedo;
	};
}

#endif // !_LAMBERTIAN_H_
