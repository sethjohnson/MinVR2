/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/structure/VRViewportFactory.h>
#include "VRViewportNode.h"
#include "VRTileNode.h"

namespace MinVR {

VRViewportFactory::VRViewportFactory(VRSystem* vrSystem) : m_vrSystem(vrSystem) {
}

VRViewportFactory::~VRViewportFactory() {
}

VRDisplay* VRViewportFactory::create(VRDataIndex& config,
		const std::string nameSpace) {

	VRDisplay* display = NULL;

	//return display;

	VRViewport viewport;
	VRViewportNode* viewportNode = NULL;
	if (viewport.read(config, nameSpace + "/viewport", ""))
	{
		viewportNode = new VRViewportNode(viewport);
		display = viewportNode;
	}

	VRTile tile;
	VRTileNode* tileNode = NULL;
	if (tile.read(config, nameSpace + "/tile", ""))
	{
		tileNode = new VRTileNode(tile);

		if (viewportNode)
		{
			viewportNode->addChild(tileNode);
		}
		else
		{
			display = tileNode;
		}
	}

	if (tileNode)
	{
		VRDisplayNode::createChildren<VRTileNode, VRGraphicsWindowChild>(tileNode, m_vrSystem->getDisplayFactory(), config, nameSpace);
	}
	else if (viewportNode)
	{
		VRDisplayNode::createChildren<VRViewportNode, VRGraphicsWindowChild>(viewportNode, m_vrSystem->getDisplayFactory(), config, nameSpace);
	}

	return display;
}

} /* namespace MinVR */
