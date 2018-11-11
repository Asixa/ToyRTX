#ifndef _METAL_H_
#define _METAL_H_

#include <RayTracing/Material.h>

namespace RayTracing {
	class Metal : public Material{
		HEAP_OBJ_SETUP(Metal)
	public:
		Metal(float r, float g, float b, float fuzz = 0.0f);
		Metal(const glm::vec3 & specular, float fuzz = 0.0f);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(HitRecord & rec) const;
	protected:
		glm::vec3 specular;
		float fuzz;
	};
}

#endif // !_METAL_H_
