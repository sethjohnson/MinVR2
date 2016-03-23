/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRSCOPENODE_H_
#define VRSCOPENODE_H_

#include "display/VRDisplayNode.h"

namespace MinVR {

class VRScopeNode : public VRDisplayNode  {
public:
	VRScopeNode() {}
	virtual ~VRScopeNode() {}

	void render(VRRenderHandler& renderer) {
		renderer.pushState();
		VRDisplayNode::render(renderer);
		renderer.popState();
	}
};

} /* namespace MinVR */

#endif /* VRSCOPENODE_H_ */
