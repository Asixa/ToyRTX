#ifndef _GROUP_H_
#define _GROUP_H_

#include <RayTracing/Hitable.h>
#include <vector>

namespace RayTracing {
	class Group : public Hitable{
		HITABLE_SETUP(Group)
	public:
		Group(const Material::CPtr & material = NULL);

		// ���� true ˵�����߼�������
		// ���� false ˵�����ߴ�������
		virtual HitRst RayIn(Ray::Ptr & ray) const;
		inline void push_back(const Hitable::CPtr & hitable) { (*this) << hitable; }
		Group & operator <<(const Hitable::CPtr & hitable);
		virtual const AABB GetBoundingBox() const { return box; }
		const std::vector<Hitable::CPtr> & GetChildren() const { return children; }
	private:
		std::vector<Hitable::CPtr> children;
		AABB box;
	};
}
#endif //!_GROUP_H_

