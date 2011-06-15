#ifndef ORO_STDINT_TYPEKIT_HPP
#define ORO_STDINT_TYPEKIT_HPP

#include <rtt/types/TypekitPlugin.hpp>

namespace RTT {
namespace types {

	/**
	 * This interface defines standard int types from stdint.h
	 */
	class StdintTypekitPlugin : public RTT::types::TypekitPlugin {
	public:
		virtual std::string getName();
		virtual bool loadTypes();
		virtual bool loadConstructors();
		virtual bool loadOperators();
	};

}}

#endif

