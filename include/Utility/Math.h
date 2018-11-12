#ifndef _MATH_H_
#define _MATH_H_

#include <glm/glm.hpp>
#include <vector>

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

			template <typename T>
			T Mean(const std::vector<T> & data) {
				if (data.size() == 0)
					return static_cast<T>(0);

				T sum = static_cast<T>(0);
				for (size_t i = 0; i < data.size(); i++)
					sum += data[i];

				return sum / data.size();
			}

			template<typename T>
			T Variance(const std::vector<T> & data) {
				if (data.size() <= 1)
					return static_cast<T>(0);

				T mean = Mean(data);
				T sum = static_cast<T>(0);
				for (size_t i = 0; i < data.size(); i++)
					sum += pow(data[i]-mean, 2);

				return sum / (data.size()-1);
			}
		}
	}
}

#endif // !_MATH_H_
