/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRCALLBACKRENDERER_H_
#define VRCALLBACKRENDERER_H_

#include "display/renderers/VRBasicRenderer.h"

namespace MinVR {

/*
 * VRCallbackRenderer is a simple renderer which takes two function callback pointers as input.
 * These functions are registered as callback functions for the VRRenderer.  The state is controlled
 * in the VRBasicRenderer subclass.
 */
class VRCallbackRenderer : public VRBasicRenderer {
public:
	typedef void (*MethodType)(VRRenderState&);

	VRCallbackRenderer(MethodType render, MethodType update = NULL);
	virtual ~VRCallbackRenderer();

	void updateFrame(VRRenderState& state);
	void render(VRRenderState& state);

private:
	MethodType m_renderMethod;
	MethodType m_updateMethod;
};

} /* namespace MinVR */

#endif /* VRFUNCTIONRENDERCALLBACK_H_ */
