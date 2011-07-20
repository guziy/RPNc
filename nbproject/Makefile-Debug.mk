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
CC=pgCC
CCC=pgCC
CXX=pgCC
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1371872258/fftw_f77.o \
	${OBJECTDIR}/rmn_wrapper.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libRPNc.so

dist/Debug/GNU-Linux-x86/libRPNc.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	pgCC -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libRPNc.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1371872258/fftw_f77.o: /home/armnlib/ssm/infrastructure_1.0_linux24-x86-64/share/armnlib/include/fftw_f77.i 
	${MKDIR} -p ${OBJECTDIR}/_ext/1371872258
	${RM} $@.d
	$(COMPILE.c) -g -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1371872258/fftw_f77.o /home/armnlib/ssm/infrastructure_1.0_linux24-x86-64/share/armnlib/include/fftw_f77.i

${OBJECTDIR}/rmn_wrapper.o: rmn_wrapper.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/wrap_std -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/stl -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/wrap_std -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/wrap_std/h -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/using -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/config -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/CC/edg -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/bits -I/usr/local/pgi_serv_904/linux86-64/9.0-4/include/sys -I/home/armnlib/ssm/infrastructure_1.0_linux24-x86-64/share/armnlib/include -I/home/armnlib/ssm/all/include/Linux_x86-64_pgi904 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/rmn_wrapper.o rmn_wrapper.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libRPNc.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
