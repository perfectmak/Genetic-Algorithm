#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/example/SortBooks/Book.o \
	${OBJECTDIR}/example/SortBooks/BookArrangement.o \
	${OBJECTDIR}/example/SortBooks/run.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/GeneticAlgorithm.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/geneticalgorithm

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/geneticalgorithm: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/geneticalgorithm ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/example/SortBooks/Book.o: example/SortBooks/Book.cpp 
	${MKDIR} -p ${OBJECTDIR}/example/SortBooks
	${RM} $@.d
	$(COMPILE.cc) -O2 -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/example/SortBooks/Book.o example/SortBooks/Book.cpp

${OBJECTDIR}/example/SortBooks/BookArrangement.o: example/SortBooks/BookArrangement.cpp 
	${MKDIR} -p ${OBJECTDIR}/example/SortBooks
	${RM} $@.d
	$(COMPILE.cc) -O2 -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/example/SortBooks/BookArrangement.o example/SortBooks/BookArrangement.cpp

${OBJECTDIR}/example/SortBooks/run.o: example/SortBooks/run.cpp 
	${MKDIR} -p ${OBJECTDIR}/example/SortBooks
	${RM} $@.d
	$(COMPILE.cc) -O2 -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/example/SortBooks/run.o example/SortBooks/run.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/GeneticAlgorithm.o: src/GeneticAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -std=c++0x -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GeneticAlgorithm.o src/GeneticAlgorithm.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/geneticalgorithm

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
