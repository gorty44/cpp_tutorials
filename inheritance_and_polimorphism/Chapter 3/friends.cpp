struct MyClass {
	friend struct Base;

	private:
		int i;
};

struct Base {
	Base(const MyClass& m) {
		(void)m.i;
	}
	protected:
		int get_i(const MyClass& m) { // Now it's possible to have access to MyClass'es i from Derives class
			return m.i;
		}
};

struct Derived : Base { // derived class doesnt have access to Myclass'es field i, because it's not inheriting friendship from Base
	Derived(const MyClass& m) {
		(void)m.i;
	}
};

int main() { }
