/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/nodes/graphics/VRGraphicsWindowNode.h>
#include "display/nodes/graphics/structure/VRViewportNode.h"

namespace MinVR {

VRGraphicsWindowNode::VRGraphicsWindowNode(const VRRect& rect) : m_rect(rect) {

}

VRGraphicsWindowNode::~VRGraphicsWindowNode() {
}

void VRGraphicsWindowNode::render(VRRenderer& renderer) {
	startRender(renderer);
	waitForRenderComplete();
	synchronize();
}

void VRGraphicsWindowNode::startRender(VRRenderer& renderer) {
	renderer.pushState();
	setCurrentContext();
	renderer.getState().setValue("graphicsContextType", getContextType());
	updateState(renderer.getState());
	renderer.updateFrame();
	VRGraphicsContextNode::render(renderer);
	flush();
	renderer.popState();
	clearCurrentContext();
}

void VRGraphicsWindowNode::waitForRenderComplete() {
	setCurrentContext();
	finish();
	clearCurrentContext();
}

void VRGraphicsWindowNode::synchronize() {
	setCurrentContext();
	swapBuffers();
	clearCurrentContext();
}

void VRGraphicsWindowNode::updateState(VRRenderState& state) {
	VRRect r = VRViewportNode::calculate("rect", "viewport", state, m_rect, true);
	r.setXOffset(0);
	r.setYOffset(0);
	state.writeValue("viewport", r);
}

const VRRect& VRGraphicsWindowNode::getRect() const {
	return m_rect;
}

void VRGraphicsWindowNode::setRect(const VRRect& rect) {
	m_rect = rect;
}

} /* namespace MinVR */
