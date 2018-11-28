#ifndef _BVH_NODE_H_
#define _BVH_NODE_H_

#include <RayTracing/Hitable.h>
#include <vector>

namespace RayTracing {
	class BVH_Node : public Hitable{
		HITABLE_SETUP(BVH_Node)
	public:
		BVH_Node(const Material::CPtr & material = NULL);
		BVH_Node(std::vector<Hitable::CPtr> & hitables, const Material::CPtr & material = NULL);

		virtual HitRst RayIn(Ray::Ptr & ray) const;
		virtual const AABB GetBoundingBox() const { return box; }
		const Hitable::CPtr GetLeft() const { return left; }
		const Hitable::CPtr GetRight() const { return right; }
	protected:
		void Build(std::vector<Hitable::CPtr>::iterator begin, std::vector<Hitable::CPtr>::iterator end);
		size_t GetAxis(std::vector<Hitable::CPtr>::const_iterator begin, const std::vector<Hitable::CPtr>::const_iterator end) const;

		Hitable::CPtr left;
		Hitable::CPtr right;
		AABB box;
	};
}

#endif // !_BVH_NODE_H_
