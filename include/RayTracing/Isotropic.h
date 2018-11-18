#ifndef _ISOTROPIC_H_
#define _ISOTROPIC_H_

#include <RayTracing/Material.h>
#include <RayTracing/Texture.h>

namespace RayTracing {
	class Isotropic : public Material{
		HEAP_OBJ_SETUP(Isotropic)
	public:
		Isotropic(const glm::rgb & color);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(const HitRecord & rec) const;
	protected:
		Texture::CPtr tex;
	};
}

#endif // !_ISOTROPIC_H_
