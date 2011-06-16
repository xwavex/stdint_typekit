#ifndef ORO_STDINT_TYPEKIT_HPP
#define ORO_STDINT_TYPEKIT_HPP

#include <map>
#include <string>

#include <rtt/types/TypekitPlugin.hpp>

namespace RTT {
namespace types {

/**
 * This plugin defines standard int types from stdint.h
 */
class StdintTypekitPlugin: public RTT::types::TypekitPlugin {
public:
	typedef std::map<std::string, bool> alias_map_t;
	static alias_map_t aliased;
	//
	virtual std::string getName();
	virtual bool loadTypes();
	virtual bool loadConstructors();
	virtual bool loadOperators();
private:
	/** RTT Type info repository owning types. */
	TypeInfoRepository::shared_ptr ti;
	/** Function adding the type to the repository.
	 * If the type already exists, it is aliased.
	 */
	template<typename T>
	bool addTypeOrAlias(const std::string name);
};

}
}

#endif

