#include <iostream>


struct Angle {
	static Angle degrees(const double degrees) {
		return Angle(degrees);
	}
	static Angle radian(const double radians) {
		return Angle(radians * 180.0 / 3.14);
	}

	int get_degrees() {
		return this->m_degrees;
	}

	private:
		Angle(const double degrees) : m_degrees(degrees) {}
		double m_degrees;
};

int main() {
	Angle a = Angle::degrees(15);
	std::cout << a.get_degrees() << std::endl;
}
