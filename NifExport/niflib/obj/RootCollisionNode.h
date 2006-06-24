/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ROOTCOLLISIONNODE_H_
#define _ROOTCOLLISIONNODE_H_

#include "NiNode.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class RootCollisionNode;
typedef Ref<RootCollisionNode> RootCollisionNodeRef;

/*!
 * RootCollisionNode - Morrowind-specific node for collision mesh.
 */

class NIFLIB_API RootCollisionNode : public ROOT_COLLISION_NODE_PARENT {
public:
	RootCollisionNode();
	~RootCollisionNode();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	ROOT_COLLISION_NODE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif