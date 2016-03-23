/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/renderers/VRRenderState.h>

namespace MinVR {

VRRenderState::VRRenderState() : m_nameSpace("") {
}

VRRenderState::~VRRenderState() {
}

VRDataIndex& VRRenderState::getDataIndex() {
	return m_index;
}

const std::string& VRRenderState::getNameSpace() const {
	return m_nameSpace;
}

void VRRenderState::setNameSpace(const std::string& nameSpace) {
	this->m_nameSpace = nameSpace;
}

bool VRRenderState::readValue(std::string name, VRWritable& writable)
{
	return writable.read(m_index, name, m_nameSpace);
}

void VRRenderState::writeValue(std::string name, const VRWritable& writable)
{
	writable.write(m_index, m_nameSpace + "/" + name);
}

VRAnyCoreType VRRenderState::getValue(std::string name)
{
	return m_index.getValue(name, m_nameSpace);
}

} /* namespace MinVR */
