/*
 * In this case we have 2 Common classes merged together
 */


struct Common {
	int i;
};

struct Base1 : Common {};
struct Base2 : virtual Common {};
struct Base3 : virtual Common {};

struct Derived : Base1, Base2, Base3 {};

int main() {}
