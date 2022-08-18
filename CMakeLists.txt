cmake_minimum_required(VERSION 3.0)

project(Alphabetizer)

include_directories(include)

file(GLOB SOURCES "source/*.cpp")

add_executable(Alphabetizer.exe
	${SOURCES}
	)
