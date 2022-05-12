#pragma once
namespace Util {
	template <typename T>
	class Tuple {
		T left;
		T right;
	public:
		Tuple(T left, T right) {
			this->left = left;
			this->right = right;
		}
	};
}