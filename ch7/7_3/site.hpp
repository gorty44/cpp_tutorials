#ifndef SITE_HPP_
#define SITE_HPP_

#include <string>

class Site {
	public:
		Site() : _name("") {}
		Site(const Site& rhs) : _name(rhs._name) {}
		Site(int _nam_sz, std::string _name) : _nam_sz(_nam_sz), _name(_name) {}
		std::string name() const {
			return this->_name;
		}
		~Site() {}

		void set_name(std::string name) {
			this->_name = name;
		}
	private:
		int _nam_sz;
		std::string _name;
};

#endif
