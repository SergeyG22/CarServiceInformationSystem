from conans import ConanFile, CMake

class Libraries(ConanFile):
	name = "Libraries"
	settings = "os","compiler","build_type","arch"
	generators = "cmake","cmake_find_package"
	requires = [("sfml/2.5.1"),("sqlite3/3.38.5")]