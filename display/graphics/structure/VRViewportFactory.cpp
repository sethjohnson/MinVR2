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

VRViewportFactory::VRViewportFactory(VRSystem* vrSystem, VRDisplayFactory* innerFactory) : m_vrSystem(vrSystem), m_innerFactory(innerFactory) {
}

VRViewportFactory::~VRViewportFactory() {
	delete m_innerFactory;
}

VRDisplay* VRViewportFactory::create(VRDataIndex& config,
		const std::string nameSpace) {

	VRDisplay* mainDisplay = m_innerFactory->create(config, nameSpace);
	VRGraphicsWindowChildNode* display = NULL;

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

	if (display)
	{
		VRGraphicsWindowChild* child = dynamic_cast<VRGraphicsWindowChild*>(mainDisplay);
		if (child)
		{
			display->addChild(child);
		}
		else
		{
			VRDisplayNode::createChildren<VRGraphicsWindowChildNode, VRGraphicsWindowChild>(tileNode, m_vrSystem->getDisplayFactory(), config, nameSpace);
		}

		return display;
	}

	return mainDisplay;
}

} /* namespace MinVR */
