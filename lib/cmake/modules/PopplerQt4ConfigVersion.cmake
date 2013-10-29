# - Try to find the version of the Qt4 binding of the Poppler library

find_package(PkgConfig)
pkg_search_module(PC_POPPLERQT4 poppler-qt4)

set(PACKAGE_VERSION ${PC_POPPLERQT4_VERSION})

if("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
	set(PACKAGE_VERSION_COMPATIBLE FALSE)
else("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
	set(PACKAGE_VERSION_COMPATIBLE TRUE)
	if("${PACKAGE_FIND_VERSION}" STREQUAL "${PACKAGE_VERSION}")
		set(PACKAGE_VERSION_EXACT TRUE)
	endif("${PACKAGE_FIND_VERSION}" STREQUAL "${PACKAGE_VERSION}")
endif("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
