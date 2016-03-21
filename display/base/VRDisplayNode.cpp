/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/base/VRDisplayNode.h>

using namespace std;

namespace MinVR {

VRDisplayNode::VRDisplayNode() {

}

VRDisplayNode::~VRDisplayNode() {
	clearChildrenInternal(true);
}

void VRDisplayNode::render(VRRenderer& renderer) {
	if (m_children.size() > 0)
	{
		for (vector<VRDisplay*>::iterator it = m_children.begin(); it != m_children.end(); it++)
		{
			(*it)->render(renderer);
		}
	}
	else
	{
		renderer.render();
	}
}

const std::vector<VRDisplay*>& VRDisplayNode::getChildren() const {
	return m_children;
}

void VRDisplayNode::addChildInternal(VRDisplay* child) {
	m_children.push_back(child);
}

void VRDisplayNode::insertChildInternal(VRDisplay* child, int index) {
	m_children.insert(m_children.begin() + index, child);
}

void VRDisplayNode::clearChildrenInternal(bool destroyChildren) {
	if (destroyChildren) {
		for (vector<VRDisplay*>::iterator it = m_children.begin(); it != m_children.end(); it++)
		{
				delete (*it);
		}
	}

	m_children.clear();
}


} /* namespace MinVR */
