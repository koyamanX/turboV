add_nsl_target(${CMAKE_CURRENT_SOURCE_DIR}/ram64x8K.nsl ${CMAKE_CURRENT_BINARY_DIR}/ram64x8K.v)

add_custom_target(integration
	DEPENDS
		ram64x8K.v
)
