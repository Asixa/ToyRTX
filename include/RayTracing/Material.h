#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <RayTracing/Ray.h>

#include <Utility/HeapObj.h>

#include <glm/glm.hpp>

#include <vector>

namespace RayTracing {
	
	struct Vertex {
		Vertex(glm::vec3 pos = glm::vec3(0), glm::vec3 normal = glm::vec3(0, 0, 1), float u = 0, float v = 0);
		glm::vec3 pos;
		glm::vec3 normal;
		float u;
		float v;
		
		void Transform(const glm::mat4 & transform);
		void Transform(const glm::mat4 & transform, const glm::mat3 & normalTransform);
		static const Vertex Interpolate_Tri(const glm::vec3 & abg, const Vertex & A, const Vertex & B, const Vertex & C);
	};

	struct HitRecord {
		HitRecord(const Ray::Ptr & ray = NULL, const glm::vec3 & pos = glm::vec3(0), const glm::vec3 & normal = glm::vec3(0,0,1), float u = 0, float v = 0);

		Ray::Ptr ray;
		Vertex vertex;
	};

	class Material : public CppUtility::Other::HeapObj{
		HEAP_OBJ_SETUP(Material)
	public:
		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(const HitRecord & rec) const = 0;
	};
}

#endif // !_MATERIAL_H_
