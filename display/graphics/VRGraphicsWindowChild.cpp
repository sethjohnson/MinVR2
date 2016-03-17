/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/VRGraphicsWindowChild.h>

namespace MinVR {

VRGraphicsWindowChild::VRGraphicsWindowChild() {
}

VRGraphicsWindowChild::~VRGraphicsWindowChild() {
}

VRGraphicsWindowChildNode::VRGraphicsWindowChildNode() {
}

VRGraphicsWindowChildNode::~VRGraphicsWindowChildNode() {
}

void VRGraphicsWindowChildNode::addChild(VRGraphicsWindowChild* child) {
	VRDisplayNode::addChild(child);
}


} /* namespace MinVR */
