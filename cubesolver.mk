##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cubesolver
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/alex/code/c"
ProjectPath            := "/home/alex/code/c/cubesolver"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alex Ozer
Date                   :=07/29/2012
CodeLitePath           :="/home/alex/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="/home/alex/code/c/cubesolver/cubesolver.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
CmpOptions             := -g -O0 -Wall $(Preprocessors)
C_CmpOptions           := -g -O0 -Wall $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
LibPath                := $(LibraryPathSwitch). 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/algs$(ObjectSuffix) $(IntermediateDirectory)/core$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/method$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/algs$(ObjectSuffix): algs.cpp $(IntermediateDirectory)/algs$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/alex/code/c/cubesolver/algs.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/algs$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algs$(DependSuffix): algs.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algs$(ObjectSuffix) -MF$(IntermediateDirectory)/algs$(DependSuffix) -MM "/home/alex/code/c/cubesolver/algs.cpp"

$(IntermediateDirectory)/algs$(PreprocessSuffix): algs.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algs$(PreprocessSuffix) "/home/alex/code/c/cubesolver/algs.cpp"

$(IntermediateDirectory)/core$(ObjectSuffix): core.cpp $(IntermediateDirectory)/core$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/alex/code/c/cubesolver/core.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/core$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core$(DependSuffix): core.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core$(ObjectSuffix) -MF$(IntermediateDirectory)/core$(DependSuffix) -MM "/home/alex/code/c/cubesolver/core.cpp"

$(IntermediateDirectory)/core$(PreprocessSuffix): core.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core$(PreprocessSuffix) "/home/alex/code/c/cubesolver/core.cpp"

$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/alex/code/c/cubesolver/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/alex/code/c/cubesolver/main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/alex/code/c/cubesolver/main.cpp"

$(IntermediateDirectory)/method$(ObjectSuffix): method.cpp $(IntermediateDirectory)/method$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/alex/code/c/cubesolver/method.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/method$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/method$(DependSuffix): method.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/method$(ObjectSuffix) -MF$(IntermediateDirectory)/method$(DependSuffix) -MM "/home/alex/code/c/cubesolver/method.cpp"

$(IntermediateDirectory)/method$(PreprocessSuffix): method.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/method$(PreprocessSuffix) "/home/alex/code/c/cubesolver/method.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/algs$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/algs$(DependSuffix)
	$(RM) $(IntermediateDirectory)/algs$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/method$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/method$(DependSuffix)
	$(RM) $(IntermediateDirectory)/method$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "/home/alex/code/c/.build-debug/cubesolver"


