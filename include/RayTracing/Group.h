#ifndef _GROUP_H_
#define _GROUP_H_

#include <RayTracing/Hitable.h>
#include <vector>

namespace RayTracing {
	class Group : public Hitable, public std::vector<CppUtility::Other::Ptr<Hitable>>{
		HEAP_OBJ_SETUP(Group)
	public:
		Group();

		// ���� true ˵�����߼�������
		// ���� false ˵�����ߴ�������
		virtual HitRst RayIn(Ray::Ptr & ray) const;
		Group & operator <<(const CppUtility::Other::Ptr<Hitable> & hitable);
		virtual AABB GetBoundingBox() const;
	};
}
#endif //!_GROUP_H_

