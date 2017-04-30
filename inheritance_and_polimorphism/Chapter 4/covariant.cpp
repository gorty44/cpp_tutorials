struct Base {
	virtual Base& get_object() {
		return *this;
	}
};

struct Derived : Base {
	Derived& get_object() override {
		return *this;
	}
};

int main() { }
