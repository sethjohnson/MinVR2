/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/VRGraphicsWindowFactory.h>

namespace MinVR {

VRGraphicsWindowFactory::VRGraphicsWindowFactory() {
	// TODO Auto-generated constructor stub

}

VRGraphicsWindowFactory::~VRGraphicsWindowFactory() {
	// TODO Auto-generated destructor stub
}

VRDisplay* VRGraphicsWindowFactory::create(VRDataIndex& config,
		const std::string nameSpace, std::string type) {
	if (config.exists("windowType", nameSpace))
	{
		return createWindow(config, nameSpace, config.getValue("windowType", nameSpace));
	}

	return NULL;
}

} /* namespace MinVR */
