#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <Utility/HeapObj.h>
#include <RayTracing/Ray.h>
#include <glm/glm.hpp>

namespace RayTracing {
	struct HitRecord {
		HitRecord(const Ray::Ptr & ray = NULL, const glm::vec3 & pos = glm::vec3(0), const glm::vec3 & normal = glm::vec3(0,0,1));

		Ray::Ptr ray;
		glm::vec3 pos;
		glm::vec3 normal;
	};

	class Material : public CppUtility::Other::HeapObj{
		HEAP_OBJ_SETUP(Material)
	public:
		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(HitRecord & rec) const = 0;
	};
}

#endif // !_MATERIAL_H_
