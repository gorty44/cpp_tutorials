#ifndef _US_ADDRESS_
#define _US_ADDRESS_

#include <string>

#include "_address.hpp"
#include "_state_abbrev.hpp"

class _us_address : public _address {
	public:
		_us_address() {}
		_us_address(const _us_address& rhs) : _address(rhs), _state(rhs._state), _zip(rhs._zip) {}
		_us_address(std::string s1, std::string s2,
			       	std::string c, StateAbbrev s,
			       	std::string z) : _address(s1, s2, c),  _state(s), _zip(z) {}
		virtual ~_us_address() {}
		
		_us_address& operator=(const _us_address& rhs) {
			_address::operator=(rhs);

			if (&rhs != this) {
				_state = rhs._state;
				_zip = rhs._zip;
			}

			return *this;
		}

		StateAbbrev state() const { return _state; }
		std::string zip() const { return _zip; }

		std::string to_string() const override { return ""; }
		
	private:
		StateAbbrev _state;
		std::string _zip;
};

#endif // _US_ADDRESS_ 
