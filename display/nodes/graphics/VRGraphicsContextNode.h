/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRGRAPHICSCONTEXTNODE_H_
#define VRGRAPHICSCONTEXTNODE_H_

#include "display/VRDisplayNode.h"

namespace MinVR {

class VRGraphicsContextChild;

typedef VREditableDisplayNode<VRGraphicsContextChild> VRGraphicsContextNode;

class VRGraphicsContextChild {
public:
	virtual ~VRGraphicsContextChild() {}
};

class VRGraphicsContextChildNode : public VRGraphicsContextNode, public VRGraphicsContextChild {
public:
	virtual ~VRGraphicsContextChildNode() {}
};

} /* namespace MinVR */

#endif /* VRGRAPHICSCONTEXTNODE_H_ */
