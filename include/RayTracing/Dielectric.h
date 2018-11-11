#ifndef _DIELETRIC_H_
#define _DIELETRIC_H_

#include <RayTracing/Material.h>

namespace RayTracing {
	class Dielectric : public Material {
		HEAP_OBJ_SETUP(Dielectric)
	public:
		Dielectric(float refractIndex, glm::vec3 attenuationConst = glm::vec3(0));

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(HitRecord & rec) const;
	private:
		float refractIndex;
		glm::vec3 attenuationConst;
	};
}

#endif // !_DIELETRIC_H_
