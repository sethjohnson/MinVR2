/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/base/factories/VRTypedDisplayFactory.h>

namespace MinVR {

VRTypedDisplayFactory::VRTypedDisplayFactory() {
	// TODO Auto-generated constructor stub

}

VRTypedDisplayFactory::~VRTypedDisplayFactory() {
	// TODO Auto-generated destructor stub
}

VRDisplay* VRTypedDisplayFactory::create(VRDataIndex& config,
		const std::string nameSpace) {
	if (config.exists("displayType", nameSpace))
	{
		return create(config, nameSpace, config.getValue("displayType", nameSpace));
	}

	return NULL;
}

} /* namespace MinVR */
