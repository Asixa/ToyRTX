#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <RayTracing/Material.h>
#include <RayTracing/Texture.h>

namespace RayTracing {
	class Light : public Material{
		HEAP_OBJ_SETUP(Light)
	public:
		Light(const glm::rgb & color);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(HitRecord & rec) const;
	private:
		Texture::CPtr lightTex;
	};
}

#endif // !_LIGHT_H_
