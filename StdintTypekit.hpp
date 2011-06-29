/***************************************************************************

                            StdintTypekit.hpp
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

