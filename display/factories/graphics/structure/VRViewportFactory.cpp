///*
// * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
// * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
// *
// * Code author(s):
// * 		Dan Orban (dtorban)
// */
//
//#include <display/factories/graphics/structure/VRViewportFactory.h>
//#include "display/nodes/graphics/structure/VRViewportNode.h"
//#include "display/nodes/graphics/structure/VRTileNode.h"
//#include "display/nodes/scope/VRStateScopeNode.h"
//
//namespace MinVR {
//
//VRViewportFactory::VRViewportFactory(VRSystem* vrSystem, VRDisplayFactory* innerFactory) : m_vrSystem(vrSystem), m_innerFactory(innerFactory) {
//}
//
//VRViewportFactory::~VRViewportFactory() {
//	delete m_innerFactory;
//}
//
//VRDisplayNode* VRViewportFactory::create(VRDataIndex& config,
//		const std::string nameSpace) {
//
//	VRDisplayNode* display = m_innerFactory->create(config, nameSpace);
//	bool createdScope = false;
//	if (!display)
//	{
//		std::cout << "Created scope" << std::endl;
//		VRStateScopeNode* scope = new VRStateScopeNode();
//		createChildren(scope, m_vrSystem->getDisplayFactory(), config, nameSpace);
//		display = scope;
//		createdScope = true;
//	}
//
//	VRDisplayNode* displayNode = display;
//
//	if (displayNode)
//	{
//		int startChildren = displayNode->getChildren().size();
//		std::vector<VRDisplayNode*> children = displayNode->getChildren();
//		displayNode->clearChildren();
//
//		VRRect viewport;
//		VRViewportNode* viewportNode = NULL;
//		if (viewport.read(config, nameSpace + "/viewport", ""))
//		{
//			std::cout << "Created viewport" << std::endl;
//			viewportNode = new VRViewportNode(viewport);
//			displayNode->addChild(viewportNode);
//			displayNode = viewportNode;
//		}
//
//		VRTile tile;
//		VRTileNode* tileNode = NULL;
//		if (tile.read(config, nameSpace + "/tile", ""))
//		{
//			std::cout << "Created tile" << std::endl;
//			tileNode = new VRTileNode(tile);
//			displayNode->addChild(tileNode);
//			displayNode = tileNode;
//		}
//
//		for (int f = 0; f < children.size(); f++)
//		{
//			displayNode->addChild(children[f]);
//		}
//
//		if (displayNode->getChildren().size() == 0 && createdScope) {
//			std::cout << "destroyed scope" << std::endl;
//			delete display;
//			return NULL;
//		}
//	}
//
//	return display;
//}
//
//} /* namespace MinVR */
