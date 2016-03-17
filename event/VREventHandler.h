/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VREVENTHANDLER_H_
#define VREVENTHANDLER_H_

#include "config/VRDataIndex.h"

namespace MinVR {

class VREventHandler {
public:
	virtual ~VREventHandler() {}

	virtual void handleEvent(const std::string &eventName, VRDataIndex *dataIndex) = 0;
};

class VREventHandlerCallback : public VREventHandler {
public:
	typedef void (*MethodType)(const std::string&, VRDataIndex*);

	VREventHandlerCallback(MethodType handle) : m_handle(handle) {}
	virtual ~VREventHandlerCallback() {}

	void handleEvent(const std::string &eventName, VRDataIndex *dataIndex) {
		(*m_handle)(eventName, dataIndex);
	}

private:
	MethodType m_handle;
};

} /* namespace MinVR */

#endif /* VREVENTHANDLER_H_ */
