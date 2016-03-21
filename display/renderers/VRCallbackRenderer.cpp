/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/renderers/VRCallbackRenderer.h>

namespace MinVR {

VRCallbackRenderer::VRCallbackRenderer(MethodType render, MethodType update) {
	m_renderMethod = render;
	m_updateMethod = update;
}

VRCallbackRenderer::~VRCallbackRenderer() {
}

void VRCallbackRenderer::updateFrame(VRRenderState& state) {
	if (m_updateMethod != NULL)
	{
		(*m_updateMethod)(state);
	}
}

void VRCallbackRenderer::render(VRRenderState& state) {
	(*m_renderMethod)(state);
}

} /* namespace MinVR */
