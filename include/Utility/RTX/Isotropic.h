#ifndef _ISOTROPIC_H_
#define _ISOTROPIC_H_

#include <Utility/RTX/Material.h>

namespace RayTracing {
	class Texture;

	class Isotropic : public Material{
		MATERIAL_SETUP(Isotropic)
	public:
		Isotropic(const glm::rgb & color);

		// ����ֵΪ true ˵�����߼�������
		// ����ֵΪ false ˵�����߲��ٴ���
		virtual bool Scatter(const HitRecord & rec) const;
		const CppUtility::Other::CPtr<Texture> GetTexture() const { return tex; }
	protected:
		CppUtility::Other::CPtr<Texture> tex;
	};
}

#endif // !_ISOTROPIC_H_
