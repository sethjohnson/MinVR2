/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/nodes/graphics/structure/VRViewportNode.h>

namespace MinVR {

VRViewportNode::VRViewportNode(const VRRect& rect) : m_rectCalculator("viewport", true), m_rect(rect) {
}

VRViewportNode::~VRViewportNode() {
}

void VRViewportNode::render(VRRenderer& renderer) {
	//renderer.pushState();
	m_rectCalculator.calculate(renderer.getState(), m_rect);

	VRGraphicsWindowChild::render(renderer);
	//renderer.popState();
}

} /* namespace MinVR */
