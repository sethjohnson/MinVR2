/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/VRGraphicsWindowFactory.h>

namespace MinVR {

VRGraphicsWindowFactory::VRGraphicsWindowFactory(VRSystem* vrSystem) : m_vrSystem(vrSystem) {
	// TODO Auto-generated constructor stub

}

VRGraphicsWindowFactory::~VRGraphicsWindowFactory() {
	// TODO Auto-generated destructor stub
}

VRDisplay* VRGraphicsWindowFactory::create(VRDataIndex& config,
		const std::string nameSpace, std::string type) {
	if (config.exists(nameSpace + "/windowType", ""))
	{
		VRGraphicsWindowNode* display = createWindow(config, nameSpace, config.getValue(nameSpace + "/windowType", ""));
		std::cout << "Test" << std::endl;
		VRDisplayNode::createChildren<VRGraphicsWindowNode, VRGraphicsWindowChild>(display, m_vrSystem->getDisplayFactory(), config, nameSpace);

		return display;
	}

	return NULL;
}

} /* namespace MinVR */
