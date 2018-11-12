#ifndef _MATH_H_
#define _MATH_H_

#include <glm/glm.hpp>

namespace CppUtility {
	namespace Other {
		typedef glm::vec3 rgb;
		namespace Math {
			const float EPSILON = 10e-6;

			glm::vec2 RandInCircle();

			glm::vec3 RandInSphere();

			//-0x7FFFFFFFF -- 0x7FFFFFFF
			int Rand_I();

			//0 -- 0xFFFFFFFF
			unsigned int Rand_UI();

			//0.0f -- 1.0f
			float Rand_F();

			//0.0 -- 1.0
			double Rand_D();

			float Gray(const glm::vec3 & color);

			// ����
			// rationNiNt ������֮�� == Ni / Nt
			//     Ni Ϊ ����������ڽ��ʵ�������
			//     Nt Ϊ ����������ڽ��ʵ�������
			bool Refract(const glm::vec3 & viewDir, const glm::vec3 & normal, float ratioNiNt, glm::vec3 & refractDir);

			// ������
			// viewDir Ϊ ���߷���(����㵽�ӵ�ķ���)
			// halfway Ϊ ���߷�������߷����ƽ��
			// rationNtNi ������֮�� == Nt / Ni
			//     Ni Ϊ ����������ڽ��ʵ�������
			//     Nt Ϊ ����������ڽ��ʵ�������
			float FresnelSchlick(const glm::vec3 & viewDir, const glm::vec3 & halfway, float ratioNtNi);
		}
	}
}

#endif // !_MATH_H_
