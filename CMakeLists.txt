cmake_minimum_required(VERSION 3.0)

project(Alphabetizer)

include_directories(include)

file(GLOB SOURCES "source/*.cpp")

add_executable(Alphabetizer
	${SOURCES}
	)

set_target_properties(
	Alphabetizer
	PROPERTIES
		OUTPUT_NAME "Alphabetizer"
		SUFFIX ".exe"
)