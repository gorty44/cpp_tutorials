class Base {
	virtual void do_something() const { }
};

class Derived : public Base {
	void do_something() const override { }
};

int main() { }
