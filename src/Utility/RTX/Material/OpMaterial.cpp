#include <Utility/RTX/OpMaterial.h>

using namespace RayTracing;
using namespace glm;
using namespace std;

OpMaterial::OpMaterial(const function<bool(const HitRecord & rec)> & op)
	: op(op){ }

bool OpMaterial::Scatter(const HitRecord & rec) const {
	if (op == NULL)
		return false;

	return op(rec);
}