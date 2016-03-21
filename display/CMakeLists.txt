# Create a library from the source files in this directory.

project (VRDisplay)

set (${PROJECT_NAME}_source_files 
	VRCallbackRenderer.cpp
	framework/VRRenderState.cpp
	framework/renderers/VRBasicRenderer.cpp
	base/VRDisplayNode.cpp
	console/VRConsoleDisplay.cpp
	graphics/VRGraphicsWindowChild.cpp
	graphics/VRGraphicsWindowNode.cpp
	graphics/stereo/VRStereoNode.cpp
	graphics/stereo/VRSideBySideNode.cpp
	graphics/structure/VRViewportNode.cpp
	graphics/structure/VRRect.cpp
	graphics/structure/VRRectCalculator.cpp
	graphics/structure/VRTile.cpp
	graphics/structure/VRTileNode.cpp
	factories/VRCompositeDisplayFactory.cpp
	factories/VRTypedDisplayFactory.cpp
	factories/graphics/VRGraphicsWindowFactory.cpp
	factories/graphics/stereo/VRStereoFactory.cpp
	factories/graphics/structure/VRViewportFactory.cpp
)

add_library (${PROJECT_NAME} ${${PROJECT_NAME}_source_files})

install(DIRECTORY ${PROJECT_SOURCE_DIR}  DESTINATION "include" FILES_MATCHING PATTERN "*.h")

install( TARGETS ${PROJECT_NAME}
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
         RUNTIME DESTINATION bin)
