#ifndef _GROUP_H_
#define _GROUP_H_

#include <RayTracing/Hitable.h>
#include <vector>

namespace RayTracing {
	class Group : public Hitable, public std::vector<Hitable::Ptr>{
		HEAP_OBJ_SETUP(Group)
	public:
		using Hitable::Hitable;

		// ���� true ˵�����߼�������
		// ���� false ˵�����ߴ�������
		virtual HitRst RayIn(Ray::Ptr & ray) const;
		Group & operator <<(const Hitable::Ptr & hitable);
		virtual AABB GetBoundingBox() const;
	};
}
#endif //!_GROUP_H_

