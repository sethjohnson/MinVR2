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

class VRRenderState {
public:
	VRRenderState();
	virtual ~VRRenderState();

	VRDataIndex& getDataIndex();
	const std::string& getNameSpace() const;
	void setNameSpace(const std::string& nameSpace);
	bool readValue(std::string name, VRWritable& writable);
	void writeValue(std::string name, const VRWritable& writable);
	VRAnyCoreType getValue(std::string name);

	template<typename T>
	T getValue(std::string name, const T& defaultValue);
	template<typename T>
	void setValue(std::string name, T val);

private:
	VRDataIndex m_index;
	std::string m_nameSpace;
};

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
