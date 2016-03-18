/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRVIEWPORTNODE_H_
#define VRVIEWPORTNODE_H_

#include "display/graphics/VRGraphicsWindowChild.h"
#include "VRRect.h"
#include "VRRectCalculator.h"

namespace MinVR {

class VRViewportNode : public VRGraphicsWindowChildNode {
public:
	VRViewportNode(const VRRect& rect);
	virtual ~VRViewportNode();

	void render(VRRenderer& renderer);

private:
	VRRectCalculator m_rectCalculator;
	VRRect m_rect;
};

} /* namespace MinVR */

#endif /* VRVIEWPORTNODE_H_ */
