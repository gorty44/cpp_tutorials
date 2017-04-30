struct Class1 {
	friend class Class2;

	private:
		int i;
};

struct Class2 {
	friend class Class3;
};

struct Class3 {
	Class3(const Class1& o) {
		(void)o.i; // its private in this context, frienship is not transitive!
	}
};

int main() { }
