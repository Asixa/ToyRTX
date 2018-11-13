#ifndef _RT_TEXTURE_H_
#define _RT_TEXTURE_H_

#include <Utility/HeapObj.h>

#include <glm/glm.hpp>

namespace RayTracing {
	class Texture : public CppUtility::Other::HeapObj {
		HEAP_OBJ_SETUP(Texture)
	public:
		virtual glm::rgb Value(float u = 0, float v = 0, const glm::vec3 & p = glm::vec3(0)) const = 0;
	};
}

#endif // !_RT_TEXTURE_H_
