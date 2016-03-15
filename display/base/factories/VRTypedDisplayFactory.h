/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRTYPEDDISPLAYFACTORY_H_
#define VRTYPEDDISPLAYFACTORY_H_

#include "display/VRDisplayFactory.h"

namespace MinVR {

class VRTypedDisplayFactory : public VRDisplayFactory {
public:
	VRTypedDisplayFactory();
	virtual ~VRTypedDisplayFactory();

	VRDisplay* create(VRDataIndex& config, const std::string nameSpace);

protected:
	virtual VRDisplay* create(VRDataIndex& config, const std::string nameSpace, std::string type) = 0;
};

} /* namespace MinVR */

#endif /* VRTYPEDDISPLAYFACTORY_H_ */
