#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <RayTracing/Material.h>

namespace RayTracing {
	class Texture;

	class Light : public Material{
		MATERIAL_SETUP(Light)
	public:
		Light(const glm::rgb & color, float linear = 0.0f, float quadratic = 0.0f);
		Light(const CppUtility::Other::CPtr<Texture> & lightTex, float linear = 0.0f, float quadratic = 0.0f);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(const HitRecord & rec) const;
		float GetLinear() const { return linear; }
		float GetQuadratic() const { return quadratic; }
		const CppUtility::Other::CPtr<Texture> GetTexture() const { return lightTex; }
	private:
		float linear;
		float quadratic;
		CppUtility::Other::CPtr<Texture> lightTex;
	};
}

#endif // !_LIGHT_H_
