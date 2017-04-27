#ifndef GENERIC_BUILDER_HPP_
#define GENERIC_BUILDER_HPP_

template<typename T>
struct NullAdapter {
	void operator()(T arg) {}
};


template<typename T, template <typename> class Adapter = NullAdapter>
struct GenericBuilder : public T {
	
	using value_type = typename T::value_type;

	GenericBuilder() {}
	virtual ~GenericBuilder() {}

	value_type build() override {
		_adapter(*this);
		return T::operator()();
	}

	private:
	Adapter<T> _adapter;
};


#endif // GENERIC_BUILDER_HPP_
