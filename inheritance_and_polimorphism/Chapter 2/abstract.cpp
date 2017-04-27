class Base {
	virtual void do_something() const = 0;
};

class Derived : public Base {
	void do_something() const { }
};

int main() {
	Base b;
}
