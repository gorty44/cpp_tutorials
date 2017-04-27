class Base {
	virtual void do_something() const { }
};

class Intermediate : public Base {
	void do_something() const override final { }
};

class Derived : public Intermediate {
	void do_something() const override { }
	void do_something_else() const final { }
};

int main() {} 
