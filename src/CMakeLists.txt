CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# added by mikerb jun 08 2019
#cmake_policy(SET CMP0042 NEW)

PROJECT(IVP)

IF (${WIN32})
  # Define Windows Compiler flags here
  SET(CMAKE_CXX_FLAGS " ")
ELSE (${WIN32})
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
ENDIF (${WIN32})

INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
IF(COMPILER_SUPPORTS_CXX11)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  ADD_DEFINITIONS(-D_USE_UNIQUE_PTR)
ELSEIF(COMPILER_SUPPORTS_CXX0X)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  ADD_DEFINITIONS(-D_USE_UNIQUE_PTR)
ELSE()
  MESSAGE(STATUS "${CMAKE_CXX_COMPILER} has no C++11 support.")
  REMOVE_DEFINITIONS(-D_USE_UNIQUE_PTR)
ENDIF()



#===============================================================================
# FINDING MOOS' HEADERS AND LIBRARIES...
#===============================================================================

# moos - http://www.robots.ox.ac.uk/~mobile/MOOS/wiki/pmwiki.php
# find_package(MOOS 10.0)
# 
# message("+++++++++++++++++++++++++++++++++++++++++")
# message("FIND_PACKAGE CONSIDERED:" ${MOOS_CONSIDERED_CONFIGS})
# message("+++++++++++++++++++++++++++++++++++++++++")
# 
# 
# if(NOT DEFINED MOOS_LIBRARIES)
#   message("Defining MOOS_LIBRARIES")
#   set(MOOS_LIBRARIES MOOS)
# endif()
# 
# include_directories(${MOOS_INCLUDE_DIRS})
# 
# message("+++++++++++++++++++++++++++++++++++++++++")
# message("MOOS_INCLUDE_DIRS:" ${MOOS_INCLUDE_DIRS})
# message("MOOS_LIBRARIES:   " ${MOOS_LIBRARIES})
# message("+++++++++++++++++++++++++++++++++++++++++")
# 
# #===============================================================================
# # FINDING MOOSGeodesy' HEADERS AND LIBRARIES...  
# #===============================================================================
# # moos - http://www.robots.ox.ac.uk/~mobile/MOOS/wiki/pmwiki.php            
# find_package(MOOSGeodesy)
# include_directories(${MOOSGeodesy_INCLUDE_DIRS})
# #link_directories(${MOOSGeodesy_LIBRARY_PATH})
# 
# message("+++++++++++++++++++++++++++++++++++++++++")
# message("MOOSGeodesy_INCLUDE_DIRS:" ${MOOSGeodesy_INCLUDE_DIRS})
# message("MOOSGeodesy_LIBRARY_PATH:" ${MOOSGeodesy_LIBRARY_PATH})
# message("+++++++++++++++++++++++++++++++++++++++++")
# 
#===============================================================================
# BUILDING IvP...
#===============================================================================

#-------------------------------------------------------------------------------
# Let users control whether or not GUI-related libraries/apps are built...
#-------------------------------------------------------------------------------
SET(IVP_BUILD_GUI_CODE ON CACHE BOOL "Build IvP's GUI-related libraries and apps.")
SET(IVP_BUILD_BOT_CODE_ONLY OFF CACHE BOOL "Build IvP's minimal set of bot apps.")

#-------------------------------------------------------------------------------
# Let users control whether or UTM or Local Coords are used
#-------------------------------------------------------------------------------
SET(USE_UTM ON CACHE BOOL "Use UTM coordinates vs Local coordinates.")

message("-------------------------------------------------------Use UTM:" ${USE_UTM})


#---------------------------------------------------------------------
#  Build the Libraries
#---------------------------------------------------------------------

SET(IVP_NON_GUI_LIBS
	#   lib_behaviors
	#   lib_behaviors-marine
	#   lib_behaviors-colregs
	#   lib_bhvutil
	#   lib_genutil
	 lib_geometry
	 #   lib_helmivp
	 #   lib_ivpbuild
	 #   lib_ivpcore
	 #   lib_ivpsolve
	 #   lib_logic
	 #   lib_evalutil
	 #   lib_encounters
	 #   lib_apputil
	 #   lib_realm
	 #   lib_contacts
	 #   lib_obstacles
	 #   lib_ufield
	 #   lib_logutils
	 lib_mbutil
	 #   lib_manifest
  #  ptask4_ScanTheCode
  )


SET(IVP_LIBS_TO_BUILD ${IVP_NON_GUI_LIBS})

IF("${IVP_BUILD_GUI_CODE}" STREQUAL "ON")
   LIST(APPEND IVP_LIBS_TO_BUILD ${IVP_GUI_LIBS})

   message("+++++++++++++++++++++++++++++++++++++++++")
   message("IVP_GUI_CODE will be built......         ")
   message("+++++++++++++++++++++++++++++++++++++++++")

ENDIF("${IVP_BUILD_GUI_CODE}" STREQUAL "ON")

IF("${USE_UTM}" STREQUAL "ON")
   ADD_DEFINITIONS(-DUSE_UTM)
   message("USING UTM")
ENDIF("${USE_UTM}" STREQUAL "ON")


# If the environment hasn't explicitly set 'IVP_LIB_DIRECTORY', give it a good
# default value...

set(IVP_INC_DIRECTORY "/usr/local/include")
set(IVP_LIB_DIRECTORY "/usr/local/lib/")

IF("${IVP_LIB_DIRECTORY}" STREQUAL "")
   # IVP_SOURCE_DIRECTORY is defined by CMake, because this project's name is
   # IVP.
   GET_FILENAME_COMPONENT(IVP_LIB_DIRECTORY "${IVP_SOURCE_DIR}/../../lib" ABSOLUTE)
ENDIF("${IVP_LIB_DIRECTORY}" STREQUAL "")

IF("${IVP_INC_DIRECTORY}" STREQUAL "")
   # IVP_SOURCE_DIRECTORY is defined by CMake, because this project's name is IVP
   GET_FILENAME_COMPONENT(IVP_INC_DIRECTORY "${IVP_SOURCE_DIR}/../../include" ABSOLUTE)
ENDIF("${IVP_INC_DIRECTORY}" STREQUAL "")


message("+++++++++++++++++++++++++++++++++++++++++")
message("IVP_LIB_DIRECTORY:" ${IVP_LIB_DIRECTORY})
message("+++++++++++++++++++++++++++++++++++++++++")


INCLUDE_DIRECTORIES(${IVP_LIBS_TO_BUILD})

FOREACH(L ${IVP_LIBS_TO_BUILD} )
  SET( LIBRARY_OUTPUT_PATH "${IVP_LIB_DIRECTORY}" CACHE PATH "" FORCE ) 
  ADD_SUBDIRECTORY(${L})
ENDFOREACH(L)


#=====================================================================
#  Build the list of Apps to be built
#=====================================================================

#---------------------------------------------------------------------
# Part 1: ROBOT_APPS
#         Minimal set of apps for running on a robot (with slower CPU)
#---------------------------------------------------------------------

#SET(ROBOT_APPS
#  pRealm
#  app_alogbin
#  app_alogtm
#  app_alogeval
#  app_alogload
#  app_aloggrep
#  app_alogscan
#  app_alogcd
#  app_alogpare
#  app_alogeplot
#  app_alogrm
#  app_alogiter
#  app_alogcat
#  app_alogclip
#  app_aloghelm
#  app_nsplug
#  app_pickpos
#  app_manifest_test
#  app_tagrep
#  app_gen_moos_app
#  pEchoVar
#  pMissionEval
#  pEvalLoiter
#  pHelmIvP
#  pMarinePID
#  pBasicContactMgr
#  pContactMgrV20
#  pDeadManPost
#  pNodeReporter
#  pMovingSurvey
#  pObstacleMgr
#  uFldMessageHandler
#  uFldNodeBroker
#  uHelmScope
#  uTimerScript
#  uProcessWatch
#  uMemWatch
#  uLoadWatch
#  uTermCommand
#  uXMS
#  uMAC
#  uPokeDB
#  uQueryDB
#  pHostInfo
#  iSay
#  )
#
##---------------------------------------------------------------------
## pSafetyRetreat is excluded in moos-ivp-aro downloads to check if the 
## source code is present before adding it to the build list.
#
#IF( EXISTS ./pSafetyRetreat )
#  LIST(APPEND ROBOT_APPS pSafetyRetreat
#)  
##ENDIF( EXISTS ./pSafetyRetreat )
#ENDIF()
#
#message(" ROBOT_APPS: ${ROBOT_APPS}")
#
#
#
##---------------------------------------------------------------------
## Part 2 of 3: IVP_NON_GUI_APPS
##              Larger set of apps but still, but still short of GUI apps.
##---------------------------------------------------------------------
#
#SET(IVP_NON_GUI_APPS
#  app_alogsplit
#  app_alogsort
#  app_alogcheck
#  app_alogtest
#  app_gen_obstacles
#  app_bhv2graphviz
#  pXRelay
#  uFldCollisionDetect
#  uFldCollObDetect
#  uFldLoiterAssign
#  uFldPathCheck
#  uFldShoreBroker
#  uFldScope
#  uFldNodeComms
#  uFldBeaconRangeSensor
#  uFldContactRangeSensor
#  uFldObstacleSim
#  uFldGenericSensor
#  uFldWrapDetect
#  pSearchGrid
#  uSimMarine
#  )
#
##---------------------------------------------------------------------
## uSimCurrent is excluded in moos-ivp-aro downloads to check if the 
## source code is present before adding it to the build list.
#IF( EXISTS ./uSimCurrent )
#  LIST(APPEND IVP_NON_GUI_APPS uSimCurrent)  
#ENDIF( EXISTS ./uSimCurrent )
#
#message(" IVP_NON_GUI_APPS: ${IVP_NON_GUI_APPS}")
#
##---------------------------------------------------------------------
## Part 3 of 3: IVP_GUI_APPS
##              Include on the GUI applications
##---------------------------------------------------------------------
#
#SET(IVP_GUI_APPS
#  app_ffview
#  app_geoview
#  app_alogview
##  app_vzaicview
##  app_gzaicview
#  app_zaic_hleq
#  app_zaic_vect
#  app_zaic_hdg
#  app_zaic_spd
#  app_zaic_peak
#  pMarineViewer
#  uFunctionVis
#  uMACView
#  uPlotViewer
#  uCommand
#  )
#
#SET(IVP_APPS_TO_BUILD ${ROBOT_APPS})
#
#message("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
#message(" IVP_BUILD_BOT_CODE_ONLY: ${IVP_BUILD_BOT_CODE_ONLY}")
#message("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
#
#IF("${IVP_BUILD_BOT_CODE_ONLY}" STREQUAL "OFF")
#  LIST(APPEND IVP_APPS_TO_BUILD ${IVP_NON_GUI_APPS})
#ENDIF("${IVP_BUILD_BOT_CODE_ONLY}" STREQUAL "OFF")
#
#
#IF("${IVP_BUILD_GUI_CODE}" STREQUAL "ON")
#   LIST(APPEND IVP_APPS_TO_BUILD ${IVP_GUI_APPS})
#ENDIF("${IVP_BUILD_GUI_CODE}" STREQUAL "ON")
#
#
# If the environment hasn't explicitly set 'IVP_BIN_DIRECTORY', give it a good
# default value...
IF("${IVP_BIN_DIRECTORY}" STREQUAL "")
   # IVP_SOURCE_DIRECTORY is defined by CMake, because this project's name is
   # IVP.
   GET_FILENAME_COMPONENT(IVP_BIN_DIRECTORY "${IVP_SOURCE_DIR}/../../bin" ABSOLUTE)
ENDIF("${IVP_BIN_DIRECTORY}" STREQUAL "")

#FOREACH(A ${IVP_APPS_TO_BUILD})
#  SET( EXECUTABLE_OUTPUT_PATH "${IVP_BIN_DIRECTORY}" CACHE PATH "" FORCE )
#  ADD_SUBDIRECTORY(${A})
#ENDFOREACH(A)

#=============================================================================
# make install (tes 2012-05-08)
#=============================================================================

message("Bin directory: ${IVP_BIN_DIRECTORY}")
message("Include directory: ${IVP_INC_DIRECTORY}")
message("Lib directory: ${IVP_LIB_DIRECTORY}")

#install(DIRECTORY ${IVP_BIN_DIRECTORY}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/bin 
#  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE )
#install(DIRECTORY ${IVP_LIB_DIRECTORY}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
#
#message("Include directory: ${IVP_INC_DIRECTORY}")
#file(GLOB_RECURSE INCLUDE_FILES RELATIVE ${IVP_SOURCE_DIR} lib_*/*.h)
#foreach(I ${INCLUDE_FILES})
#  if(BUILD_LOCAL_FLTK OR (NOT ${I} MATCHES .*lib_fltk.*))
#    get_filename_component(I_NAMEONLY ${I} NAME)
#    configure_file(${IVP_SOURCE_DIR}/${I} ${IVP_INC_DIRECTORY}/ivp/${I_NAMEONLY} COPYONLY)
#  endif()
#endforeach()
#
#install(DIRECTORY ${IVP_INC_DIRECTORY}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include
#  FILES_MATCHING REGEX .*\\.h)
