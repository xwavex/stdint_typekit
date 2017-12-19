/***************************************************************************

                            StdintTypekit.cpp
                           -------------------
    project              : Orocos Toolchain
    package              : stdint-typekit
    author               : Charles Lesire-Cabaniols
    copyright            : (C) 2011 Onera - the French Aerospace Lab
    email                : charles.lesire@onera.fr

 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

#include <stdint.h>
#include <boost/assign.hpp>
#include <boost/lexical_cast.hpp>

#include <rtt/typekit/StdTypeInfo.hpp>
#include <rtt/types/TemplateConstructor.hpp>
#include <rtt/types/Operators.hpp>
#include <rtt/types/OperatorTypes.hpp>
#include <rtt/internal/mystd.hpp>

#include "StdintTypekit.hpp"

namespace RTT {
namespace types {

StdintTypekitPlugin::alias_map_t StdintTypekitPlugin::aliased =
		boost::assign::map_list_of("int8", false)("int16", false)("int32",
				false)("int64", false)("uint8", false)("uint16", false)(
				"uint32", false)("uint64", false);

std::string StdintTypekitPlugin::getName() {
	return "stdint-typekit";
}

template<typename T>
bool StdintTypekitPlugin::addTypeOrAlias(const std::string name) {
    log(Debug) << "addTypeOrAlias<" << typeid(T).name() << ">(" << name << ")" << endlog();
	// Note: TypeInfoRepository::addType() adds an alias automatically if the type is already registered.
	return ti->addType(new StdTypeInfo<T> (name.c_str()));
}

bool StdintTypekitPlugin::loadTypes() {
	ti = TypeInfoRepository::Instance();

	// Signed integers
#ifdef ADD_INT8_TYPE
	if (!addTypeOrAlias<int_least8_t> ("int8")) {
		log(Error) << "Unable to define (add or alias) type 'int8'" << endlog();
		return false;
	}
#endif
	if (!addTypeOrAlias<int_least16_t> ("int16")) {
		log(Error) << "Unable to define (add or alias) type 'int16'"
				<< endlog();
		return false;
	}
	if (!addTypeOrAlias<int_least32_t> ("int32")) {
		log(Error) << "Unable to define (add or alias) type 'int32'"
				<< endlog();
		return false;
	}
	if (!addTypeOrAlias<int_least64_t> ("int64")) {
		log(Error) << "Unable to define (add or alias) type 'int64'"
				<< endlog();
		return false;
	}

	// Unsigned integers
#ifdef ADD_INT8_TYPE
	if (!addTypeOrAlias<uint_least8_t> ("uint8")) {
		log(Error) << "Unable to define (add or alias) type 'uint8'"
		<< endlog();
		return false;
	}
#endif
	if (!addTypeOrAlias<uint_least16_t> ("uint16")) {
		log(Error) << "Unable to define (add or alias) type 'uint16'"
				<< endlog();
		return false;
	}
	if (!addTypeOrAlias<uint_least32_t> ("uint32")) {
		log(Error) << "Unable to define (add or alias) type 'uint32'"
				<< endlog();
		return false;
	}
	if (!addTypeOrAlias<uint_least64_t> ("uint64")) {
		log(Error) << "Unable to define (add or alias) type 'uint64'"
				<< endlog();
		return false;
	}

	return true;
}

bool StdintTypekitPlugin::loadConstructors() {
	// int8
#ifdef ADD_INT8_TYPE
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, int_least16_t> , false));
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, int_least32_t> , false));
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, int_least64_t> , false));
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, uint_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, uint_least16_t> , false));
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, uint_least32_t> , false));
	ti->type("int8")->addConstructor(newConstructor(boost::lexical_cast<int_least8_t, uint_least64_t> , false));
#endif
	// int16
#ifdef ADD_INT8_TYPE
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, int_least8_t> , false));
#endif
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, int_least32_t> , false));
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, int_least64_t> , false));
#ifdef ADD_INT8_TYPE
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, uint_least8_t> , false));
#endif
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, uint_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, uint_least32_t> , false));
	ti->type("int16")->addConstructor(newConstructor(boost::lexical_cast<int_least16_t, uint_least64_t> , false));
	// int32
#ifdef ADD_INT8_TYPE
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, int_least8_t> , false));
#endif
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, int_least16_t> , false));
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, int_least64_t> , false));
#ifdef ADD_INT8_TYPE
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, uint_least8_t> , false));
#endif
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, uint_least16_t> , false));
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, uint_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(boost::lexical_cast<int_least32_t, uint_least64_t> , false));
	// int64
#ifdef ADD_INT8_TYPE
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, int_least8_t> , false));
#endif
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, int_least16_t> , false));
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, int_least32_t> , false));
#ifdef ADD_INT8_TYPE
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, uint_least8_t> , false));
#endif
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, uint_least16_t> , false));
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, uint_least32_t> , false));
	ti->type("int64")->addConstructor(newConstructor(boost::lexical_cast<int_least64_t, uint_least64_t> , false));
	// uint8
#ifdef ADD_INT8_TYPE
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, int_least16_t> , false));
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, int_least32_t> , false));
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, int_least64_t> , false));
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, int_least8_t> , false));
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, uint_least16_t> , false));
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, uint_least32_t> , false));
	ti->type("uint8")->addConstructor(newConstructor(boost::lexical_cast<uint_least8_t, uint_least64_t> , false));
#endif
	// uint16
#ifdef ADD_INT8_TYPE
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, int_least8_t> , false));
#endif
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, int_least32_t> , false));
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, int_least64_t> , false));
#ifdef ADD_INT8_TYPE
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, uint_least8_t> , false));
#endif
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, int_least16_t> , false));
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, uint_least32_t> , false));
	ti->type("uint16")->addConstructor(newConstructor(boost::lexical_cast<uint_least16_t, uint_least64_t> , false));
	// uint32
#ifdef ADD_INT8_TYPE
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, int_least8_t> , false));
#endif
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, int_least16_t> , false));
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, int_least64_t> , false));
#ifdef ADD_INT8_TYPE
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, uint_least8_t> , false));
#endif
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, uint_least16_t> , false));
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, int_least32_t> , false));
	ti->type("uint32")->addConstructor(newConstructor(boost::lexical_cast<uint_least32_t, uint_least64_t> , false));
	// uint64
#ifdef ADD_INT8_TYPE
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, int_least8_t> , false));
#endif
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, int_least16_t> , false));
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, int_least32_t> , false));
#ifdef ADD_INT8_TYPE
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, uint_least8_t> , false));
#endif
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, uint_least16_t> , false));
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, uint_least32_t> , false));
	ti->type("uint64")->addConstructor(newConstructor(boost::lexical_cast<uint_least64_t, int_least64_t> , false));

	return true;
}

bool StdintTypekitPlugin::loadOperators() {
	OperatorRepository::shared_ptr oreg = OperatorRepository::Instance();
	using namespace internal;
	// int8
#ifdef ADD_INT8_TYPE
	if (!aliased["int8"]) {
		oreg->add(newUnaryOperator("-", std::negate<int_least8_t>()));
		oreg->add(newUnaryOperator("+", identity<int_least8_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<int_least8_t>()));
		oreg->add(newBinaryOperator("/", divides3<int_least8_t, int_least8_t,
						int_least8_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<int_least8_t>()));
		oreg->add(newBinaryOperator("+", std::plus<int_least8_t>()));
		oreg->add(newBinaryOperator("-", std::minus<int_least8_t>()));
		oreg->add(newBinaryOperator("<", std::less<int_least8_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<int_least8_t>()));
		oreg->add(newBinaryOperator(">", std::greater<int_least8_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<int_least8_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<int_least8_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<int_least8_t>()));
	}
	// uint8
	if (!aliased["uint8"]) {
		oreg->add(newUnaryOperator("+", identity<uint_least8_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<uint_least8_t>()));
		oreg->add(newBinaryOperator("/", divides3<uint_least8_t, uint_least8_t,
						uint_least8_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<uint_least8_t>()));
		oreg->add(newBinaryOperator("+", std::plus<uint_least8_t>()));
		oreg->add(newBinaryOperator("-", std::minus<uint_least8_t>()));
		oreg->add(newBinaryOperator("<", std::less<uint_least8_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<uint_least8_t>()));
		oreg->add(newBinaryOperator(">", std::greater<uint_least8_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<uint_least8_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<uint_least8_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<uint_least8_t>()));
	}
#endif
	// int16
	if (!aliased["int16"]) {
		oreg->add(newUnaryOperator("-", std::negate<int_least16_t>()));
		oreg->add(newUnaryOperator("+", identity<int_least16_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<int_least16_t>()));
		oreg->add(newBinaryOperator("/", divides3<int_least16_t, int_least16_t,
						int_least16_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<int_least16_t>()));
		oreg->add(newBinaryOperator("+", std::plus<int_least16_t>()));
		oreg->add(newBinaryOperator("-", std::minus<int_least16_t>()));
		oreg->add(newBinaryOperator("<", std::less<int_least16_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<int_least16_t>()));
		oreg->add(newBinaryOperator(">", std::greater<int_least16_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<int_least16_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<int_least16_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<int_least16_t>()));
	}
	// uint16
	if (!aliased["uint16"]) {
		oreg->add(newUnaryOperator("+", identity<uint_least16_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<uint_least16_t>()));
		oreg->add(newBinaryOperator("/", divides3<uint_least16_t, uint_least16_t,
						uint_least16_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<uint_least16_t>()));
		oreg->add(newBinaryOperator("+", std::plus<uint_least16_t>()));
		oreg->add(newBinaryOperator("-", std::minus<uint_least16_t>()));
		oreg->add(newBinaryOperator("<", std::less<uint_least16_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<uint_least16_t>()));
		oreg->add(newBinaryOperator(">", std::greater<uint_least16_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<uint_least16_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<uint_least16_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<uint_least16_t>()));
	}
	
	// int32
	if (!aliased["int32"]) {
		oreg->add(newUnaryOperator("-", std::negate<int_least32_t>()));
		oreg->add(newUnaryOperator("+", identity<int_least32_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<int_least32_t>()));
		oreg->add(newBinaryOperator("/", divides3<int_least32_t, int_least32_t,
						int_least32_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<int_least32_t>()));
		oreg->add(newBinaryOperator("+", std::plus<int_least32_t>()));
		oreg->add(newBinaryOperator("-", std::minus<int_least32_t>()));
		oreg->add(newBinaryOperator("<", std::less<int_least32_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<int_least32_t>()));
		oreg->add(newBinaryOperator(">", std::greater<int_least32_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<int_least32_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<int_least32_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<int_least32_t>()));
	}
	// uint32
	if (!aliased["uint32"]) {
		oreg->add(newUnaryOperator("+", identity<uint_least32_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<uint_least32_t>()));
		oreg->add(newBinaryOperator("/", divides3<uint_least32_t, uint_least32_t,
						uint_least32_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<uint_least32_t>()));
		oreg->add(newBinaryOperator("+", std::plus<uint_least32_t>()));
		oreg->add(newBinaryOperator("-", std::minus<uint_least32_t>()));
		oreg->add(newBinaryOperator("<", std::less<uint_least32_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<uint_least32_t>()));
		oreg->add(newBinaryOperator(">", std::greater<uint_least32_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<uint_least32_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<uint_least32_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<uint_least32_t>()));
	}
	
	// int64
	if (!aliased["int64"]) {
		oreg->add(newUnaryOperator("-", std::negate<int_least64_t>()));
		oreg->add(newUnaryOperator("+", identity<int_least64_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<int_least64_t>()));
		oreg->add(newBinaryOperator("/", divides3<int_least64_t, int_least64_t,
						int_least64_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<int_least64_t>()));
		oreg->add(newBinaryOperator("+", std::plus<int_least64_t>()));
		oreg->add(newBinaryOperator("-", std::minus<int_least64_t>()));
		oreg->add(newBinaryOperator("<", std::less<int_least64_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<int_least64_t>()));
		oreg->add(newBinaryOperator(">", std::greater<int_least64_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<int_least64_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<int_least64_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<int_least64_t>()));
	}
	// uint64
	if (!aliased["uint64"]) {
		oreg->add(newUnaryOperator("+", identity<uint_least64_t> ()));
		oreg->add(newBinaryOperator("*", std::multiplies<uint_least64_t>()));
		oreg->add(newBinaryOperator("/", divides3<uint_least64_t, uint_least64_t,
						uint_least64_t> ())); // use our own divides<> which detects div by zero
		oreg->add(newBinaryOperator("%", std::modulus<uint_least64_t>()));
		oreg->add(newBinaryOperator("+", std::plus<uint_least64_t>()));
		oreg->add(newBinaryOperator("-", std::minus<uint_least64_t>()));
		oreg->add(newBinaryOperator("<", std::less<uint_least64_t>()));
		oreg->add(newBinaryOperator("<=", std::less_equal<uint_least64_t>()));
		oreg->add(newBinaryOperator(">", std::greater<uint_least64_t>()));
		oreg->add(newBinaryOperator(">=", std::greater_equal<uint_least64_t>()));
		oreg->add(newBinaryOperator("==", std::equal_to<uint_least64_t>()));
		oreg->add(newBinaryOperator("!=", std::not_equal_to<uint_least64_t>()));
	}

	return true;
}

}
} // namespaces

ORO_TYPEKIT_PLUGIN( RTT::types::StdintTypekitPlugin);
