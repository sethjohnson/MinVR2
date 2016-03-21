/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/nodes/graphics/structure/VRViewportNode.h>
#include "VRTile.h"

namespace MinVR {

VRViewportNode::VRViewportNode(const VRRect& rect) : m_rect(rect) {
}

VRViewportNode::~VRViewportNode() {
}

void VRViewportNode::render(VRRenderer& renderer) {
	calculate("viewport", renderer.getState(), m_rect, true);

	VRGraphicsWindowChild::render(renderer);
}

VRRect VRViewportNode::calculate(std::string inName, std::string outName,
		VRRenderState& state, const VRRect& rect, bool modifyTile) {
	const VRRect* currentRect = &rect;

	VRRect oldRect;
	VRRect modifiedRect;
	if (state.readValue(inName, oldRect))
	{
		modifiedRect = oldRect.generateChild(rect);
		currentRect = &modifiedRect;
	}

	if (modifyTile)
	{
		VRTile tile;
		if (state.readValue("tile", tile))
		{
			tile = tile.modifyWithRect(oldRect, *currentRect);
			state.writeValue("tile", tile);
		}
	}

	state.writeValue(outName, *currentRect);

	return *currentRect;
}

VRRect VRViewportNode::calculate(std::string inName, VRRenderState& state,
		const VRRect& rect, bool modifyTile) {
	calculate(inName, inName, state, rect, modifyTile);
}

} /* namespace MinVR */
