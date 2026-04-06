###########################################################################
## Makefile generated for component 'wbqp_solve'. 
## 
## Makefile     : wbqp_solve_rtw.mk
## Generated on : Wed Sep 10 16:14:55 2025
## Final product: .\wbqp_solve.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = wbqp_solve
MAKEFILE                  = wbqp_solve_rtw.mk
MATLAB_ROOT               = C:\Users\Italo\Desktop\Matlab\MATLAB~1\R2024a
MATLAB_BIN                = C:\Users\Italo\Desktop\Matlab\MATLAB~1\R2024a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\Italo\Desktop\Documenti\ARS\TesiElia\QP-solver
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ..\..\..
COMPILER_COMMAND_FILE     = wbqp_solve_rtw_comp.rsp
CMD_FILE                  = wbqp_solve_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
MODELLIB                  = wbqp_solve.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2022 v17.0 | nmake (64-bit Windows)
# Supported Version(s):    17.0
# ToolchainInfo Version:   2024a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251 /Zc:__cplusplus
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\wbqp_solve.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=wbqp_solve

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\codegen\lib\wbqp_solve\coder_posix_time.c $(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_data.cpp $(START_DIR)\codegen\lib\wbqp_solve\rt_nonfinite.cpp $(START_DIR)\codegen\lib\wbqp_solve\rtGetNaN.cpp $(START_DIR)\codegen\lib\wbqp_solve\rtGetInf.cpp $(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_initialize.cpp $(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_terminate.cpp $(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve.cpp $(START_DIR)\codegen\lib\wbqp_solve\tic.cpp $(START_DIR)\codegen\lib\wbqp_solve\xnrm2.cpp $(START_DIR)\codegen\lib\wbqp_solve\toc.cpp $(START_DIR)\codegen\lib\wbqp_solve\quadprog.cpp $(START_DIR)\codegen\lib\wbqp_solve\setProblemType.cpp $(START_DIR)\codegen\lib\wbqp_solve\modifyOverheadPhaseOne_.cpp $(START_DIR)\codegen\lib\wbqp_solve\factorQRE.cpp $(START_DIR)\codegen\lib\wbqp_solve\xzlarfg.cpp $(START_DIR)\codegen\lib\wbqp_solve\xzlarf.cpp $(START_DIR)\codegen\lib\wbqp_solve\driver.cpp $(START_DIR)\codegen\lib\wbqp_solve\PresolveWorkingSet.cpp $(START_DIR)\codegen\lib\wbqp_solve\ComputeNumDependentEq_.cpp $(START_DIR)\codegen\lib\wbqp_solve\computeQ_.cpp $(START_DIR)\codegen\lib\wbqp_solve\countsort.cpp $(START_DIR)\codegen\lib\wbqp_solve\removeEqConstr.cpp $(START_DIR)\codegen\lib\wbqp_solve\removeConstr.cpp $(START_DIR)\codegen\lib\wbqp_solve\RemoveDependentIneq_.cpp $(START_DIR)\codegen\lib\wbqp_solve\feasibleX0ForWorkingSet.cpp $(START_DIR)\codegen\lib\wbqp_solve\maxConstraintViolation.cpp $(START_DIR)\codegen\lib\wbqp_solve\computeFval.cpp $(START_DIR)\codegen\lib\wbqp_solve\linearForm_.cpp $(START_DIR)\codegen\lib\wbqp_solve\iterate.cpp $(START_DIR)\codegen\lib\wbqp_solve\computeGrad_StoreHx.cpp $(START_DIR)\codegen\lib\wbqp_solve\xgemv.cpp $(START_DIR)\codegen\lib\wbqp_solve\computeFval_ReuseHx.cpp $(START_DIR)\codegen\lib\wbqp_solve\xrotg.cpp $(START_DIR)\codegen\lib\wbqp_solve\deleteColMoveEnd.cpp $(START_DIR)\codegen\lib\wbqp_solve\compute_deltax.cpp $(START_DIR)\codegen\lib\wbqp_solve\addBoundToActiveSetMatrix_.cpp $(START_DIR)\codegen\lib\wbqp_solve\computeFirstOrderOpt.cpp $(START_DIR)\codegen\lib\wbqp_solve\xzgeqp3.cpp $(START_DIR)\codegen\lib\wbqp_solve\factorQR.cpp $(START_DIR)\codegen\lib\wbqp_solve\feasibleratiotest.cpp $(START_DIR)\codegen\lib\wbqp_solve\ratiotest.cpp $(START_DIR)\codegen\lib\wbqp_solve\fullColLDL2_.cpp $(START_DIR)\codegen\lib\wbqp_solve\CoderTimeAPI.cpp $(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = coder_posix_time.obj wbqp_solve_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj wbqp_solve_initialize.obj wbqp_solve_terminate.obj wbqp_solve.obj tic.obj xnrm2.obj toc.obj quadprog.obj setProblemType.obj modifyOverheadPhaseOne_.obj factorQRE.obj xzlarfg.obj xzlarf.obj driver.obj PresolveWorkingSet.obj ComputeNumDependentEq_.obj computeQ_.obj countsort.obj removeEqConstr.obj removeConstr.obj RemoveDependentIneq_.obj feasibleX0ForWorkingSet.obj maxConstraintViolation.obj computeFval.obj linearForm_.obj iterate.obj computeGrad_StoreHx.obj xgemv.obj computeFval_ReuseHx.obj xrotg.obj deleteColMoveEnd.obj compute_deltax.obj addBoundToActiveSetMatrix_.obj computeFirstOrderOpt.obj xzgeqp3.obj factorQR.obj feasibleratiotest.obj ratiotest.obj fullColLDL2_.obj CoderTimeAPI.obj wbqp_solve_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ = /source-charset:utf-8
CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = /source-charset:utf-8
CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


.cc.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


.cxx.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cc.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cxx.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\wbqp_solve}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\wbqp_solve}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\wbqp_solve}.cc.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\codegen\lib\wbqp_solve}.cxx.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cc.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cxx.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


coder_posix_time.obj : "$(START_DIR)\codegen\lib\wbqp_solve\coder_posix_time.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\coder_posix_time.c"


wbqp_solve_data.obj : "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_data.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_data.cpp"


rt_nonfinite.obj : "$(START_DIR)\codegen\lib\wbqp_solve\rt_nonfinite.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\rt_nonfinite.cpp"


rtGetNaN.obj : "$(START_DIR)\codegen\lib\wbqp_solve\rtGetNaN.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\rtGetNaN.cpp"


rtGetInf.obj : "$(START_DIR)\codegen\lib\wbqp_solve\rtGetInf.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\rtGetInf.cpp"


wbqp_solve_initialize.obj : "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_initialize.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_initialize.cpp"


wbqp_solve_terminate.obj : "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_terminate.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_terminate.cpp"


wbqp_solve.obj : "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve.cpp"


tic.obj : "$(START_DIR)\codegen\lib\wbqp_solve\tic.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\tic.cpp"


xnrm2.obj : "$(START_DIR)\codegen\lib\wbqp_solve\xnrm2.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\xnrm2.cpp"


toc.obj : "$(START_DIR)\codegen\lib\wbqp_solve\toc.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\toc.cpp"


quadprog.obj : "$(START_DIR)\codegen\lib\wbqp_solve\quadprog.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\quadprog.cpp"


setProblemType.obj : "$(START_DIR)\codegen\lib\wbqp_solve\setProblemType.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\setProblemType.cpp"


modifyOverheadPhaseOne_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\modifyOverheadPhaseOne_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\modifyOverheadPhaseOne_.cpp"


factorQRE.obj : "$(START_DIR)\codegen\lib\wbqp_solve\factorQRE.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\factorQRE.cpp"


xzlarfg.obj : "$(START_DIR)\codegen\lib\wbqp_solve\xzlarfg.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\xzlarfg.cpp"


xzlarf.obj : "$(START_DIR)\codegen\lib\wbqp_solve\xzlarf.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\xzlarf.cpp"


driver.obj : "$(START_DIR)\codegen\lib\wbqp_solve\driver.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\driver.cpp"


PresolveWorkingSet.obj : "$(START_DIR)\codegen\lib\wbqp_solve\PresolveWorkingSet.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\PresolveWorkingSet.cpp"


ComputeNumDependentEq_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\ComputeNumDependentEq_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\ComputeNumDependentEq_.cpp"


computeQ_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\computeQ_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\computeQ_.cpp"


countsort.obj : "$(START_DIR)\codegen\lib\wbqp_solve\countsort.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\countsort.cpp"


removeEqConstr.obj : "$(START_DIR)\codegen\lib\wbqp_solve\removeEqConstr.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\removeEqConstr.cpp"


removeConstr.obj : "$(START_DIR)\codegen\lib\wbqp_solve\removeConstr.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\removeConstr.cpp"


RemoveDependentIneq_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\RemoveDependentIneq_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\RemoveDependentIneq_.cpp"


feasibleX0ForWorkingSet.obj : "$(START_DIR)\codegen\lib\wbqp_solve\feasibleX0ForWorkingSet.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\feasibleX0ForWorkingSet.cpp"


maxConstraintViolation.obj : "$(START_DIR)\codegen\lib\wbqp_solve\maxConstraintViolation.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\maxConstraintViolation.cpp"


computeFval.obj : "$(START_DIR)\codegen\lib\wbqp_solve\computeFval.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\computeFval.cpp"


linearForm_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\linearForm_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\linearForm_.cpp"


iterate.obj : "$(START_DIR)\codegen\lib\wbqp_solve\iterate.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\iterate.cpp"


computeGrad_StoreHx.obj : "$(START_DIR)\codegen\lib\wbqp_solve\computeGrad_StoreHx.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\computeGrad_StoreHx.cpp"


xgemv.obj : "$(START_DIR)\codegen\lib\wbqp_solve\xgemv.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\xgemv.cpp"


computeFval_ReuseHx.obj : "$(START_DIR)\codegen\lib\wbqp_solve\computeFval_ReuseHx.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\computeFval_ReuseHx.cpp"


xrotg.obj : "$(START_DIR)\codegen\lib\wbqp_solve\xrotg.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\xrotg.cpp"


deleteColMoveEnd.obj : "$(START_DIR)\codegen\lib\wbqp_solve\deleteColMoveEnd.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\deleteColMoveEnd.cpp"


compute_deltax.obj : "$(START_DIR)\codegen\lib\wbqp_solve\compute_deltax.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\compute_deltax.cpp"


addBoundToActiveSetMatrix_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\addBoundToActiveSetMatrix_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\addBoundToActiveSetMatrix_.cpp"


computeFirstOrderOpt.obj : "$(START_DIR)\codegen\lib\wbqp_solve\computeFirstOrderOpt.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\computeFirstOrderOpt.cpp"


xzgeqp3.obj : "$(START_DIR)\codegen\lib\wbqp_solve\xzgeqp3.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\xzgeqp3.cpp"


factorQR.obj : "$(START_DIR)\codegen\lib\wbqp_solve\factorQR.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\factorQR.cpp"


feasibleratiotest.obj : "$(START_DIR)\codegen\lib\wbqp_solve\feasibleratiotest.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\feasibleratiotest.cpp"


ratiotest.obj : "$(START_DIR)\codegen\lib\wbqp_solve\ratiotest.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\ratiotest.cpp"


fullColLDL2_.obj : "$(START_DIR)\codegen\lib\wbqp_solve\fullColLDL2_.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\fullColLDL2_.cpp"


CoderTimeAPI.obj : "$(START_DIR)\codegen\lib\wbqp_solve\CoderTimeAPI.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\CoderTimeAPI.cpp"


wbqp_solve_rtwutil.obj : "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_rtwutil.cpp"
	$(CPP) $(CPPFLAGS) -Fo"$@" "$(START_DIR)\codegen\lib\wbqp_solve\wbqp_solve_rtwutil.cpp"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


