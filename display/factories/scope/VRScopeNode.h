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
#include "display/interfaces/graph/VRHasDisplayChildren.h"

namespace MinVR {

template<class DisplayNodeType, typename ChildNodeType>
class VRScopeNode : public DisplayNodeType, public VRHasDisplayChildren<ChildNodeType>  {
public:
	VRScopeNode() : VRHasDisplayChildren<ChildNodeType>(this) {}
	virtual ~VRScopeNode() {}

	void render(VRRenderer& renderer) {
		renderer.pushState();
		VRDisplayNode::render(renderer);
		renderer.popState();
	}
};

} /* namespace MinVR */

#endif /* VRSCOPENODE_H_ */
