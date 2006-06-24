/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIAVOBJECT_H_
#define _NIAVOBJECT_H_

// Includes
#include "../gen/BoundingBox.h"
#include "../gen/obj_defines.h"
#include NI_A_V_OBJECT_INCLUDE
namespace Niflib {

// Forward define of referenced blocks
class NiProperty;
class NiCollisionData;
class NiCollisionObject;
class NiNode;


/*
 * NiAVObject - An audio/video object?  Part of the scene graph and has a position in 3D.
 */

class NiAVObject;
typedef Ref<NiAVObject> NiAVObjectRef;

class NIFLIB_API NiAVObject : public NI_A_V_OBJECT_PARENT {
public:
	NiAVObject();
	~NiAVObject();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;

	//TODO:  Bounding Box.  What to do with newer files that have a link?  Wrap this in a function and translate?
	
	/*! 
	 * This is a conveniance function that allows you to retrieve the full 4x4 matrix transform of a node.  It accesses the "Rotation," "Translation," and "Scale" attributes and builds a complete 4x4 transformation matrix from them.
	 * \return A 4x4 transformation matrix built from the node's transform attributes.
	 * \sa INode::GetWorldTransform
	 */
	Matrix44 GetLocalTransform() const;

	/*! 
	 * This function will return a transform matrix that represents the location of this node in world space.  In other words, it concatenates all parent transforms up to the root of the scene to give the ultimate combined transform from the origin for this node.
	 * \return The 4x4 world transform matrix of this node.
	 * \sa INode::GetLocalTransform
	 */
	Matrix44 GetWorldTransform() const;

	/*! Meant to be called by NiNode during the addition of new children.  Should not be called directly. */
	void SetParent( NiNode * new_parent );

	Ref<NiNode> GetParent() const;

	void AddProperty( Ref<NiProperty> & obj );
	void RemoveProperty( Ref<NiProperty> obj );
	void ClearProperties();
	vector< Ref<NiProperty> > GetProperties() const;
	Ref<NiProperty> GetPropertyByType( const Type & compare_to );

	ushort GetFlags() const;
	void SetFlags( ushort n );

	Matrix33 GetLocalRotation() const;
	void SetLocalRotation( const Matrix33 & n );

	Vector3 GetLocalTranslation() const;
	void SetLocalTranslation( const Vector3 & n );

	float GetLocalScale() const;
	void SetLocalScale( float n );

	Vector3 GetVelocity() const;
	void SetVelocity( const Vector3 & n );

	void SetCollisionObject(Ref<NiCollisionObject> &);

protected:
	NiNode * parent;
	NI_A_V_OBJECT_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif