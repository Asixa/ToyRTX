#ifndef _AABB_H_
#define _AABB_H_

#include <Utility/Ptr.h>

#include <glm/glm.hpp>

namespace RayTracing {
	class Ray;

	class AABB {
	public:
		AABB();
		AABB(const glm::vec3 & minP, const glm::vec3 & maxP, bool isValid = true);

		inline glm::vec3 GetMinP() const { return minP; }
		inline glm::vec3 GetMaxP() const { return maxP; }
		inline glm::vec3 GetCenter() const { return (minP + maxP) / 2.0f; }
		inline float GetRadius() const { return length(maxP - minP) / 2.0f; }

		// ���ú�Ὣ isValid ���ó� true
		void SetP(const glm::vec3 & minP, const glm::vec3 & maxP);
		inline bool IsValid() const { return isValid; }
		bool Hit(const CppUtility::Other::Ptr<Ray> & ray) const;

		const AABB operator +(const AABB & aabb) const;
		AABB & operator +=(const AABB & aabb);

		static const AABB InValid;
	private:
		bool isValid;
		glm::vec3 minP;
		glm::vec3 maxP;
	};
}

#endif // !_AABB_H_

