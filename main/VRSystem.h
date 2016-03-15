/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRSYSTEM_H_
#define VRSYSTEM_H_

#include "display/VRDisplayFactory.h"

namespace MinVR {

class VRSystem {
public:
	virtual ~VRSystem() {}

	virtual VRDisplayFactory& getDisplayFactory() = 0;
};

} /* namespace MinVR */

#endif /* VRSYSTEM_H_ */
