/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRRENDERSTATE_H_
#define VRRENDERSTATE_H_

#include "config/VRDataIndex.h"
#include "config/VRWritable.h"

namespace MinVR {

/*
 * VRRenderState has functions which help control the current state using a VRDataIndex.
 * It has a current namespace which allows quick access to variables at differing namespace
 * levels inside the VRDataIndex.
 */
class VRRenderState {
public:
	VRRenderState();
	virtual ~VRRenderState();

	// Returns the data index
	VRDataIndex& getDataIndex();

	// Gets and sets the current namespace
	const std::string& getNameSpace() const;
	void setNameSpace(const std::string& nameSpace);

	//--------- Methods for reading and writting values to the VRDataIndex: ---------
	// Reads a writable value which handles its own serialization of basic types
	bool readValue(std::string name, VRWritable& writable);
	// Writes a writable value which handles its own serialization of basic types
	void writeValue(std::string name, const VRWritable& writable);
	// Returns the value of any core type
	VRAnyCoreType getValue(std::string name);
	// Gets the value with a VRAnyCoreType specified
	template<typename T>
	T getValue(std::string name, const T& defaultValue);
	// Sets the value of any VRAnyCoreType
	template<typename T>
	void setValue(std::string name, T val);

private:
	VRDataIndex m_index;
	std::string m_nameSpace;
};

//-------------- VRRenderState template method implementations ---------------

template<typename T>
T VRRenderState::getValue(std::string name, const T& defaultValue)
{
	if (!m_index.exists(name, m_nameSpace))
	{
		return defaultValue;
	}

	return getValue(name);
}

template<typename T>
void VRRenderState::setValue(std::string name, T val)
{
	m_index.addData(m_nameSpace + "/" + name, val);
}

} /* namespace MinVR */

#endif /* VRRENDERSTATE_H_ */
