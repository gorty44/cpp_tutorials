#ifndef _WEB_ADDRESS_HPP_
#define _WEB_ADDRESS_HPP_

#include <string>
#include "_address.hpp"


class _web_address : public _address {
	public:
		_web_address() {}
		_web_address(const _web_address& rhs) : _address(rhs), _uri(rhs._uri) {}
		_web_address(std::string e) : _uri(e) {}
		virtual ~_web_address() {}

		_web_address& operator=(const _web_address& rhs) {
			_address::operator=(rhs);

			if (&rhs != this) {
				_uri = rhs._uri;
			}

			return *this;
		}

		std::string to_string() const override { return _uri; }

	private:
		std::string _uri;
};

#endif // _WEB_ADDRESS_HPP_
