/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/VRGraphicsRenderNode.h>

namespace MinVR {

VRGraphicsRenderNode::VRGraphicsRenderNode() {
	// TODO Auto-generated constructor stub

}

VRGraphicsRenderNode::~VRGraphicsRenderNode() {
	// TODO Auto-generated destructor stub
}

void VRGraphicsRenderNode::render(VRRenderer& renderer) {
	std::cout << "Render" << std::endl;
	renderer.render();
}

} /* namespace MinVR */
