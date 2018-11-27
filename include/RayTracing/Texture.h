#ifndef _RT_TEXTURE_H_
#define _RT_TEXTURE_H_

#include <Utility/HeapObj.h>

#include <glm/glm.hpp>

#include <RayTracing/TexVisitor.h>

#define TEXTURE_SETUP(CLASS) \
HEAP_OBJ_SETUP(CLASS)\
public:\
virtual void Accept(const TexVisitor::Ptr & texVisitor) const{\
	texVisitor->Visit(CThis());\
}

namespace RayTracing {
	class Texture : public CppUtility::Other::HeapObj {
		HEAP_OBJ_SETUP(Texture)
	public:
		virtual glm::rgb Value(float u = 0, float v = 0, const glm::vec3 & p = glm::vec3(0)) const = 0;
		virtual void Accept(const TexVisitor::Ptr & texVisitor) const = 0;
	};
}

#endif // !_RT_TEXTURE_H_
