/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/structure/VRRectCalculator.h>
#include "VRTile.h"

namespace MinVR {

VRRectCalculator::VRRectCalculator(std::string inName, bool modifyTile) : m_modifyTile(modifyTile), m_inName(inName), m_outName(inName) {
}

VRRectCalculator::VRRectCalculator(std::string inName, std::string outName, bool modifyTile) : m_modifyTile(modifyTile), m_inName(inName), m_outName(outName) {
}

VRRectCalculator::~VRRectCalculator() {
}

VRRect VRRectCalculator::calculate(VRRenderState& state,
		const VRRect& rect) {

	const VRRect* currentRect = &rect;

	VRRect oldRect;
	VRRect modifiedRect;
	if (state.readValue(m_inName, oldRect))
	{
		modifiedRect = oldRect.generateChild(rect);
		currentRect = &modifiedRect;
	}

	if (m_modifyTile)
	{
		VRTile tile;
		if (state.readValue("tile", tile))
		{
			tile = tile.modifyWithRect(oldRect, *currentRect);
			state.writeValue("tile", tile);
		}
	}

	state.writeValue(m_outName, *currentRect);

	return *currentRect;
}

} /* namespace MinVR */
