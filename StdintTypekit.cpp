#include <stdint.h>

#include <rtt/typekit/StdTypeInfo.hpp>

#include "StdintTypekit.hpp"

namespace RTT {
namespace types {

std::string StdintTypekitPlugin::getName() { return "stdint-typekit"; }

bool StdintTypekitPlugin::loadTypes() {
	// Signed integers
	RTT::types::Types()->addType( new StdTypeInfo<int_least8_t>("int8") );
	RTT::types::Types()->addType( new StdTypeInfo<int_least16_t>("int16") );
	RTT::types::Types()->addType( new StdTypeInfo<int_least32_t>("int32") );
	RTT::types::Types()->addType( new StdTypeInfo<int_least64_t>("int64") );
	// Unsigned integers
	RTT::types::Types()->addType( new StdTypeInfo<uint_least8_t>("uint8") );
	RTT::types::Types()->addType( new StdTypeInfo<uint_least16_t>("uint16") );
	RTT::types::Types()->addType( new StdTypeInfo<uint_least32_t>("uint32") );
	RTT::types::Types()->addType( new StdTypeInfo<uint_least64_t>("uint64") );
}  

bool StdintTypekitPlugin::loadConstructors() {
}

bool StdintTypekitPlugin::loadOperators() {
}

}} // namespaces

ORO_TYPEKIT_PLUGIN( RTT::types::StdintTypekitPlugin ); 
