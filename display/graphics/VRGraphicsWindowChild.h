/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRGRAPHICSWINDOWCHILD_H_
#define VRGRAPHICSWINDOWCHILD_H_

#include "display/VRDisplayNode.h"
#include "display/interfaces/graph/VRHasDisplayChildren.h"

namespace MinVR {

class VRGraphicsWindowChild : public VRDisplayNode {
public:
	VRGraphicsWindowChild();
	virtual ~VRGraphicsWindowChild();
};

class VRGraphicsWindowChildNode : public VRGraphicsWindowChild, public VRHasDisplayChildren<VRGraphicsWindowChild> {
public:
	VRGraphicsWindowChildNode();
	virtual ~VRGraphicsWindowChildNode();

	//virtual void addChild(VRGraphicsWindowChild* child);
};

} /* namespace MinVR */

#endif /* VRGRAPHICSWINDOWCHILD_H_ */
