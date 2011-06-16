#include <stdint.h>
#include <boost/assign.hpp>

#include <rtt/typekit/StdTypeInfo.hpp>
#include <rtt/types/Operators.hpp>
#include <rtt/types/TemplateConstructor.hpp>

#include "StdintTypekit.hpp"
#include "StdintConversions.hpp"

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
	TypeInfo* t = ti->getTypeInfo<T> ();
	if (t == NULL)
		return ti->addType(new StdTypeInfo<T> (name.c_str()));
	else {
		log(Warning) << "RTT type repository already knows type '" << name
				<< "' as type '" << t->getTypeName() << "'. Aliasing type '"
				<< t->getTypeName() << "'" << endlog();
		aliased[name] = true;
		return ti->aliasType(name, t);
	}
}

bool StdintTypekitPlugin::loadTypes() {
	ti = TypeInfoRepository::Instance();

	// Signed integers
	if (!addTypeOrAlias<int_least8_t> ("int8")) {
		log(Error) << "Unable to define (add or alias) type 'int8'" << endlog();
		return false;
	}
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
	if (!addTypeOrAlias<uint_least8_t> ("uint8")) {
		log(Error) << "Unable to define (add or alias) type 'uint8'"
				<< endlog();
		return false;
	}
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
	ti ->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			int_least16_t, int_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			int_least32_t, int_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			int_least64_t, int_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			uint_least8_t, int_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			uint_least16_t, int_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			uint_least32_t, int_least8_t> , false));
	ti->type("int8")->addConstructor(newConstructor(&convertIntTypes<
			uint_least64_t, int_least8_t> , false));
	// int16
	ti ->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			int_least8_t, int_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			int_least32_t, int_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			int_least64_t, int_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			uint_least8_t, int_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			uint_least16_t, int_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			uint_least32_t, int_least16_t> , false));
	ti->type("int16")->addConstructor(newConstructor(&convertIntTypes<
			uint_least64_t, int_least16_t> , false));
	// int32
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			int_least8_t, int_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			int_least16_t, int_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			int_least64_t, int_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			uint_least8_t, int_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			uint_least16_t, int_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			uint_least32_t, int_least32_t> , false));
	ti->type("int32")->addConstructor(newConstructor(&convertIntTypes<
			uint_least64_t, int_least32_t> , false));
	// int64
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			int_least8_t, int_least64_t> , false));
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			int_least16_t, int_least64_t> , false));
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			int_least32_t, int_least64_t> , false));
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			uint_least8_t, int_least64_t> , false));
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			uint_least16_t, int_least64_t> , false));
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			uint_least32_t, int_least64_t> , false));
	ti->type("int64")->addConstructor(newConstructor(&convertIntTypes<
			uint_least64_t, int_least64_t> , false));

	return true;
}

bool StdintTypekitPlugin::loadOperators() {
	return true;
}

}
} // namespaces

ORO_TYPEKIT_PLUGIN( RTT::types::StdintTypekitPlugin);
