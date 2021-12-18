##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=QuantLibEx
ConfigurationName      :=Debug
WorkspacePath          :=/home/xrl/Documents/CodeLite/QuantLibEx
ProjectPath            :=/home/xrl/Documents/CodeLite/QuantLibEx
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=xrl
Date                   :=18/12/21
CodeLitePath           :=/home/xrl/.codelite
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="QuantLibEx.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell wx-config --libs) 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)QuantLib 
ArLibs                 :=  "QuantLib" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags)   $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_example.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_utility.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(ObjectSuffix) $(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(ObjectSuffix): qlex/time/daycounters/Actual365_25.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(DependSuffix) -MM qlex/time/daycounters/Actual365_25.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/time/daycounters/Actual365_25.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(PreprocessSuffix): qlex/time/daycounters/Actual365_25.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_time_daycounters_Actual365_25.cpp$(PreprocessSuffix) qlex/time/daycounters/Actual365_25.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(ObjectSuffix): qlex/termstructures/yield/AdjustedSvenssonFitting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(DependSuffix) -MM qlex/termstructures/yield/AdjustedSvenssonFitting.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/AdjustedSvenssonFitting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(PreprocessSuffix): qlex/termstructures/yield/AdjustedSvenssonFitting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_AdjustedSvenssonFitting.cpp$(PreprocessSuffix) qlex/termstructures/yield/AdjustedSvenssonFitting.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(ObjectSuffix): qlex/termstructures/yield/CubicSplinesFitting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(DependSuffix) -MM qlex/termstructures/yield/CubicSplinesFitting.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/CubicSplinesFitting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(PreprocessSuffix): qlex/termstructures/yield/CubicSplinesFitting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_CubicSplinesFitting.cpp$(PreprocessSuffix) qlex/termstructures/yield/CubicSplinesFitting.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(ObjectSuffix): qlex/termstructures/yield/BjorkChristensenFitting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(DependSuffix) -MM qlex/termstructures/yield/BjorkChristensenFitting.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/BjorkChristensenFitting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(PreprocessSuffix): qlex/termstructures/yield/BjorkChristensenFitting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_BjorkChristensenFitting.cpp$(PreprocessSuffix) qlex/termstructures/yield/BjorkChristensenFitting.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(ObjectSuffix): qlex/termstructures/yield/BlissFitting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(DependSuffix) -MM qlex/termstructures/yield/BlissFitting.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/BlissFitting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(PreprocessSuffix): qlex/termstructures/yield/BlissFitting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_BlissFitting.cpp$(PreprocessSuffix) qlex/termstructures/yield/BlissFitting.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(ObjectSuffix): qlex/termstructures/yield/QuadraticSplinesFitting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(DependSuffix) -MM qlex/termstructures/yield/QuadraticSplinesFitting.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/QuadraticSplinesFitting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(PreprocessSuffix): qlex/termstructures/yield/QuadraticSplinesFitting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_QuadraticSplinesFitting.cpp$(PreprocessSuffix) qlex/termstructures/yield/QuadraticSplinesFitting.cpp

$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(ObjectSuffix): qlex/cashflows/ChinaFixingRepoCouponPricer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(DependSuffix) -MM qlex/cashflows/ChinaFixingRepoCouponPricer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/cashflows/ChinaFixingRepoCouponPricer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(PreprocessSuffix): qlex/cashflows/ChinaFixingRepoCouponPricer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCouponPricer.cpp$(PreprocessSuffix) qlex/cashflows/ChinaFixingRepoCouponPricer.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(ObjectSuffix): qlex/termstructures/yield/DieboldLiFitting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(DependSuffix) -MM qlex/termstructures/yield/DieboldLiFitting.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/DieboldLiFitting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(PreprocessSuffix): qlex/termstructures/yield/DieboldLiFitting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_DieboldLiFitting.cpp$(PreprocessSuffix) qlex/termstructures/yield/DieboldLiFitting.cpp

$(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(ObjectSuffix): qlex/instruments/ChinaFixingRepoSwap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(DependSuffix) -MM qlex/instruments/ChinaFixingRepoSwap.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/instruments/ChinaFixingRepoSwap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(PreprocessSuffix): qlex/instruments/ChinaFixingRepoSwap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_instruments_ChinaFixingRepoSwap.cpp$(PreprocessSuffix) qlex/instruments/ChinaFixingRepoSwap.cpp

$(IntermediateDirectory)/test_example.cpp$(ObjectSuffix): test/example.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_example.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_example.cpp$(DependSuffix) -MM test/example.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/test/example.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_example.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_example.cpp$(PreprocessSuffix): test/example.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_example.cpp$(PreprocessSuffix) test/example.cpp

$(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(ObjectSuffix): qlex/indexes/ChinaFixingRepo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(DependSuffix) -MM qlex/indexes/ChinaFixingRepo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/indexes/ChinaFixingRepo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(PreprocessSuffix): qlex/indexes/ChinaFixingRepo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_indexes_ChinaFixingRepo.cpp$(PreprocessSuffix) qlex/indexes/ChinaFixingRepo.cpp

$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix): test/test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_test.cpp$(DependSuffix) -MM test/test.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/test/test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_test.cpp$(PreprocessSuffix): test/test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_test.cpp$(PreprocessSuffix) test/test.cpp

$(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(ObjectSuffix): qlex/instruments/MakeChinaFixingRepoSwap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(DependSuffix) -MM qlex/instruments/MakeChinaFixingRepoSwap.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/instruments/MakeChinaFixingRepoSwap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(PreprocessSuffix): qlex/instruments/MakeChinaFixingRepoSwap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_instruments_MakeChinaFixingRepoSwap.cpp$(PreprocessSuffix) qlex/instruments/MakeChinaFixingRepoSwap.cpp

$(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(ObjectSuffix): qlex/termstructures/yield/ChinaFixingRepoSwapRateHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(DependSuffix) -MM qlex/termstructures/yield/ChinaFixingRepoSwapRateHelper.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/termstructures/yield/ChinaFixingRepoSwapRateHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(PreprocessSuffix): qlex/termstructures/yield/ChinaFixingRepoSwapRateHelper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_termstructures_yield_ChinaFixingRepoSwapRateHelper.cpp$(PreprocessSuffix) qlex/termstructures/yield/ChinaFixingRepoSwapRateHelper.cpp

$(IntermediateDirectory)/test_utility.cpp$(ObjectSuffix): test/utility.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_utility.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_utility.cpp$(DependSuffix) -MM test/utility.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/test/utility.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_utility.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_utility.cpp$(PreprocessSuffix): test/utility.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_utility.cpp$(PreprocessSuffix) test/utility.cpp

$(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(ObjectSuffix): qlex/math/CubicSpline.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(DependSuffix) -MM qlex/math/CubicSpline.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/math/CubicSpline.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(PreprocessSuffix): qlex/math/CubicSpline.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_math_CubicSpline.cpp$(PreprocessSuffix) qlex/math/CubicSpline.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(ObjectSuffix): qlex/cashflows/ChinaFixingRepoCoupon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(DependSuffix) -MM qlex/cashflows/ChinaFixingRepoCoupon.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/cashflows/ChinaFixingRepoCoupon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(PreprocessSuffix): qlex/cashflows/ChinaFixingRepoCoupon.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoCoupon.cpp$(PreprocessSuffix) qlex/cashflows/ChinaFixingRepoCoupon.cpp

$(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(ObjectSuffix): qlex/math/QuadraticSpline.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(DependSuffix) -MM qlex/math/QuadraticSpline.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/math/QuadraticSpline.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(PreprocessSuffix): qlex/math/QuadraticSpline.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_math_QuadraticSpline.cpp$(PreprocessSuffix) qlex/math/QuadraticSpline.cpp

$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(ObjectSuffix): qlex/cashflows/ChinaFixingRepoLeg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(DependSuffix) -MM qlex/cashflows/ChinaFixingRepoLeg.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xrl/Documents/CodeLite/QuantLibEx/qlex/cashflows/ChinaFixingRepoLeg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(PreprocessSuffix): qlex/cashflows/ChinaFixingRepoLeg.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/qlex_cashflows_ChinaFixingRepoLeg.cpp$(PreprocessSuffix) qlex/cashflows/ChinaFixingRepoLeg.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


