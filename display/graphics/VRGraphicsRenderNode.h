/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRGRAPHICSRENDERDNODE_H_
#define VRGRAPHICSRENDERDNODE_H_

#include "display/graphics/VRGraphicsWindowChild.h"

namespace MinVR {

class VRGraphicsRenderNode : public VRGraphicsWindowChild {
public:
	VRGraphicsRenderNode();
	virtual ~VRGraphicsRenderNode();

	void render(VRRenderer& renderer);
};

} /* namespace MinVR */

#endif /* VRGRAPHICSRENDERDISPLAY_H_ */
