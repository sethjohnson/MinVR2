/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRGRAPHICSWINDOWFACTORY_H_
#define VRGRAPHICSWINDOWFACTORY_H_

#include "display/base/factories/VRTypedDisplayFactory.h"

namespace MinVR {

class VRGraphicsWindowFactory : public VRTypedDisplayFactory {
public:
	VRGraphicsWindowFactory();
	virtual ~VRGraphicsWindowFactory();

protected:
	VRDisplay* create(VRDataIndex& config, const std::string nameSpace, std::string type);
	virtual VRDisplay* createWindow(VRDataIndex& config, const std::string nameSpace, std::string type) = 0;
};

} /* namespace MinVR */

#endif /* VRGRAPHICSWINDOWFACTORY_H_ */
