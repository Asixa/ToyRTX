#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <RayTracing/Hitable.h>

namespace RayTracing {
	class Transform : public Hitable {
		HITABLE_SETUP(Transform)
	public:
		// ��� material ��Ϊ��, �򸲸��ӽڵ�� material
		Transform(const glm::mat4 & transform, Hitable::CPtr hitable, Material::CPtr material = NULL);

		virtual HitRst RayIn(CppUtility::Other::Ptr<Ray> & ray) const;
		virtual const AABB GetBoundingBox() const { return box; }
		const glm::mat4 GetTransform() const { return transform; }
		const glm::mat4 GetInvTransform() const { return inverseTransform; }
		const glm::mat3 GetNormTransform() const { return normalTransform; }
		const Hitable::CPtr GetChild() const { return hitable; }
	private:
		//���Ҫ�޸�transform, ��Ҫͬʱ���� inverseTransform �� normalTransform
		glm::mat4 transform;
		glm::mat4 inverseTransform;
		glm::mat3 normalTransform;

		Hitable::CPtr hitable;
		AABB box;
	};
}

#endif // !_TRANSFORM_H_
