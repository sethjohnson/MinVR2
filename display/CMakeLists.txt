# Create a library from the source files in this directory.

project (VRDisplay)

set (${PROJECT_NAME}_source_files 
	VRRenderState.cpp
	base/VRDisplayNode.cpp
	base/VRBasicRenderer.cpp
	base/VRFunctionRenderCallback.cpp
	base/factories/VRCompositeDisplayFactory.cpp
	base/factories/VRTypedDisplayFactory.cpp
	console/VRConsoleDisplay.cpp
	graphics/VRGraphicsWindowChild.cpp
	graphics/VRGraphicsRenderNode.cpp
	graphics/VRGraphicsWindowNode.cpp
	graphics/VRGraphicsWindowFactory.cpp
	graphics/stereo/VRStereoFactory.cpp
	graphics/stereo/VRStereoNode.cpp
	graphics/stereo/VRSideBySideNode.cpp
	graphics/structure/VRViewportNode.cpp
	graphics/structure/VRRect.cpp
	graphics/structure/VRViewportFactory.cpp
	graphics/structure/VRRectCalculator.cpp
	graphics/structure/VRTile.cpp
	graphics/structure/VRTileNode.cpp
)

add_library (${PROJECT_NAME} ${${PROJECT_NAME}_source_files})

install(DIRECTORY ${PROJECT_SOURCE_DIR}  DESTINATION "include" FILES_MATCHING PATTERN "*.h")

install( TARGETS ${PROJECT_NAME}
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
         RUNTIME DESTINATION bin)
