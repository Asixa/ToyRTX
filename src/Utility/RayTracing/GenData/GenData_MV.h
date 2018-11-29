#ifndef _GEN_FS_MV_H_
#define _GEN_FS_MV_H_

#include <RayTracing/MatVisitor.h>

#include <Utility/Ptr.h>

#include <vector>
#include <map>

namespace RayTracing {
	class Texture;
	class GenData_TV;

	// Generate Fragmen Shader -- Material Visitor
	class GenData_MV : public MatVisitor{
		HEAP_OBJ_SETUP(GenData_MV)
	public:
		typedef std::map<CppUtility::Other::CPtr<Material>, size_t> MatIdxMap;
		typedef std::map<CppUtility::Other::CPtr<Texture>, size_t> TexIdxMap;

		void Accept(const CppUtility::Other::Ptr<GenData_TV> & genFS_TV);
		const MatIdxMap & GetMatIdxMap() const { return mat2idx; }
		const std::vector<float> & GetMatData() const { return matData; };
	private:
		void SetTex(const TexIdxMap & tex2idx);

		virtual void Visit(const CppUtility::Other::CPtr<Lambertian> & lambertian);
		virtual void Visit(const CppUtility::Other::CPtr<Metal> & metal);
		virtual void Visit(const CppUtility::Other::CPtr<Dielectric> & dielectric);
		virtual void Visit(const CppUtility::Other::CPtr<Light> & light);
		using MatVisitor::Visit;

		std::vector<float> matData;
		std::map<CppUtility::Other::CPtr<Texture>, std::vector<size_t>> tex2idxVec;
		MatIdxMap mat2idx;
	};
}

#endif // !_GEN_FS_HV_H_
