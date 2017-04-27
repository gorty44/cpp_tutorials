class Other {
	int j = 3;
	friend class Test;
};


class Test {
	int i;

	public:
		int get_a_value() const {
			struct Inner {
				Inner(Other& o) : m_o(o) {}
				int get_other_value() { return m_o.j; }
				private:
					Other& m_o;
			};

			Other o;
			Inner i(o);
			return i.get_other_value();
		}
};

int main() {
	Test t;
	return t.get_a_value();
}
